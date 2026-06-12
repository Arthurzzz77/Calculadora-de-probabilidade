#ifndef DISTRIBUICAO_DISCRETA_HPP
#define DISTRIBUICAO_DISCRETA_HPP
#include "Distribuicao.hpp"
/**
 * @brief Classe base abstrata para distribuicoes de probabilidade discretas
 *
 * Distribuicoes discretas calculam probabilidades em valores inteiros isolados.
 * Esta classe adiciona a interface de probabilidade pontual P(X = k) e acumulada P(X <= k) a hierarquia de Distribuicao, que subclasses como Bernoulli, Binomial e Poisson devem implementar
 */
class DistribuicaoDiscreta : public Distribuicao {
public:
    /**
     * @brief Destrutor virtual para permitir delecao polimorfica
     */
    virtual ~DistribuicaoDiscreta() = default;
    /**
     * @brief Calcula P(X = k)
     * @param k Valor inteiro da variavel aleatoria
     * @return Probabilidade pontual em k
     */
    virtual double probabilidade(int k) const = 0;
    /**
     * @brief Calcula P(X <= k)
     *
     * Implementacao padrao soma probabilidade(i) de 0 ate k;
     * subclasses com forma fechada podem sobrescrever para maior eficiencia
     * @param k Valor de corte
     * @return Probabilidade acumulada ate k
     */
    virtual double acumulada(int k) const;
    /**
     * @brief Calcula P(a <= X <= b)
     *
     * Implementacao padrao soma probabilidade(i) de a ate b
     * @param a Limite inferior do intervalo
     * @param b Limite superior do intervalo
     * @return Probabilidade de X pertencer ao intervalo [a, b]
     * @throws std::invalid_argument se a > b
     */
    virtual double probabilidadeIntervalo(int a, int b) const;
};
#endif
