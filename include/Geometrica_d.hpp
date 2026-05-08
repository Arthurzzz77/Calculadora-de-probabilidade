#ifndef GEOMETRICA_HPP
#define GEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"

class Geometrica : public DistribuicaoDiscreta {
public:
    explicit Geometrica(double p);
    double pmf(int k);
    double cdf(int k);
    double esperanca();
    double variancia();
    std::string nome();
    double getP();
private:
    double p_;
};

#endif
