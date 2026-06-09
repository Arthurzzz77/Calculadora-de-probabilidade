#include "Binomialnegativa_d.hpp"
#include "Combinatoria.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

BinomialNegativa::BinomialNegativa(int r, double p) : r_(r), p_(p) {
    if (r < 1) {
        throw std::invalid_argument("BinomialNegativa: r (numero de sucessos) deve ser >= 1.");
    }
    if (p <= 0.0 || p > 1.0) {
        throw std::invalid_argument("BinomialNegativa: a probabilidade de sucesso deve estar em (0, 1].");
    }
}
double BinomialNegativa::probabilidade(int k) const {
    // k = numero de tentativas ate o r-esimo sucesso (k >= r).
    if (k < r_) return 0.0;
    double coef = Combinatoria::coeficienteBinomial(k - 1, r_ - 1);
    return coef * std::pow(p_, r_) * std::pow(1.0 - p_, k - r_);
}
double BinomialNegativa::acumulada(int k) const {
    if (k < r_) return 0.0;
    double soma = 0.0;
    for (int i = r_; i <= k; ++i) {
        soma += probabilidade(i);
    }
    if (soma > 1.0) soma = 1.0;
    return soma;
}
double BinomialNegativa::esperanca() const {
    return r_ / p_;
}
double BinomialNegativa::variancia() const {
    return r_ * (1.0 - p_) / (p_ * p_);
}
std::string BinomialNegativa::nome() const {
    return "Binomial Negativa";
}
void BinomialNegativa::exibir() const {
    std::cout << "Distribuicao Binomial Negativa\n"
              << "  r (sucessos) = " << r_ << "\n"
              << "  p (sucesso)  = " << p_ << "\n"
              << "  Esperanca    = " << esperanca() << "\n"
              << "  Variancia    = " << variancia() << "\n"
              << "  Desvio       = " << desvioPadrao() << std::endl;
}
int BinomialNegativa::getR() const {
    return r_;
}
double BinomialNegativa::getP() const {
    return p_;
}
