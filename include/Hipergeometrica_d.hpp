#ifndef GEOMETRICA_HPP
#define GEOMETRICA_HPP
#include "DistribuicaoDiscreta.hpp"
 
class Geometrica : public DistribuicaoDiscreta {
public:
    explicit Geometrica(double chanceSucesso);

    double probabilidade(int k) const;

    double acumulada(int k) const;

    double esperanca() const;

    double variancia() const;

    std::string nome() const;

    void exibir() const;

    double getChanceSucesso() const;
 
private:
    double chanceSucesso_;
};
#endif
