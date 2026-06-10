#include "Gama_c.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <limits>

namespace{

/**
 * @brief Funcao auxiliar para calculo da acumulada da distribuicao Gama.
 */
double gammaIncompletaRegularizada(double a, double x){
    if (x < 0.0 || a <= 0.0){
        throw std::domain_error("gammaIncompletaRegularizada: argumentos invalidos.");
    }

    if (x == 0.0){
        return 0.0;
    }

    const double EPS = 1e-12;
    const int MAX_ITER = 1000;
    double gln = std::lgamma(a);

    if (x < a + 1.0){
        double ap = a;
        double soma = 1.0 / a;
        double termo = soma;

        for (int n = 0; n < MAX_ITER; n++){
            ap += 1.0;
            termo *= x / ap;
            soma += termo;

            if(std::fabs(termo) < std::fabs(soma) * EPS){
                break;
            }
        }

        return soma * std::exp(-x + a * std::log(x) - gln);
    }

    const double FPMIN = 1e-300;

    double b = x + 1.0 - a;
    double c = 1.0 / FPMIN;
    double d = 1.0 / b;
    double h = d;

    for(int i = 1; i <= MAX_ITER; i++){
        double an = -i * (i - a);

        b += 2.0;

        d = an * d + b;

        if (std::fabs(d) < FPMIN){
            d = FPMIN;
        }

        c = b + an / c;

        if (std::fabs(c) < FPMIN){
            c = FPMIN;
        }

        d = 1.0 / d;

        double delta = d * c;
        h *= delta;

        if(std::fabs(delta - 1.0) < EPS){
            break;
        }
    }

    double q = std::exp(-x + a * std::log(x) - gln) * h;
    return 1.0 - q;
}
}

/**
 * @brief Construtor da distribuicao Gama.
 *
 * @param forma Parametro de forma.
 * @param taxa Parametro de taxa.
 *
 * @throw std::invalid_argument Caso os parametros sejam invalidos.
 */
Gama::Gama(double forma, double taxa) : forma_(forma), taxa_(taxa){
    if (forma <= 0.0){
        throw std::invalid_argument("Gama: o parametro de forma deve ser positivo.");
    }

    if (taxa <= 0.0){
        throw std::invalid_argument("Gama: o parametro de taxa deve ser positivo.");
    }
}

/**
 * @brief Calcula a densidade da distribuicao.
 *
 * @param x Valor de entrada.
 * @return Densidade em x.
 */
double Gama::densidade(double x) const{
    if (x < 0.0){
        return 0.0;
    }

    if (x == 0.0){
        if (forma_ < 1.0){
            return std::numeric_limits<double>::infinity();
        }

        if (forma_ == 1.0){
            return taxa_;
        }
        return 0.0;
    }

    double parte1 = forma_ * std::log(taxa_);
    double parte2 = (forma_ - 1.0) * std::log(x);
    double parte3 = taxa_ * x;
    double parte4 = std::lgamma(forma_);
    double logDensidade = parte1 + parte2 - parte3 - parte4;

    return std::exp(logDensidade);
}

/**
 * @brief Calcula a probabilidade acumulada.
 *
 * @param x Valor de entrada.
 * @return Probabilidade acumulada.
 */
double Gama::acumulada(double x) const{
    if (x <= 0.0){
        return 0.0;
    }

    return gammaIncompletaRegularizada(forma_, taxa_ * x);
}

/**
 * @brief Retorna a esperanca da distribuicao.
 */
double Gama::esperanca() const{
    return forma_ / taxa_;
}

/**
 * @brief Retorna a variancia da distribuicao.
 */
double Gama::variancia() const{
    return forma_ / (taxa_ * taxa_);
}

/**
 * @brief Retorna o nome da distribuicao.
 */
std::string Gama::nome() const{
    return "Gama";
}

/**
 * @brief Exibe as informacoes da distribuicao.
 */
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
