#ifndef COMBINATORIA_HPP
#define COMBINATORIA_HPP

class Combinatoria {
public:
    static long long fatorial(int n);

    static long long combinacao(int n, int k);

    static long long permutacao(int n, int k);

    static double coeficienteBinomial(int n, int k);
};
#endif