#ifndef GAMA_HPP
#define GAMA_HPP
#include "DistribuicaoContinua.hpp"
/**
 * @brief Distribuicao Gama
 *
 * Modela o tempo de espera ate a ocorrencia do k-esimo evento num processo de Poisson, generalizando a distribuicao Exponencial
 *
 * f(x) = (taxa^forma / Gamma(forma)) * x^(forma-1) * e^(-taxa*x),  x >= 0
 */
class Gama : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Gama
     * @param forma Parametro de forma alpha (> 0)
     * @param taxa Parametro de taxa beta (> 0)
     * @throws std::invalid_argument se forma ou taxa nao forem positivos
     */
    Gama(double forma, double taxa);
    /**
     * @brief Calcula a densidade f(x)
     * @param x Valor no suporte [0, +inf)
     * @return Valor da funcao densidade; 0 se x < 0
     */
    double densidade(double x) const;
    /**
     * @brief Calcula P(X <= x) via funcao gama incompleta regularizada
     * @param x Valor no suporte [0, +inf)
     * @return Probabilidade acumulada ate x; 0 se x <= 0
     */
    double acumulada(double x) const;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = forma / taxa
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = forma / taxa^2
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Gama"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Retorna o parametro de forma
     * @return Valor de forma_
     */
    double getForma() const;
    /**
     * @brief Retorna o parametro de taxa
     * @return Valor de taxa_
     */
    double getTaxa() const;

private:
    double forma_; ///< Parametro de forma alpha
    double taxa_;  ///< Parametro de taxa beta
};
#endif
