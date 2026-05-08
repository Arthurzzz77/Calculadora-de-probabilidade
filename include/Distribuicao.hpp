#ifndef DISTRIBUICAO_HPP
#define DISTRIBUICAO_HPP
#include <string>

class Distribuicao {
public:
    virtual ~Distribuicao() = default;

    virtual double esperanca() const = 0;

    virtual double variancia() const = 0;

    virtual double desvioPadrao() const;

    virtual std::string nome() const = 0;

    virtual void exibir() const = 0;
};
#endif
