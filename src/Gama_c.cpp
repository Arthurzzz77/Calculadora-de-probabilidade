#include "Gama_c.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <limits>

namespace {

// Funcao gama incompleta inferior regularizada P(forma, x) = P(X <= x) da Gama
// Dois metodos, cada um rapido na sua regiao:
// serie de potencias quando x e pequeno (x < forma + 1)
// fracao continuada (metodo de Lentz) quando x e grande
double gamaIncompletaRegularizada(double forma, double x) {
    if (x < 0.0 || forma <= 0.0) {
        throw std::domain_error("gamaIncompletaRegularizada: argumentos invalidos.");
    }
    if (x == 0.0) return 0.0;

    const int MAX_ITERACOES = 1000;
    const double PRECISAO = 1e-12;      // para quando a mudanca for menor que isso
    const double QUASE_ZERO = 1e-300;   // evita divisao por zero
    double logGamaForma = std::lgamma(forma);

    if (x < forma + 1.0) {
        // Serie de potencias: soma termos ate eles ficarem despreziveis
        double denominador = forma;
        double soma = 1.0 / forma;
        double termo = soma;
        for (int iter = 0; iter < MAX_ITERACOES; ++iter) {
            denominador += 1.0;
            termo *= x / denominador;   // cada termo e o anterior vezes x/denominador
            soma += termo;
            if (std::fabs(termo) < std::fabs(soma) * PRECISAO) break;
        }
        return soma * std::exp(-x + forma * std::log(x) - logGamaForma);
    } else {
        //Fracao continuada (Lentz): calcula a cauda superior Q = 1 - P
        double denominadorParcial = x + 1.0 - forma;
        double razaoC = 1.0 / QUASE_ZERO;
        double razaoD = 1.0 / denominadorParcial;
        double resultado = razaoD;
        for (int iter = 1; iter <= MAX_ITERACOES; ++iter) {
            double coeficiente = -iter * (iter - forma);
            denominadorParcial += 2.0;
            razaoD = coeficiente * razaoD + denominadorParcial;
            if (std::fabs(razaoD) < QUASE_ZERO) razaoD = QUASE_ZERO;
            razaoC = denominadorParcial + coeficiente / razaoC;
            if (std::fabs(razaoC) < QUASE_ZERO) razaoC = QUASE_ZERO;
            razaoD = 1.0 / razaoD;
            double fatorCorrecao = razaoD * razaoC;
            resultado *= fatorCorrecao;
            // Convergiu: o fator de correcao ficou praticamente 1
            if (std::fabs(fatorCorrecao - 1.0) < PRECISAO) break;
        }
        double caudaSuperior = std::exp(-x + forma * std::log(x) - logGamaForma) * resultado;
        return 1.0 - caudaSuperior;
    }
}

}

Gama::Gama(double forma, double taxa) : forma_(forma), taxa_(taxa) {
    if (forma <= 0.0) {
        throw std::invalid_argument("Gama: o parametro de forma deve ser positivo.");
    }
    if (taxa <= 0.0) {
        throw std::invalid_argument("Gama: o parametro de taxa deve ser positivo.");
    }
}

double Gama::densidade(double x) const {
    // Fora do suporte: tempo negativo nao existe
    if (x < 0.0) {
        return 0.0;
    }

    // Caso especial x = 0: a formula geral faria log(0)
    // O valor correto depende do parametro de forma:
    if (x == 0.0) {
        if (forma_ < 1.0) {
            return std::numeric_limits<double>::infinity(); // curva dispara na borda
        }
        if (forma_ == 1.0) {
            return taxa_;  // caso Exponencial: f(0) = taxa
        }
        return 0.0;        // forma > 1: curva nasce do chao
    }

    // Caso geral: formula calculada em log para evitar overflow
    double logDens = forma_ * std::log(taxa_) + (forma_ - 1.0) * std::log(x)
                     - taxa_ * x - std::lgamma(forma_);
    return std::exp(logDens);
}

double Gama::acumulada(double x) const {
    if (x <= 0.0) return 0.0;
    return gamaIncompletaRegularizada(forma_, taxa_ * x);
}

double Gama::esperanca() const {
    return forma_ / taxa_;
}

double Gama::variancia() const {
    return forma_ / (taxa_ * taxa_);
}

std::string Gama::nome() const {
    return "Gama";
}

void Gama::exibir() const {
    std::cout << "Distribuicao Gama\n"
              << "  forma (k)  = " << forma_ << "\n"
              << "  taxa (beta)= " << taxa_ << "\n"
              << "  Esperanca  = " << esperanca() << "\n"
              << "  Variancia  = " << variancia() << "\n"
              << "  Desvio     = " << desvioPadrao() << std::endl;
}

double Gama::getForma() const {
    return forma_;
}

double Gama::getTaxa() const {
    return taxa_;
}
