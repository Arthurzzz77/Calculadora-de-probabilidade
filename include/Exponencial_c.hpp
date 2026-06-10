#ifndef EXPONENCIAL_HPP
#define EXPONENCIAL_HPP
#include "DistribuicaoContinua.hpp"

/**
 * @brief Distribuicao Exponencial (tempo de espera ate o proximo evento).
 *
 * Suporte: x >= 0.   f(x) = lambda * e^(-lambda * x)
 */
class Exponencial : public DistribuicaoContinua {
public:
    /**
     * @brief Constroi uma distribuicao Exponencial.
     * @param taxa Taxa de ocorrencia (lambda), deve ser positiva.
     * @throws std::invalid_argument se taxa <= 0.
     */
    explicit Exponencial(double taxa);

    double densidade(double x) const override;
    double acumulada(double x) const override;
    double esperanca() const override;
    double variancia() const override;
    std::string nome() const override;
    void exibir() const override;

    double getTaxa() const;

private:
    double taxa_;
};
#endif
