#ifndef GEOMETRICA_HPP
#define GEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"

/**
 * @brief Distribuicao Geometrica (numero de tentativas ate o 1o sucesso).
 *
 * Suporte: k = 1, 2, 3, ...   P(X = k) = (1 - p)^(k-1) * p
 */
class Geometrica : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Geometrica.
     * @param p Probabilidade de sucesso em cada tentativa, no intervalo (0, 1].
     * @throws std::invalid_argument se p nao estiver em (0, 1].
     */
    explicit Geometrica(double p);

    double probabilidade(int k) const override;
    double acumulada(int k) const override;
    double esperanca() const override;
    double variancia() const override;
    std::string nome() const override;
    void exibir() const override;

    double getP() const;

private:
    double p_;
};
#endif
