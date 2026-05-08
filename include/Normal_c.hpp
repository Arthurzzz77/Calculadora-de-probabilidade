#ifndef NORMAL_HPP
#define NORMAL_HPP
#include "DistribuicaoContinua.hpp"
 
class Normal : public DistribuicaoContinua {
public:
    Normal(double media, double desvioPadrao);
 
    double densidade(double x) const;

    double acumulada(double x) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double padronizar(double x) const;
 
    double getMedia() const;

    double getDesvioPadrao() const;
 
private:
    double media_;
    double desvioPadrao_;
};
#endif
