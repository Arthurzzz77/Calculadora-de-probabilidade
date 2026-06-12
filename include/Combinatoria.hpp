#ifndef COMBINATORIA_HPP
#define COMBINATORIA_HPP
/**
 * @brief Classe utilitaria com operacoes de analise combinatoria
 *
 * Centraliza calculos de fatorial, combinacao e permutacao
 * usados pelas distribuicoes discretas, evitando duplicacao de codigo
 */
class Combinatoria {
public:
    /**
     * @brief Calcula o fatorial de n
     * @param n Inteiro nao negativo (n <= 20)
     * @return n!
     * @throws std::invalid_argument se n < 0
     * @throws std::overflow_error se n > 20
     */
    static long long fatorial(int n);
    /**
     * @brief Calcula o coeficiente binomial C(n, k)
     * @param n Inteiro nao negativo
     * @param k Inteiro nao negativo (k <= n)
     * @return Numero de combinacoes de n elementos tomados k a k; 0 se k > n
     * @throws std::invalid_argument se n < 0 ou k < 0
     */
    static long long combinacao(int n, int k);
    /**
     * @brief Calcula a permutacao P(n, k)
     * @param n Inteiro nao negativo
     * @param k Inteiro nao negativo (k <= n)
     * @return Numero de permutacoes de n elementos tomados k a k; 0 se k > n
     * @throws std::invalid_argument se n < 0 ou k < 0
     */
    static long long permutacao(int n, int k);
    /**
     * @brief Calcula C(n, k) em ponto flutuante via lgamma
     *
     * Indicado para valores grandes que causariam overflow em long long
     * @param n Inteiro nao negativo
     * @param k Inteiro nao negativo (k <= n)
     * @return C(n, k) como double; 0 se k > n
     * @throws std::invalid_argument se n < 0 ou k < 0
     */
    static double coeficienteBinomial(int n, int k);
};
#endif
