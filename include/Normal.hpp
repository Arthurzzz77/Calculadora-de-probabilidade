#ifndef NORMAL_HPP
#define NORMALHPP
 
#include "DistribuicaoContinua.hpp"

class Normal : public DistribuicaoContinua {
private:
    double media;
    double desvioPadrao;
public:
Normal(double media, double desvioPadrao);
  double densidade(double x) const override;
  double acumulada(double x) const override;
  double media() const override;
  double variancia() const override;
  void exibir() const override;
  double padronizar(double x) const;
};
 
#endif
