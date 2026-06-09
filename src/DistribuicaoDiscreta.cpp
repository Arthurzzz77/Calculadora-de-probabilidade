#include "DistribuicaoDiscreta.hpp"
#include <stdexcept>

// Acumulada: soma das probabilidades de 0 ate k
// Subclasses com forma fechada podem sobrescrever para maior precisao.
double DistribuicaoDiscreta::acumulada(int k) const {
    if (k < 0) {
        return 0.0;
    }
    double soma = 0.0;
    for (int i = 0; i <= k; ++i) {
        soma += probabilidade(i);
    }
    if (soma > 1.0) soma = 1.0;
    return soma;
}
// P(a <= X <= b) para variaveis discretas
double DistribuicaoDiscreta::probabilidadeIntervalo(int a, int b) const {
    if (a > b) {
        throw std::invalid_argument("probabilidadeIntervalo: limite inferior maior que o superior.");
    }
    double soma = 0.0;
    for (int i = a; i <= b; ++i) {
        soma += probabilidade(i);
    }
    return soma;
}
