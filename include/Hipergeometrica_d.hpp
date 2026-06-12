#ifndef HIPERGEOMETRICA_HPP
#define HIPERGEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao Hipergeometrica
 *
 * Modela o numero de sucessos em n extracoes sem reposicao de uma populacao de tamanho N que contem K sucessos
 *
 * P(X = k) = C(K, k) * C(N-K, n-k) / C(N, n)
 */
class Hipergeometrica : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Hipergeometrica
     * @param N Tamanho da populacao (N >= 0)
     * @param K Numero de sucessos na populacao (0 <= K <= N)
     * @param n Numero de extracoes (0 <= n <= N)
     * @throws std::invalid_argument se os parametros violarem as restricoes
     */
    Hipergeometrica(int N, int K, int n);
    /**
     * @brief Calcula P(X = k)
     * @param k Numero de sucessos na amostra
     * @return Probabilidade de exatamente k sucessos; 0 fora do suporte
     */
    double probabilidade(int k) const override;
    /**
     * @brief Calcula P(X <= k)
     * @param k Valor de corte
     * @return Probabilidade acumulada ate k
     */
    double acumulada(int k) const override;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = n * K / N
     */
    double esperanca() const override;

    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = n * (K/N) * (1 - K/N) * (N - n) / (N - 1)
     */
    double variancia() const override;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Hipergeometrica"
     */
    std::string nome() const override;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const override;
    /**
     * @brief Retorna o tamanho da populacao N
     * @return Valor de N_
     */
    int getN() const;
    /**
     * @brief Retorna o numero de sucessos na populacao K
     * @return Valor de K_
     */
    int getK() const;
    /**
     * @brief Retorna o numero de extracoes n
     * @return Valor de n_
     */
    int getn() const;

private:
    int N_; ///< Tamanho da populacao
    int K_; ///< Numero de sucessos na populacao
    int n_; ///< Numero de extracoes
};
#endif
