#ifndef POISSON_HPP
#define POISSON_HPP
#include "DistribuicaoDiscreta.hpp"
/**
 * @brief Distribuicao de Poisson
 *
 * Modela o numero de ocorrencias de um evento em um intervalo fixo de tempo ou espaco, dado uma taxa media de ocorrencia lambda
 *
 * P(X = k) = (lambda^k * e^(-lambda)) / k!,  k = 0, 1, 2, ...
 */
class Poisson : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao de Poisson
     * @param taxaMedia Taxa media de ocorrencia lambda (> 0)
     * @throws std::invalid_argument se taxaMedia <= 0
     */
    explicit Poisson(double taxaMedia);
    /**
     * @brief Calcula P(X = k)
     * @param k Numero de ocorrencias (k >= 0)
     * @return Probabilidade de exatamente k ocorrencias; 0 se k < 0
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
     * @return E[X] = lambda
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = lambda
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Poisson"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna a taxa media lambda
     * @return Valor de taxaMedia_
     */
    double getTaxaMedia() const;

private:
    double taxaMedia_; ///< Taxa media de ocorrencia lambda
};
#endif
