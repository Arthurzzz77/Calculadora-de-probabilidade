#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <stdexcept>
#include "DistribuicaoDiscreta.hpp"
#include "DistribuicaoContinua.hpp"
#include "Bernoulli_d.hpp"
#include "Binomial_d.hpp"
#include "Geometrica_d.hpp"
#include "Binomialnegativa_d.hpp"
#include "Hipergeometrica_d.hpp"
#include "Poisson_d.hpp"
#include "Normal_c.hpp"
#include "Uniforme_c.hpp"
#include "Exponencial_c.hpp"
#include "Beta_c.hpp"
#include "Gama_c.hpp"
#include "Combinatoria.hpp"

namespace {

// ---------- Visual: linhas e cabecalhos ----------

void linhaGrossa() {
    std::cout << "==================================================\n";
}

void linhaFina() {
    std::cout << "--------------------------------------------------\n";
}

void cabecalho() {
    std::cout << "\n";
    linhaGrossa();
    std::cout << "          CALCULADORA DE PROBABILIDADES\n";
    linhaGrossa();
}

//  defensiva

// Le um numero inteiro; repete ate o usuario digitar algo valido.
int lerInteiro(const std::string& mensagem) {
    int valor;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            return valor;
        }
        if (std::cin.eof()) {
            throw std::runtime_error("Entrada encerrada.");
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [!] Valor invalido. Digite um numero inteiro.\n";
    }
}

// Le um numero real e repete ate o usuario digitar algo valido
double lerReal(const std::string& mensagem) {
    double valor;
    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            return valor;
        }
        if (std::cin.eof()) {
            throw std::runtime_error("Entrada encerrada.");
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [!] Valor invalido. Digite um numero.\n";
    }
}

// ---------- Painel de resultados (usa o polimorfismo da classe base) -------

void painelResultados(const Distribuicao& dist) {
    linhaGrossa();
    std::cout << "RESULTADOS:\n"
              << "  Distribuicao : " << dist.nome() << "\n"
              << "  Esperanca    : " << dist.esperanca() << "\n"
              << "  Variancia    : " << dist.variancia() << "\n"
              << "  Desvio padrao: " << dist.desvioPadrao() << "\n";
}

// ------- Calculo de probabilidades (discretas) ---------

void calcularDiscreta(const DistribuicaoDiscreta& dist) {
    while (true) {
        linhaFina();
        std::cout << "CALCULAR PROBABILIDADES:\n"
                  << "  1 - P(X = k)\n"
                  << "  2 - P(X <= k)\n"
                  << "  3 - P(a <= X <= b)\n"
                  << "  0 - Voltar ao menu\n";
        int opcao = lerInteiro("Escolha: ");
        if (opcao == 0) {
            return;
        }
        if (opcao == 1) {
            int k = lerInteiro("  k = ");
            std::cout << "  P(X = " << k << ") = " << dist.probabilidade(k) << "\n";
        } else if (opcao == 2) {
            int k = lerInteiro("  k = ");
            std::cout << "  P(X <= " << k << ") = " << dist.acumulada(k) << "\n";
        } else if (opcao == 3) {
            int a = lerInteiro("  a = ");
            int b = lerInteiro("  b = ");
            std::cout << "  P(" << a << " <= X <= " << b << ") = "
                      << dist.probabilidadeIntervalo(a, b) << "\n";
        } else {
            std::cout << "  [!] Opcao invalida.\n";
        }
    }
}

// -------- Calculo de probabilidades (continuas) ----------

void calcularContinua(const DistribuicaoContinua& dist) {
    while (true) {
        linhaFina();
        std::cout << "CALCULAR PROBABILIDADES:\n"
                  << "  1 - Densidade f(x)\n"
                  << "  2 - P(X <= x)\n"
                  << "  3 - P(a <= X <= b)\n"
                  << "  0 - Voltar ao menu\n";
        int opcao = lerInteiro("Escolha: ");
        if (opcao == 0) {
            return;
        }
        if (opcao == 1) {
            double x = lerReal("  x = ");
            std::cout << "  f(" << x << ") = " << dist.densidade(x) << "\n";
        } else if (opcao == 2) {
            double x = lerReal("  x = ");
            std::cout << "  P(X <= " << x << ") = " << dist.acumulada(x) << "\n";
        } else if (opcao == 3) {
            double a = lerReal("  a = ");
            double b = lerReal("  b = ");
            std::cout << "  P(" << a << " <= X <= " << b << ") = "
                      << dist.probabilidadeIntervalo(a, b) << "\n";
        } else {
            std::cout << "  [!] Opcao invalida.\n";
        }
    }
}

// ---------- Menu de combinatoria -------

void menuCombinatoria() {
    linhaGrossa();
    std::cout << "COMBINATORIA:\n"
              << "  1 - Fatorial n!\n"
              << "  2 - Combinacao C(n, k)\n"
              << "  3 - Permutacao P(n, k)\n"
              << "  0 - Voltar ao menu\n";
    int opcao = lerInteiro("Escolha: ");
    if (opcao == 0) {
        return;
    }
    linhaGrossa();
    std::cout << "INSIRA OS PARAMETROS:\n";
    if (opcao == 1) {
        int n = lerInteiro("  n = ");
        linhaGrossa();
        std::cout << "RESULTADOS:\n  " << n << "! = " << Combinatoria::fatorial(n) << "\n";
    } else if (opcao == 2) {
        int n = lerInteiro("  n = ");
        int k = lerInteiro("  k = ");
        linhaGrossa();
        std::cout << "RESULTADOS:\n  C(" << n << ", " << k << ") = "
                  << Combinatoria::combinacao(n, k) << "\n";
    } else if (opcao == 3) {
        int n = lerInteiro("  n = ");
        int k = lerInteiro("  k = ");
        linhaGrossa();
        std::cout << "RESULTADOS:\n  P(" << n << ", " << k << ") = "
                  << Combinatoria::permutacao(n, k) << "\n";
    } else {
        std::cout << "  [!] Opcao invalida.\n";
    }
}

