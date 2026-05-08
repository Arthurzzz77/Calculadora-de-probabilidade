#ifndef GAMA_HPP
#define GAMA_HPP
#include "DistribuicaoContinua.hpp"
 
class Gama : public DistribuicaoContinua {
private:
    double forma;
    double taxa;
 
public:
    Gama(double forma, double taxa);
    double densidade(double x) const;
    double acumulada(double x) const;
    double media() const;
    double variancia() const;
    void exibir() const;
};
#endif
