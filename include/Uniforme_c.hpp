#ifndef UNIFORME_HPP
#define UNIFORME_HPP
#include "DistribuicaoContinua.hpp"
/**
 * @brief Distribuicao Uniforme continua
 *
 * Modela eventos igualmente provaveis em um intervalo [a, b], onde todo subintervalo de mesmo comprimento tem a mesma probabilidade
 *
 * f(x) = 1 / (b - a),  x in [a, b]
 */
class Uniforme : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Uniforme
     * @param limiteInferior Limite inferior a do intervalo
     * @param limiteSuperior Limite superior b do intervalo
     * @throws std::invalid_argument se limiteInferior >= limiteSuperior
     */
    Uniforme(double limiteInferior, double limiteSuperior);
    /**
     * @brief Calcula a densidade f(x)
     * @param x Ponto de avaliacao
     * @return 1 / (b - a) se x in [a, b]; 0 caso contrario
     */
    double densidade(double x) const;
    /**
     * @brief Calcula P(X <= x)
     * @param x Ponto de avaliacao
     * @return Probabilidade acumulada ate x
     */
    double acumulada(double x) const;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = (a + b) / 2
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = (b - a)^2 / 12
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Uniforme"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna o limite inferior a
     * @return Valor de limiteInferior_
     */
    double getLimiteInferior() const;
    /**
     * @brief Retorna o limite superior b
     * @return Valor de limiteSuperior_
     */
    double getLimiteSuperior() const;

private:
    double limiteInferior_; ///< Limite inferior a do intervalo
    double limiteSuperior_; ///< Limite superior b do intervalo
};
#endif
