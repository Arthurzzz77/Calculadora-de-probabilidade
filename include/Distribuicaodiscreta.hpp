#ifndef DISTRIBUICAO_DISCRETA_HPP
#define DISTRIBUICAO_DISCRETA_HPP
#include "Distribuicao.hpp"

class DistribuicaoDiscreta : public Distribuicao {
public:
    virtual ~DistribuicaoDiscreta() {}

    virtual double probabilidade(int k) const = 0;
 
    double densidade(double x) const{
      return probabilidade(static_cast<int>(x));
      }
};
#endif
