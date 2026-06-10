
#include "Exponencial_c.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

Exponencial::Exponencial(double taxa) : taxa_(taxa) {
    if (taxa <= 0.0) {
        throw std::invalid_argument("Exponencial: a taxa (lambda) deve ser positiva.");
    }
}
double Exponencial::densidade(double x) const {
    if (x < 0.0) return 0.0;
    return taxa_ * std::exp(-taxa_ * x);
}
double Exponencial::acumulada(double x) const {
    if (x <= 0.0) return 0.0;
    return 1.0 - std::exp(-taxa_ * x);
}
double Exponencial::esperanca() const {
    return 1.0 / taxa_;
}
double Exponencial::variancia() const {
    return 1.0 / (taxa_ * taxa_);
}
std::string Exponencial::nome() const {
    return "Exponencial";
}
void Exponencial::exibir() const {
    std::cout << "Distribuicao Exponencial\n"
              << "  lambda (taxa) = " << taxa_ << "\n"
              << "  Esperanca     = " << esperanca() << "\n"
              << "  Variancia     = " << variancia() << "\n"
              << "  Desvio        = " << desvioPadrao() << std::endl;
}
double Exponencial::getTaxa() const {
    return taxa_;
}
