#ifndef NORMAL_HPP
#define NORMAL_HPP
#include "DistribuicaoContinua.hpp"
/**
 * @brief Distribuicao Normal (gaussiana)
 *
 * Modela fenomenos naturais simetricos em torno de uma media, sendo a distribuicao continua mais utilizada em estatistica
 *
 * f(x) = (1 / (sigma * sqrt(2*pi))) * e^(-(x-mu)^2 / (2*sigma^2))
 */
class Normal : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Normal
     * @param media Media da distribuicao mu
     * @param desvioPadrao Desvio padrao sigma (> 0)
     * @throws std::invalid_argument se desvioPadrao <= 0
     */
    Normal(double media, double desvioPadrao);
    /**
     * @brief Calcula a densidade f(x)
     * @param x Ponto de avaliacao
     * @return Valor da funcao densidade em x
     */
    double densidade(double x) const;
    /**
     * @brief Calcula P(X <= x) via funcao de erro complementar
     * @param x Ponto de avaliacao
     * @return Probabilidade acumulada ate x
     */
    double acumulada(double x) const;
    /**
     * @brief Retorna a esperanca da distribuicao
     * @return E[X] = mu
     */
    double esperanca() const;
    /**
     * @brief Retorna a variancia da distribuicao
     * @return Var[X] = sigma^2
     */
    double variancia() const;
    /**
     * @brief Retorna o nome da distribuicao
     * @return String "Normal"
     */
    std::string nome() const;
    /**
     * @brief Exibe os parametros e medidas da distribuicao no console
     */
    void exibir() const;
    /**
     * @brief Padroniza um valor x para a escala Z
     * @param x Valor a ser padronizado
     * @return z = (x - mu) / sigma
     */
    double padronizar(double x) const;
    /**
     * @brief Retorna a media da distribuicao
     * @return Valor de media_
     */
    double getMedia() const;
    /**
     * @brief Retorna o desvio padrao da distribuicao
     * @return Valor de desvioPadrao_
     */
    double getDesvioPadrao() const;

private:
    double media_;        ///< Media da distribuicao mu
    double desvioPadrao_; ///< Desvio padrao da distribuicao sigma
};
#endif
