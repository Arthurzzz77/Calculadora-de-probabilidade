#ifndef GAMA_HPP
#define GAMA_HPP
#include "DistribuicaoContinua.hpp"
 
class Gama : public DistribuicaoContinua {
private:
    double forma;
    double taxa;
 
public:
    Gama(double forma, double taxa);
    double densidade(double x) const override;
    double acumulada(double x) const override;
    double media() const override;
    double variancia() const override;
    void exibir() const override;
};
#endif