// ----- Criacao das distribuicoes (le os parametros de cada uma) ---------

std::unique_ptr<DistribuicaoDiscreta> criarDiscreta(int opcao) {
    linhaGrossa();
    std::cout << "INSIRA OS PARAMETROS:\n";
    switch (opcao) {
        case 1: {
            double p = lerReal("  p (probabilidade de sucesso) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new Bernoulli(p));
        }
        case 2: {
            int n = lerInteiro("  n (numero de tentativas) = ");
            double p = lerReal("  p (probabilidade de sucesso) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new Binomial(n, p));
        }
        case 3: {
            double p = lerReal("  p (probabilidade de sucesso) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new Geometrica(p));
        }
        case 4: {
            int r = lerInteiro("  r (numero de sucessos desejados) = ");
            double p = lerReal("  p (probabilidade de sucesso) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new BinomialNegativa(r, p));
        }
        case 5: {
            int N = lerInteiro("  N (tamanho da populacao) = ");
            int K = lerInteiro("  K (sucessos na populacao) = ");
            int n = lerInteiro("  n (numero de extracoes) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new Hipergeometrica(N, K, n));
        }
        case 6: {
            double lambda = lerReal("  lambda (taxa media) = ");
            return std::unique_ptr<DistribuicaoDiscreta>(new Poisson(lambda));
        }
        default:
            return nullptr;
    }
}

std::unique_ptr<DistribuicaoContinua> criarContinua(int opcao) {
    linhaGrossa();
    std::cout << "INSIRA OS PARAMETROS:\n";
    switch (opcao) {
        case 7: {
            double a = lerReal("  a (limite inferior) = ");
            double b = lerReal("  b (limite superior) = ");
            return std::unique_ptr<DistribuicaoContinua>(new Uniforme(a, b));
        }
        case 8: {
            double lambda = lerReal("  lambda (taxa) = ");
            return std::unique_ptr<DistribuicaoContinua>(new Exponencial(lambda));
        }
        case 9: {
            double media = lerReal("  media = ");
            double desvio = lerReal("  desvio padrao = ");
            return std::unique_ptr<DistribuicaoContinua>(new Normal(media, desvio));
        }
        case 10: {
            double alfa = lerReal("  alfa (forma) = ");
            double beta = lerReal("  beta (taxa) = ");
            return std::unique_ptr<DistribuicaoContinua>(new Gama(alfa, beta));
        }
        case 11: {
            double alfa = lerReal("  alfa = ");
            double beta = lerReal("  beta = ");
            return std::unique_ptr<DistribuicaoContinua>(new Beta(alfa, beta));
        }
        default:
            return nullptr;
    }
}

// ---------- Menu -----------------

void menuPrincipal() {
    cabecalho();
    std::cout << "SELECIONE SUA DISTRIBUICAO:\n"
              << "   1 - Bernoulli          (discreta)\n"
              << "   2 - Binomial           (discreta)\n"
              << "   3 - Geometrica         (discreta)\n"
              << "   4 - Binomial Negativa  (discreta)\n"
              << "   5 - Hipergeometrica    (discreta)\n"
              << "   6 - Poisson            (discreta)\n"
              << "   7 - Uniforme           (continua)\n"
              << "   8 - Exponencial        (continua)\n"
              << "   9 - Normal             (continua)\n"
              << "  10 - Gama               (continua)\n"
              << "  11 - Beta               (continua)\n"
              << "  12 - Combinatoria (fatorial, combinacao, permutacao)\n"
              << "   0 - Sair\n";
    linhaGrossa();
}

} // namespace

int main() {
    try {
        while (true) {
            menuPrincipal();
            int opcao = lerInteiro("Escolha: ");

            if (opcao == 0) {
                std::cout << "Encerrando. Ate logo!\n";
                break;
            }

            // try interno: erro em uma operacao nao derruba o programa
            try {
                if (opcao >= 1 && opcao <= 6) {
                    std::unique_ptr<DistribuicaoDiscreta> dist = criarDiscreta(opcao);
                    painelResultados(*dist);
                    calcularDiscreta(*dist);
                } else if (opcao >= 7 && opcao <= 11) {
                    std::unique_ptr<DistribuicaoContinua> dist = criarContinua(opcao);
                    painelResultados(*dist);
                    calcularContinua(*dist);
                } else if (opcao == 12) {
                    menuCombinatoria();
                } else {
                    std::cout << "  [!] Opcao invalida. Escolha entre 0 e 12.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "  [erro] " << e.what() << "\n";
            }
        }
    } catch (const std::exception& e) {
        //  erro inesperado: sai com aviso
        std::cout << "\n[encerrado] " << e.what() << "\n";
    }
    return 0;
}
