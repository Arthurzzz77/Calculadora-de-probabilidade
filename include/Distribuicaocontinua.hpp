#ifndef DISTRIBUICAO_CONTINUA_HPP
#define DISTRIBUICAO_CONTINUA_HPP
#include "Distribuicao.hpp"

class DistribuicaoContinua : public Distribuicao {
public:
    virtual ~DistribuicaoContinua() = default;

    virtual double densidade(double x) const = 0;

    virtual double acumulada(double x) const = 0;

    virtual double probabilidadeIntervalo(double a, double b) const;
};
#endif
