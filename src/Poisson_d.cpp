#include "Poisson_d.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

Poisson::Poisson(double taxaMedia) : taxaMedia_(taxaMedia) {
    if (taxaMedia <= 0.0) {
        throw std::invalid_argument("Poisson: a taxa media (lambda) deve ser positiva.");
    }
}

double Poisson::probabilidade(int k) const {
    if (k < 0) return 0.0;
    double logP = -taxaMedia_ + k * std::log(taxaMedia_) - std::lgamma(k + 1.0);
    return std::exp(logP);
}
double Poisson::acumulada(int k) const {
    if (k < 0) return 0.0;
    double soma = 0.0;
    for (int i = 0; i <= k; ++i) {
        soma += probabilidade(i);
    }
    if (soma > 1.0) soma = 1.0;
    return soma;
}
double Poisson::esperanca() const {
    return taxaMedia_;
}
double Poisson::variancia() const {
    return taxaMedia_;
}
std::string Poisson::nome() const {
    return "Poisson";
}
void Poisson::exibir() const {
    std::cout << "Distribuicao de Poisson\n"
              << "  lambda (taxa) = " << taxaMedia_ << "\n"
              << "  Esperanca     = " << esperanca() << "\n"
              << "  Variancia     = " << variancia() << "\n"
              << "  Desvio        = " << desvioPadrao() << std::endl;
}
double Poisson::getTaxaMedia() const {
    return taxaMedia_;
}
