#ifndef BINOMIAL_NEGATIVA_HPP
#define BINOMIAL_NEGATIVA_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao Binomial Negativa
 *
 * Modela o numero de tentativas necessarias ate obter o r-esimo sucesso
 *
 * P(X = k) = C(k-1, r-1) * p^r * (1-p)^(k-r),  k = r, r+1, ...
 */
class BinomialNegativa : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Binomial Negativa
     * @param r Numero de sucessos desejados (>= 1)
     * @param p Probabilidade de sucesso em cada tentativa, no intervalo (0, 1]
     * @throws std::invalid_argument se r < 1 ou p nao estiver em (0, 1]
     */
    BinomialNegativa(int r, double p);
    /**
     * @brief Calcula P(X = k)
     * @param k Numero de tentativas (k >= r)
     * @return Probabilidade de obter o r-esimo sucesso na k-esima tentativa; 0 se k < r
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
     * @return E[X] = r / p
     */
    double esperanca() const override;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = r * (1 - p) / p^2
     */
    double variancia() const override;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Binomial Negativa"
     */
    std::string nome() const override;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const override;
    /**
     * @brief Retorna o numero de sucessos desejados r
     * @return Valor de r_
     */
    int getR() const;
    /**
     * @brief Retorna a probabilidade de sucesso p
     * @return Valor de p_
     */
    double getP() const;

private:
    int r_;     ///< Numero de sucessos desejados
    double p_;  ///< Probabilidade de sucesso em cada tentativa
};
#endif
