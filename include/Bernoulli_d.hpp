#ifndef BERNOULLI_HPP
#define BERNOULLI_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao de Bernoulli.
 *
 * Modela um experimento com apenas dois resultados possiveis:
 * sucesso (k = 1) com probabilidade p, e fracasso (k = 0) com probabilidade 1 - p
 *
 * P(X = k) = p^k * (1 - p)^(1-k),  k in {0, 1}
 */
class Bernoulli : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao de Bernoulli
     * @param chanceSucesso Probabilidade de sucesso p, no intervalo [0, 1]
     * @throws std::invalid_argument se chanceSucesso nao estiver em [0, 1]
     */
    explicit Bernoulli(double chanceSucesso);
    /**
     * @brief Calcula P(X = k)
     * @param k Valor da variavel aleatoria (0 ou 1)
     * @return Probabilidade de k; 0 para qualquer outro valor
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
     * @return E[X] = p
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao.
     * @return Var[X] = p * (1 - p).
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Bernoulli"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna a probabilidade de sucesso p
     * @return Valor de chanceSucesso_
     */
    double getChanceSucesso() const;

private:
    double chanceSucesso_; ///< Probabilidade de sucesso p
};
#endif
