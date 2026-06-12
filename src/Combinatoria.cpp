#include "Combinatoria.hpp"
#include <stdexcept>
#include <cmath>

long long Combinatoria::fatorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("fatorial: n nao pode ser negativo.");
    }
    if (n > 20) {
        // 21! gera overflow no limite de long long (64 bits)
        throw std::overflow_error("fatorial: valor muito grande, estouro de long long (n > 20).");
    }
    // Multiplica resultado por 2, 3, 4, ..., n
    long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado = resultado * i;
    }
    return resultado;
}

long long Combinatoria::combinacao(int n, int k) {
    if (n < 0 || k < 0) {
        throw std::invalid_argument("combinacao: n e k devem ser nao negativos.");
    }
    if (k > n) {
        return 0;
    }
    // Usa a simetria C(n,k) = C(n, n-k) para reduzir as iteracoes
    if (k > n - k) {
        k = n - k;
    }
    // Calculo multiplicativo, que evita o overflow do fatorial
    long long resultado = 1;
    for (int i = 1; i <= k; ++i) {
        resultado = resultado * (n - k + i) / i;
    }
    return resultado;
}

long long Combinatoria::permutacao(int n, int k) {
    if (n < 0 || k < 0) {
        throw std::invalid_argument("permutacao: n e k devem ser nao negativos.");
    }
    if (k > n) {
        return 0;
    }
    // Multiplica n * (n-1) * (n-2) * ... (k fatores)
    long long resultado = 1;
    for (int i = 0; i < k; ++i) {
        resultado = resultado * (n - i);
    }
    return resultado;
}

double Combinatoria::coeficienteBinomial(int n, int k) {
    if (n < 0 || k < 0) {
        throw std::invalid_argument("coeficienteBinomial: n e k devem ser nao negativos.");
    }
    if (k > n) {
        return 0.0;
    }
    // Versao em ponto flutuante via lgamma (log do fatorial) para suportar valores grandes sem overflow
    double log_coef = std::lgamma(n + 1.0) - std::lgamma(k + 1.0) - std::lgamma(n - k + 1.0);
    return std::round(std::exp(log_coef));
}
