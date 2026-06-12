#ifndef EXPONENCIAL_HPP
#define EXPONENCIAL_HPP
#include "DistribuicaoContinua.hpp"
/**
 * @brief Distribuicao Exponencial
 *
 * Modela o tempo de espera ate a ocorrencia do proximo evento num processo de Poisson com taxa lambda
 *
 * f(x) = lambda * e^(-lambda * x),  x >= 0
 */
class Exponencial : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Exponencial
     * @param taxa Taxa de ocorrencia lambda (> 0)
     * @throws std::invalid_argument se taxa <= 0
     */
    explicit Exponencial(double taxa);
    /**
     * @brief Calcula a densidade f(x)
     * @param x Valor no suporte [0, +inf)
     * @return Valor da funcao densidade; 0 se x < 0
     */
    double densidade(double x) const override;
    /**
     * @brief Calcula P(X <= x)
     * @param x Valor no suporte [0, +inf)
     * @return Probabilidade acumulada ate x; 0 se x <= 0
     */
    double acumulada(double x) const override;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = 1 / lambda
     */
    double esperanca() const override;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = 1 / lambda^2
     */
    double variancia() const override;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Exponencial"
     */
    std::string nome() const override;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const override;
    /**
     * @brief Retorna a taxa lambda
     * @return Valor de taxa_
     */
    double getTaxa() const;

private:
    double taxa_; ///< Taxa de ocorrencia lambda
};
#endif
