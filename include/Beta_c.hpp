#ifndef BETA_HPP
#define BETA_HPP
#include "DistribuicaoContinua.hpp"
 
class Beta : public DistribuicaoContinua {
public:
    Beta(double alfa, double beta);
 
    double densidade(double x) const;

    double acumulada(double x) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double getAlfa() const;

    double getBeta() const;
 
private:
    double alfa_;
    double beta_;
};
#endif