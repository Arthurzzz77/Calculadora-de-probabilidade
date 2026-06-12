#ifndef BETA_HPP
#define BETA_HPP
#include "DistribuicaoContinua.hpp"
/**
 * @brief Distribuicao Beta
 *
 * Modela variaveis aleatorias continuas restritas ao intervalo [0, 1], sendo util para representar probabilidades e proporcoes
 *
 * f(x) = x^(alfa-1) * (1-x)^(beta-1) / B(alfa, beta),  x in [0, 1]
 */
class Beta : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Beta
     * @param alfa Parametro de forma alfa (> 0)
     * @param beta Parametro de forma beta (> 0)
     * @throws std::invalid_argument se alfa ou beta nao forem positivos
     */
    Beta(double alfa, double beta);
    /**
     * @brief Calcula a densidade f(x)
     * @param x Valor no suporte [0, 1]
     * @return Valor da funcao densidade; 0 fora do suporte
     */
    double densidade(double x) const;
    /**
     * @brief Calcula P(X <= x) via funcao beta incompleta regularizada
     * @param x Valor no suporte [0, 1]
     * @return Probabilidade acumulada ate x
     */
    double acumulada(double x) const;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = alfa / (alfa + beta)
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = alfa * beta / ((alfa + beta)^2 * (alfa + beta + 1))
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Beta"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna o parametro alfa
     * @return Valor de alfa_
     */
    double getAlfa() const;
    /**
     * @brief Retorna o parametro beta
     * @return Valor de beta_
     */
    double getBeta() const;

private:
    double alfa_; ///< Parametro de forma alfa
    double beta_; ///< Parametro de forma beta
};
#endif
