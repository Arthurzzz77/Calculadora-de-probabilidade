#include "Uniforme_c.hpp"
#include <stdexcept>
#include <iostream>

Uniforme::Uniforme(double limiteInferior, double limiteSuperior) : limiteInferior_(limiteInferior), limiteSuperior_(limiteSuperior){
    if (limiteInferior >= limiteSuperior){
        throw std::invalid_argument("Uniforme: o limite inferior deve ser menor que o superior.");
    }
}
//Calcula a densidade da distribuicao
double Uniforme::densidade(double x) const{
    if (x < limiteInferior_ || x > limiteSuperior_){
        return 0.0;
    }
    return 1.0 / (limiteSuperior_ - limiteInferior_);
}
//Calcula a probabilidade acumulada
double Uniforme::acumulada(double x) const{
    if (x < limiteInferior_){
        return 0.0;
    }
    if (x >= limiteSuperior_){
        return 1.0;
    }
    return (x - limiteInferior_) / (limiteSuperior_ - limiteInferior_);
}
//Retorna a esperanca da distribuicao
double Uniforme::esperanca() const{
    return (limiteInferior_ + limiteSuperior_) / 2.0;
}
//Retorna a variancia da distribuicao
double Uniforme::variancia() const{
    double amplitude = limiteSuperior_ - limiteInferior_;
    return (amplitude * amplitude) / 12.0;
}
std::string Uniforme::nome() const{
    return "Uniforme";
}

void Uniforme::exibir() const{
    std::cout << "Distribuicao Uniforme\n"
              << "  Limite inferior = " << limiteInferior_ << "\n"
              << "  Limite superior = " << limiteSuperior_ << "\n"
              << "  Esperanca       = " << esperanca() << "\n"
              << "  Variancia       = " << variancia() << "\n"
              << "  Desvio          = " << desvioPadrao() << std::endl;
}
double Uniforme::getLimiteInferior() const{
    return limiteInferior_;
}
double Uniforme::getLimiteSuperior() const{
    return limiteSuperior_;
}
