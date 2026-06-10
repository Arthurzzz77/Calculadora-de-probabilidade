#include "Gama_c.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <limits>

namespace{

//Funcao auxiliar para calculo da acumulada da distribuicao Gama.
double gamaIncompletaRegularizada(double forma, double x){
    if (x < 0.0 || forma <= 0.0){
        throw std::domain_error("gamaIncompletaRegularizada: argumentos invalidos.");
    }

    if (x == 0.0){
        return 0.0;
    }

    const int MAX_ITERACOES = 1000;
    const double PRECISAO = 1e-12;
    const double QUASE_ZERO = 1e-300;
    double logGamaForma = std::lgamma(forma);

    if (x < forma + 1.0){
        double denominador = forma;
        double soma = 1.0 / forma;
        double termo = soma;
        
        for (int iter = 0; iter < MAX_ITERACOES; ++iter){
            denominador += 1.0;
            termo *= x / denominador;
            soma += termo;
            
            if (std::fabs(termo) < std::fabs(soma) * PRECISAO){
                break;
            }
        }
        return soma * std::exp(-x + forma * std::log(x) - logGamaForma);
    }

    double denominadorParcial = x + 1.0 - forma;
    double razaoC = 1.0 / QUASE_ZERO;
    double razaoD = 1.0 / denominadorParcial;
    double resultado = razaoD;

    for (int iter = 1; iter <= MAX_ITERACOES; ++iter){
        double coeficiente = -iter * (iter - forma);
        denominadorParcial += 2.0;
        razaoD = coeficiente * razaoD + denominadorParcial;

        if (std::fabs(razaoD) < QUASE_ZERO){
            razaoD = QUASE_ZERO;
        }
        
        razaoC = denominadorParcial + coeficiente / razaoC;
        if (std::fabs(razaoC) < QUASE_ZERO) {
            razaoC = QUASE_ZERO;
        }
        razaoD = 1.0 / razaoD;
        double fatorCorrecao = razaoD * razaoC;
        resultado *= fatorCorrecao;

        if (std::fabs(fatorCorrecao - 1.0) < PRECISAO){
            break;
        }
    }

    double caudaSuperior = std::exp(-x + forma * std::log(x) - logGamaForma) * resultado;
    return 1.0 - caudaSuperior;
}
}


Gama::Gama(double forma, double taxa) : forma_(forma), taxa_(taxa) {
    if (forma <= 0.0){
        throw std::invalid_argument("Gama: o parametro de forma deve ser positivo.");
    }

    if (taxa <= 0.0){
        throw std::invalid_argument("Gama: o parametro de taxa deve ser positivo.");
    }
}

//Calcula a densidade da distribuicao.
double Gama::densidade(double x) const{
    if (x < 0.0){
        return 0.0;
    }

//Caso especial da densidade em x = 0.
    if (x == 0.0){
        if (forma_ < 1.0){
            return std::numeric_limits<double>::infinity();
        }
        if (forma_ == 1.0){
            return taxa_;
        }
        return 0.0;
    }
    double logDens = forma_ * std::log(taxa_) + (forma_ - 1.0) * std::log(x) - taxa_ * x - std::lgamma(forma_);
    return std::exp(logDens);
}

//Calcula a probabilidade acumulada.
double Gama::acumulada(double x) const{
    if (x <= 0.0){
        return 0.0;
    }
    return gamaIncompletaRegularizada(forma_, taxa_ * x);
}

//Retorna a esperanca da distribuicao.
double Gama::esperanca() const{
    return forma_ / taxa_;
}

//Retorna a variancia da distribuicao.
double Gama::variancia() const{
    return forma_ / (taxa_ * taxa_);
}

std::string Gama::nome() const{
    return "Gama";
}

void Gama::exibir() const{
    std::cout << "Distribuicao Gama\n"
              << "  Forma      = " << forma_ << "\n"
              << "  Taxa       = " << taxa_ << "\n"
              << "  Esperanca  = " << esperanca() << "\n"
              << "  Variancia  = " << variancia() << "\n"
              << "  Desvio     = " << desvioPadrao() << std::endl;
}

double Gama::getForma() const{
    return forma_;
}

double Gama::getTaxa() const{
    return taxa_;
}
