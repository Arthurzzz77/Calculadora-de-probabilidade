#include "Distribuicao.hpp"
#include <cmath>

double Distribuicao::desvioPadrao() const {
    return std::sqrt(variancia());
}
