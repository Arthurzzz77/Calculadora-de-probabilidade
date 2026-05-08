#ifndef BERNOULLI_HPP
#define BERNOULLI_HPP
 
#include "DistribuicaoDiscreta.hpp"

class Bernoulli : public DistribuicaoDiscreta {
private:
    double chanceSucesso; 
public:
Bernoulli(double chanceSucesso);
  double probabilidade(int k) const override;
  double acumulada(double x) const override;
  double media() const override;
  double variancia() const override;
  void exibir() const override;
};
 
#endif
