#ifndef DISTRIBUICAO_HPP
#define DISTRIBUICAO_HPP

class Distribuicao {
public:

    virtual ~Distribuicao() {}

    virtual double pdf(double x) const = 0;

    virtual double cdf(double x) const = 0;

    virtual double media() const = 0;

    virtual double variancia() const = 0;

    virtual void exibir() const = 0;
};
#endif
