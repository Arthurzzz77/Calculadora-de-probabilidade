#include "Normalc.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

//Construtor da distribuicao Normal.
Normal::Normal(double media, double desvioPadrao) : media_(media), desvioPadrao_(desvioPadrao){
    if (desvioPadrao <= 0.0){
        throw std::invalid_argument("Normal: o desvio padrao deve ser positivo.");
    }
}

//Calcula a densidade da distribuicao.
double Normal::densidade(double x) const{
    static const double PI = 3.14159265358979323846;
    double z = (x - media_) / desvioPadrao_;
    return std::exp(-0.5 * z * z) / (desvioPadrao_ * std::sqrt(2.0 * PI));
}

//Calcula a probabilidade acumulada.
double Normal::acumulada(double x) const{
    double z = (x - media_) / (desvioPadrao_ * std::sqrt(2.0));
    return 0.5 * std::erfc(-z);
}

//Retorna a esperanca da distribuicao.
double Normal::esperanca() const{
    return media_;
}

//Retorna a variancia da distribuicao.
double Normal::variancia() const{
    return desvioPadrao_ * desvioPadrao_;
}

std::string Normal::nome() const{
    return "Normal";
}

void Normal::exibir() const{
    std::cout << "Distribuicao Normal\n"
              << "  Media      = " << media_ << "\n"
              << "  Desvio     = " << desvioPadrao_ << "\n"
              << "  Esperanca  = " << esperanca() << "\n"
              << "  Variancia  = " << variancia() << "\n"
              << "  DesvioPad. = " << desvioPadrao() << std::endl;
}

//Padroniza um valor da distribuicao.
double Normal::padronizar(double x) const{
    return (x - media_) / desvioPadrao_;
}

double Normal::getMedia() const{
    return media_;
}

double Normal::getDesvioPadrao() const{
    return desvioPadrao_;
}
