#include "Geometrica_d.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

Geometrica::Geometrica(double p) : p_(p) {
    if (p <= 0.0 || p > 1.0) {
        throw std::invalid_argument("Geometrica: a probabilidade de sucesso deve estar em (0, 1].");
    }
}

double Geometrica::probabilidade(int k) const {
    if (k < 1) return 0.0;
    return std::pow(1.0 - p_, k - 1) * p_;
}
double Geometrica::acumulada(int k) const {
    if (k < 1) return 0.0;
    return 1.0 - std::pow(1.0 - p_, k);
}
double Geometrica::esperanca() const {
    return 1.0 / p_;
}
double Geometrica::variancia() const {
    return (1.0 - p_) / (p_ * p_);
}
std::string Geometrica::nome() const {
    return "Geometrica";
}
void Geometrica::exibir() const {
    std::cout << "Distribuicao Geometrica\n"
              << "  p (sucesso) = " << p_ << "\n"
              << "  Esperanca   = " << esperanca() << "\n"
              << "  Variancia   = " << variancia() << "\n"
              << "  Desvio      = " << desvioPadrao() << std::endl;
}
double Geometrica::getP() const {
    return p_;
}
