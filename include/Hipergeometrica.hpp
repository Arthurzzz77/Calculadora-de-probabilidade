#ifndef HIPERGEOMETRICA_HPP
#define HIPERGEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"
 
class Hipergeometrica : public DistribuicaoDiscreta {
private:

    int tamPopulacao; 
    int sucessosPopulacao;
    int tamAmostra;
 
public:

    Hipergeometrica(int tamPopulacao, int sucessosPopulacao, int tamAmostra);
    double probabilidade(int k) const;
    double acumulada(double x) const;
    double media() const;
    double variancia() const;
    void exibir() const;
};
#endif
