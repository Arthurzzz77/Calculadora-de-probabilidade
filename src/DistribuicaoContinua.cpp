#include "DistribuicaoContinua.hpp"
#include <stdexcept>
// P(a <= X <= b) = F(b) - F(a) para variaveis continuas
double DistribuicaoContinua::probabilidadeIntervalo(double a, double b) const {
    if (a > b) {
        throw std::invalid_argument("probabilidadeIntervalo: limite inferior maior que o superior.");
    }
    return acumulada(b) - acumulada(a);
}
