#ifndef HIPERGEOMETRICA_HPP
#define HIPERGEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"

/**
 * @brief Distribuicao Hipergeometrica.
 *
 * Modela o numero de sucessos em n extracoes SEM reposicao de uma populacao
 * de tamanho N que contem K sucessos.
 *
 * P(X = k) = C(K, k) * C(N-K, n-k) / C(N, n)
 */
class Hipergeometrica : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Hipergeometrica.
     * @param N Tamanho da populacao (N >= 0).
     * @param K Numero de sucessos na populacao (0 <= K <= N).
     * @param n Numero de extracoes (0 <= n <= N).
     * @throws std::invalid_argument se os parametros violarem as restricoes.
     */
    Hipergeometrica(int N, int K, int n);

    double probabilidade(int k) const override;
    double acumulada(int k) const override;
    double esperanca() const override;
    double variancia() const override;
    std::string nome() const override;
    void exibir() const override;

    int getN() const;
    int getK() const;
    int getn() const;

private:
    int N_;
    int K_;
    int n_;
};
#endif
