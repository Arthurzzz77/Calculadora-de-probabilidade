#ifndef GAMA_HPP
#define GAMA_HPP
#include "DistribuicaoContinua.hpp"
 
class Gama : public DistribuicaoContinua {
public:
    Gama(double forma, double taxa);
 
    double densidade(double x) const;

    double acumulada(double x) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;
 
    double getForma() const;

    double getTaxa() const;
 
private:
    double forma_;
    double taxa_;
};
#endif
