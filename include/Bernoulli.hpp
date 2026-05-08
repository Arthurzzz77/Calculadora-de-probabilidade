#ifndef BERNOULLI_HPP
#define BERNOULLI_HPP
#include "DistribuicaoDiscreta.hpp"
 
class Bernoulli : public DistribuicaoDiscreta {
public:
    explicit Bernoulli(double chanceSucesso);

    double probabilidade(int k) const;

    double acumulada(int k) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double getChanceSucesso() const;

private:
    double chanceSucesso_;
};
#endif
