#ifndef DISTRIBUICAO_CONTINUA_HPP
#define DISTRIBUICAO_CONTINUA_HPP
#include "Distribuicao.hpp"
/**
 * @brief Classe base abstrata para distribuicoes de probabilidade continuas
 *
 * Distribucoes continuas calculam probabilidades sobre intervalos reais.
 * Esta classe adiciona a interface de densidade f(x) e acumulada F(x) a hierarquia de Distribuicao, que subclasses como Normal, Gama e Beta devem implementar
 */
class DistribuicaoContinua : public Distribuicao {
public:
    /**
     * @brief Destrutor virtual para permitir delecao polimorfica
     */
    virtual ~DistribuicaoContinua() = default;
    /**
     * @brief Calcula a densidade f(x)
     * @param x Ponto de avaliacao
     * @return Valor da funcao densidade em x
     */
    virtual double densidade(double x) const = 0;
    /**
     * @brief Calcula a probabilidade acumulada P(X <= x)
     * @param x Ponto de avaliacao
     * @return Valor da funcao de distribuicao acumulada em x
     */
    virtual double acumulada(double x) const = 0;
    /**
     * @brief Calcula P(a <= X <= b)
     *
     * Implementacao padrao retorna acumulada(b) - acumulada(a)
     * @param a Limite inferior do intervalo
     * @param b Limite superior do intervalo
     * @return Probabilidade de X pertencer ao intervalo [a, b]
     * @throws std::invalid_argument se a > b
     */
    virtual double probabilidadeIntervalo(double a, double b) const;
};
#endif
