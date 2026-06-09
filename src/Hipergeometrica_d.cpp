#include "Hipergeometrica_d.hpp"
#include "Combinatoria.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Hipergeometrica::Hipergeometrica(int N, int K, int n) : N_(N), K_(K), n_(n) {
    if (N < 0) {
        throw std::invalid_argument("Hipergeometrica: N (populacao) nao pode ser negativo.");
    }
    if (K < 0 || K > N) {
        throw std::invalid_argument("Hipergeometrica: K (sucessos) deve estar em [0, N].");
    }
    if (n < 0 || n > N) {
        throw std::invalid_argument("Hipergeometrica: n (extracoes) deve estar em [0, N].");
    }
}
double Hipergeometrica::probabilidade(int k) const {
    // k limitado por: max(0, n-(N-K)) <= k <= min(n, K)
    int kMin = std::max(0, n_ - (N_ - K_));
    int kMax = std::min(n_, K_);
    if (k < kMin || k > kMax) return 0.0;
    double num = Combinatoria::coeficienteBinomial(K_, k) *
                 Combinatoria::coeficienteBinomial(N_ - K_, n_ - k);
    double den = Combinatoria::coeficienteBinomial(N_, n_);
    return num / den;
}
double Hipergeometrica::acumulada(int k) const {
    if (k < 0) return 0.0;
    double soma = 0.0;
    int kMax = std::min(k, std::min(n_, K_));
    for (int i = 0; i <= kMax; ++i) {
        soma += probabilidade(i);
    }
    if (soma > 1.0) soma = 1.0;
    return soma;
}
double Hipergeometrica::esperanca() const {
    return static_cast<double>(n_) * K_ / N_;
}
double Hipergeometrica::variancia() const {
    double p = static_cast<double>(K_) / N_;
    return n_ * p * (1.0 - p) * (static_cast<double>(N_ - n_) / (N_ - 1));
}
std::string Hipergeometrica::nome() const {
    return "Hipergeometrica";
}
void Hipergeometrica::exibir() const {
    std::cout << "Distribuicao Hipergeometrica\n"
              << "  N (populacao) = " << N_ << "\n"
              << "  K (sucessos)  = " << K_ << "\n"
              << "  n (extracoes) = " << n_ << "\n"
              << "  Esperanca     = " << esperanca() << "\n"
              << "  Variancia     = " << variancia() << "\n"
              << "  Desvio        = " << desvioPadrao() << std::endl;
}
int Hipergeometrica::getN() const { return N_; }
int Hipergeometrica::getK() const { return K_; }
int Hipergeometrica::getn() const { return n_; }
