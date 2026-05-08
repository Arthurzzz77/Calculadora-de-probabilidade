#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP
 
#include "DistribuicaoDiscreta.hpp"

class Binomial : public DistribuicaoDiscreta {
private:
    int numTentativas;
    double chanceSucesso;
public:
Binomial(int numTentativas, double chanceSucesso);
  double probabilidade(int k) const override;
  double acumulada(double x) const override;
  double media() const override;
  double variancia() const override;
  void exibir() const override;
};
 
#endif
