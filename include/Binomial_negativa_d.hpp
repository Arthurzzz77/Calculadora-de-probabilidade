// include/BinomialNegativa.hpp
#ifndef BINOMIAL_NEGATIVA_HPP
#define BINOMIAL_NEGATIVA_HPP
#include "DistribuicaoDiscreta.hpp"

class BinomialNegativa : public DistribuicaoDiscreta {
public:
    BinomialNegativa(int r, double p);
    double pmf(int k);
    double esperanca();
    double variancia();
    std::string nome();
    int getR();
    double getP();
private:
    int r_;
    double p_;
};

#endif
