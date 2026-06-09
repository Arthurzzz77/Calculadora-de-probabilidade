#ifndef DISTRIBUICAO_DISCRETA_HPP
#define DISTRIBUICAO_DISCRETA_HPP
#include "Distribuicao.hpp"
 
class DistribuicaoDiscreta : public Distribuicao {
public:
    virtual ~DistribuicaoDiscreta() = default;

    virtual double probabilidade(int k) const = 0;

    virtual double acumulada(int k) const;

    virtual double probabilidadeIntervalo(int a, int b) const;
};
#endif
