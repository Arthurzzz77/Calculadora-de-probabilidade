#ifndef UNIFORME_HPP
#define UNIFORME_HPP
 
#include "DistribuicaoContinua.hpp"
class Uniforme : public DistribuicaoContinua {
private:
    double limiteInferior;
    double limiteSuperior;
public:
Uniforme(double limiteInferior, double limiteSuperior);
  double densidade(double x) const override;
  double acumulada(double x) const override;
  double media() const override;
  double variancia() const override;
  void exibir() const override;
};
 
#endif
