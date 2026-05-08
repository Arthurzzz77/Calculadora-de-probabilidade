#ifndef UNIFORME_HPP
#define UNIFORME_HPP
#include "DistribuicaoContinua.hpp"
 
class Uniforme : public DistribuicaoContinua {
public:
    Uniforme(double limiteInferior, double limiteSuperior);
 
    double densidade(double x) const;

    double acumulada(double x) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double getLimiteInferior() const;

    double getLimiteSuperior() const;
 
private:
    double limiteInferior_;
    double limiteSuperior_;
};
#endif
