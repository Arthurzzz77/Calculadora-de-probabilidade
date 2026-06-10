#include "Beta_c.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <limits>

namespace {

// Fracao continuada da funcao beta incompleta (algoritmo de Lentz).
// Vai adicionando "andares" na fracao ate o valor estabilizar.
double fracaoContinuadaBeta(double alfa, double beta, double x) {
    const int MAX_ITERACOES = 1000;
    const double PRECISAO = 1e-12;      // para quando a mudanca for menor que isso
    const double QUASE_ZERO = 1e-300;   // evita divisao por zero

    double somaAlfaBeta = alfa + beta;
    double alfaMaisUm = alfa + 1.0;
    double alfaMenosUm = alfa - 1.0;

    // Variaveis do metodo de Lentz: o resultado e construido como um
    // produto de fatores de correcao, um por iteracao.
    double razaoC = 1.0;
    double razaoD = 1.0 - somaAlfaBeta * x / alfaMaisUm;
    if (std::fabs(razaoD) < QUASE_ZERO) razaoD = QUASE_ZERO;
    razaoD = 1.0 / razaoD;
    double resultado = razaoD;

    for (int iter = 1; iter <= MAX_ITERACOES; ++iter) {
        double doisIter = 2.0 * iter;

        // Primeiro coeficiente da iteracao (termo "par" da fracao).
        double coeficiente = iter * (beta - iter) * x /
                             ((alfaMenosUm + doisIter) * (alfa + doisIter));
        razaoD = 1.0 + coeficiente * razaoD;
        if (std::fabs(razaoD) < QUASE_ZERO) razaoD = QUASE_ZERO;
        razaoC = 1.0 + coeficiente / razaoC;
        if (std::fabs(razaoC) < QUASE_ZERO) razaoC = QUASE_ZERO;
        razaoD = 1.0 / razaoD;
        resultado *= razaoD * razaoC;

        // Segundo coeficiente da iteracao (termo "impar" da fracao).
        coeficiente = -(alfa + iter) * (somaAlfaBeta + iter) * x /
                      ((alfa + doisIter) * (alfaMaisUm + doisIter));
        razaoD = 1.0 + coeficiente * razaoD;
        if (std::fabs(razaoD) < QUASE_ZERO) razaoD = QUASE_ZERO;
        razaoC = 1.0 + coeficiente / razaoC;
        if (std::fabs(razaoC) < QUASE_ZERO) razaoC = QUASE_ZERO;
        razaoD = 1.0 / razaoD;

        double fatorCorrecao = razaoD * razaoC;
        resultado *= fatorCorrecao;

        // Convergiu: o fator de correcao ficou praticamente 1.
        if (std::fabs(fatorCorrecao - 1.0) < PRECISAO) break;
    }
    return resultado;
}

// Funcao beta incompleta regularizada I_x(alfa, beta) = P(X <= x) da Beta.
double betaIncompletaRegularizada(double alfa, double beta, double x) {
    if (x < 0.0 || x > 1.0) {
        throw std::domain_error("betaIncompletaRegularizada: x deve estar em [0, 1].");
    }
    if (x == 0.0) return 0.0;
    if (x == 1.0) return 1.0;

    // Fator de escala da fracao continuada, calculado em log para evitar estouro.
    double logFatorEscala = std::lgamma(alfa + beta) - std::lgamma(alfa) - std::lgamma(beta)
                            + alfa * std::log(x) + beta * std::log(1.0 - x);
    double fatorEscala = std::exp(logFatorEscala);

    // A fracao continuada converge rapido so quando x e "pequeno".
    // Para x grande, usa a simetria I_x(a,b) = 1 - I_(1-x)(b,a).
    double limiteConvergencia = (alfa + 1.0) / (alfa + beta + 2.0);
    if (x < limiteConvergencia) {
        return fatorEscala * fracaoContinuadaBeta(alfa, beta, x) / alfa;
    } else {
        return 1.0 - fatorEscala * fracaoContinuadaBeta(beta, alfa, 1.0 - x) / beta;

    }
}

} 
Beta::Beta(double alfa, double beta) : alfa_(alfa), beta_(beta) {
    if (alfa <= 0.0) {
        throw std::invalid_argument("Beta: o parametro alfa deve ser positivo.");
    }
    if (beta <= 0.0) {
        throw std::invalid_argument("Beta: o parametro beta deve ser positivo.");
    }
}
double Beta::densidade(double x) const {
    if (x < 0.0 || x > 1.0) return 0.0;
    if (x == 0.0 || x == 1.0) {
        // Evita log(0),pois a densidade pode divergir nas bordas conforme os parametros.
        if ((x == 0.0 && alfa_ < 1.0) || (x == 1.0 && beta_ < 1.0)) {
            return std::numeric_limits<double>::infinity();
        }
        if ((x == 0.0 && alfa_ > 1.0) || (x == 1.0 && beta_ > 1.0)) {
            return 0.0;
        }
    }
    double logBeta = std::lgamma(alfa_) + std::lgamma(beta_) - std::lgamma(alfa_ + beta_);
    double logDens = (alfa_ - 1.0) * std::log(x) + (beta_ - 1.0) * std::log(1.0 - x) - logBeta;
    return std::exp(logDens);
}
double Beta::acumulada(double x) const {
    if (x <= 0.0) return 0.0;
    if (x >= 1.0) return 1.0;
    return betaIncompletaRegularizada(alfa_, beta_, x);
}

double Beta::esperanca() const {
    return alfa_ / (alfa_ + beta_);
}
double Beta::variancia() const {
    double s = alfa_ + beta_;
    return (alfa_ * beta_) / (s * s * (s + 1.0));
}
std::string Beta::nome() const {
    return "Beta";
}
void Beta::exibir() const {
    std::cout << "Distribuicao Beta\n"
              << "  alfa      = " << alfa_ << "\n"
              << "  beta      = " << beta_ << "\n"
              << "  Esperanca = " << esperanca() << "\n"
              << "  Variancia = " << variancia() << std::endl;
}
double Beta::getAlfa() const {
    return alfa_;
}
double Beta::getBeta() const {
    return beta_;
}
