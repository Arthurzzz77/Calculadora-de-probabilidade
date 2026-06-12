#ifndef DISTRIBUICAO_HPP
#define DISTRIBUICAO_HPP
#include <string>
/**
 * @brief Classe base abstrata para todas as distribuicoes de probabilidade
 *
 * Define a interface comum a todas as distribuicoes, garantindo que esperanca, variancia, desvio padrao e nome estejam disponiveis via polimorfismo
 */
class Distribuicao {
public:
    /**
     * @brief Destrutor virtual para permitir delecao polimorfica
     */
    virtual ~Distribuicao() = default;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X]
     */
    virtual double esperanca() const = 0;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X]
     */
    virtual double variancia() const = 0;
    /**
     * @brief Retorna o desvio padrao da distribuicao
     *
     * Implementacao padrao retorna sqrt(variancia()), podendo ser sobrescrita por subclasses
     * @return sqrt(Var[X])
     */
    virtual double desvioPadrao() const;

    /**
     * @brief Retorna o nome da distribuicao
     * @return String com o nome da distribuicao
     */
    virtual std::string nome() const = 0;

    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    virtual void exibir() const = 0;
};
#endif
