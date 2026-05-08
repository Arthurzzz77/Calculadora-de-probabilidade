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
    double probabilidade(int k) const override;
    double acumulada(double x) const override;
    double media() const override;
    double variancia() const override;
    void exibir() const override;
};
#endif
