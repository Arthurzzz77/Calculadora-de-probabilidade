#ifndef POISSON_HPP
#define POISSON_HPP
#include "DistribuicaoDiscreta.hpp"
 
class Poisson : public DistribuicaoDiscreta {
public:
    explicit Poisson(double taxaMedia);
 
    double probabilidade(int k) const;

    double acumulada(int k) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double getTaxaMedia() const;
 
private:
    double taxaMedia_;
};
#endif
