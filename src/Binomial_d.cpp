#include "Binomial_d.hpp"
#include "Combinatoria.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

Binomial::Binomial(int numTentativas, double chanceSucesso)
    : numTentativas_(numTentativas), chanceSucesso_(chanceSucesso) {
    if (numTentativas < 0) {
        throw std::invalid_argument("Binomial: o numero de tentativas nao pode ser negativo.");
    }
    if (chanceSucesso < 0.0 || chanceSucesso > 1.0) {
        throw std::invalid_argument("Binomial: a probabilidade de sucesso deve estar em [0, 1].");
    }
}

double Binomial::probabilidade(int k) const {
    if (k < 0 || k > numTentativas_) return 0.0;
    double coef = Combinatoria::coeficienteBinomial(numTentativas_, k);
    return coef * std::pow(chanceSucesso_, k) * std::pow(1.0 - chanceSucesso_, numTentativas_ - k);
}

double Binomial::acumulada(int k) const {
    if (k < 0) return 0.0;
    if (k >= numTentativas_) return 1.0;
    double soma = 0.0;
    for (int i = 0; i <= k; ++i) {
        soma += probabilidade(i);
    }
    return soma;
}
double Binomial::esperanca() const {
    return numTentativas_ * chanceSucesso_;
}
double Binomial::variancia() const {
    return numTentativas_ * chanceSucesso_ * (1.0 - chanceSucesso_);
}
std::string Binomial::nome() const {
    return "Binomial";
}
void Binomial::exibir() const {
    std::cout << "Distribuicao Binomial\n"
              << "  n (tentativas) = " << numTentativas_ << "\n"
              << "  p (sucesso)    = " << chanceSucesso_ << "\n"
              << "  Esperanca      = " << esperanca() << "\n"
              << "  Variancia      = " << variancia() << "\n"
              << "  Desvio         = " << desvioPadrao() << std::endl;
}

int Binomial::getNumTentativas() const {
    return numTentativas_;
}
double Binomial::getChanceSucesso() const {
    return chanceSucesso_;
}
