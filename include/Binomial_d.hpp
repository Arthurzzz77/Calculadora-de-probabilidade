#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP
#include "DistribuicaoDiscreta.hpp"
 
class Binomial : public DistribuicaoDiscreta {
public:
    Binomial(int numTentativas, double chanceSucesso);

    double probabilidade(int k) const;

    double acumulada(int k) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    int getNumTentativas() const;

    double getChanceSucesso() const;

private:
    int numTentativas_; 
    double chanceSucesso_;
};
#endif
