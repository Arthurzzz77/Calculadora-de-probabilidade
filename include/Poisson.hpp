#ifndef POISSON_HPP
#define POISSON_HPP
 
#include "DistribuicaoDiscreta.hpp"

class Poisson : public DistribuicaoDiscreta {
private:
    double taxaMedia;
public:
Poisson(double taxaMedia);
  double probabilidade(int k) const override;
  double acumulada(double x) const override;
  double media() const override;
  double variancia() const override;
  void exibir() const override;
};
 
#endif
