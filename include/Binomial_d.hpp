#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao Binomial
 *
 * Modela o numero de sucessos em n tentativas independentes, cada uma com probabilidade de sucesso p
 *
 * P(X = k) = C(n, k) * p^k * (1-p)^(n-k),  k in {0, 1, ..., n}
 */
class Binomial : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Binomial
     * @param numTentativas Numero de tentativas n (>= 0)
     * @param chanceSucesso Probabilidade de sucesso p, no intervalo [0, 1]
     * @throws std::invalid_argument se numTentativas < 0 ou chanceSucesso fora de [0, 1]
     */
    Binomial(int numTentativas, double chanceSucesso);
    /**
     * @brief Calcula P(X = k)
     * @param k Numero de sucessos desejados (0 <= k <= n)
     * @return Probabilidade de exatamente k sucessos; 0 fora do suporte
     */
    double probabilidade(int k) const;
    /**
     * @brief Calcula P(X <= k)
     * @param k Valor de corte
     * @return Probabilidade acumulada ate k
     */
    double acumulada(int k) const;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = n * p
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = n * p * (1 - p)
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Binomial"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna o numero de tentativas n
     * @return Valor de numTentativas_
     */
    int getNumTentativas() const;
    /**
     * @brief Retorna a probabilidade de sucesso p
     * @return Valor de chanceSucesso_
     */
    double getChanceSucesso() const;

private:
    int numTentativas_;       ///< Numero de tentativas n
    double chanceSucesso_;    ///< Probabilidade de sucesso p
};
#endif
