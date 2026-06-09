#include "Bernoulli_d.hpp"
#include <stdexcept>
#include <iostream>

Bernoulli::Bernoulli(double chanceSucesso) : chanceSucesso_(chanceSucesso) {
    if (chanceSucesso < 0.0 || chanceSucesso > 1.0) {
        throw std::invalid_argument("Bernoulli: a probabilidade de sucesso deve estar em [0, 1].");
  }
}

double Bernoulli::probabilidade(int k) const {
    if (k == 1) return chanceSucesso_;
    if (k == 0) return 1.0 - chanceSucesso_;
    return 0.0;
}
double Bernoulli::acumulada(int k) const {
    if (k < 0) return 0.0;
    if (k == 0) return 1.0 - chanceSucesso_;
    return 1.0;
}
double Bernoulli::esperanca() const {
    return chanceSucesso_;
}
double Bernoulli::variancia() const {
    return chanceSucesso_ * (1.0 - chanceSucesso_);
}
std::string Bernoulli::nome() const {
    return "Bernoulli";
}
void Bernoulli::exibir() const {
    std::cout << "Distribuicao de Bernoulli\n"
              << "  p (sucesso) = " << chanceSucesso_ << "\n"
              << "  Esperanca   = " << esperanca() << "\n"
              << "  Variancia   = " << variancia() << "\n"
              << "  Desvio      = " << desvioPadrao() << std::endl;
}
double Bernoulli::getChanceSucesso() const {
    return chanceSucesso_;
}
