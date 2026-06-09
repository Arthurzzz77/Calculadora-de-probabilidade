#ifndef BINOMIAL_NEGATIVA_HPP
#define BINOMIAL_NEGATIVA_HPP
#include "DistribuicaoDiscreta.hpp"

/**
 * @brief Distribuicao Binomial Negativa (numero de tentativas ate o r-esimo sucesso).
 *
 * Suporte: k = r, r+1, ...   P(X = k) = C(k-1, r-1) * p^r * (1-p)^(k-r)
 */
class BinomialNegativa : public DistribuicaoDiscreta {
public:
    /**
     * @brief Constroi uma distribuicao Binomial Negativa.
     * @param r Numero de sucessos desejados (inteiro >= 1).
     * @param p Probabilidade de sucesso em cada tentativa, no intervalo (0, 1].
     * @throws std::invalid_argument se r < 1 ou p nao estiver em (0, 1].
     */
    BinomialNegativa(int r, double p);

    double probabilidade(int k) const override;
    double acumulada(int k) const override;
    double esperanca() const override;
    double variancia() const override;
    std::string nome() const override;
    void exibir() const override;

    int getR() const;
    double getP() const;

private:
    int r_;
    double p_;
};
#endif
