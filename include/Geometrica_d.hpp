#ifndef GEOMETRICA_HPP
#define GEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao Geometrica
 *
 * Modela o numero de tentativas necessarias ate obter o primeiro sucesso em experimentos independentes com probabilidade de sucesso p
 *
 * P(X = k) = (1 - p)^(k-1) * p,  k = 1, 2, 3, ...
 */
class Geometrica : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Geometrica
     * @param p Probabilidade de sucesso em cada tentativa, no intervalo (0, 1]
     * @throws std::invalid_argument se p nao estiver em (0, 1]
     */
    explicit Geometrica(double p);
    /**
     * @brief Calcula P(X = k)
     * @param k Numero de tentativas (k >= 1)
     * @return Probabilidade do primeiro sucesso ocorrer na k-esima tentativa; 0 se k < 1
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
     * @return E[X] = 1 / p
     */
    double esperanca() const override;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = (1 - p) / p^2
     */
    double variancia() const override;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Geometrica"
     */
    std::string nome() const override;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const override;
    /**
     * @brief Retorna a probabilidade de sucesso p
     * @return Valor de p_
     */
    double getP() const;

private:
    double p_; ///< Probabilidade de sucesso em cada tentativa
};
#endif
