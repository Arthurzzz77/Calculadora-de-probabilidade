# Calculadora de Probabilidade
## Alunos: Arthur Felipe de Freitas Morais | Matricula: 2025075132; Guilherme Gonçalves Veras | Matrícula: 2025075230; Gabriel Andrade de Oliveira | Matrícula: 2025020699; João Pedro Kakehasi Saturnino | Matrícula: 2025123099; Isaque Emanuel Craveiro de Araujo | Matrícula: 2025113530.
Este projeto consiste em uma calculadora de probabilidade que será desenvolvida como o trabalho prático de PDS 2 (Programação e Desenvolvimento de Software 2). Utilizando conceitos aprofundados paralelamente na disciplina de Probabilidade, esta ferramenta permite calcular distribuições de probabilidade com base em diferentes tipos de distribuições estatísticas, como de Bernoulli, Binomial, de Poisson, entre outras. 

O objetivo desse projeto é aplicar os aprendizados de PDS 2 na construção de um programa funcional que, através dos parâmetros utilizados em distribuições probabilísticas, facilite o cálculo de probabilidades e auxilie no entendimento dos seus conceitos.

07/05: Os cartões CRC e User Stories estão no docs!


## Divisão do trabalho 

A divisão do trabalho foi feita a partir de uma média ponderada do número de distribuições/auxiliares, cujo peso era a dificuldade de implementar cada uma. Entretanto, no meio do processo, houve colaboração mútua em uma mesma parte do trabalho.

A distribuição final ficou da seguinte forma:

João Pedro Saturnino:
Bernoulli_d.cpp
Binomial_d.cpp
Poisson_d.cpp
Geometrica_d.hpp + Geometrica_d.cpp
Binomialnegativa_d.hpp + Binomialnegativa_d.cpp
Hipergeometrica_d.cpp

Guilherme Veras:
Combinatoria.cpp
Distribuicao.cpp
DistribuicaoDiscreta.cpp
DistribuicaoContinua.cpp
Bernoulli_d.hpp
Binomial_d.hpp
Poisson_d.hpp
Hipergeometrica_d.hpp

Isaque Craveiro:
Combinatoria.hpp
main.cpp

Arthur Felipe:
Distribuicao.hpp
DistribuicaoDiscreta.hpp
DistribuicaoContinua.hpp
Uniforme_c.hpp + Uniforme_c.cpp
Gama_c.cpp

Gabriel Andrade:
Beta_c.hpp + Beta_c.cpp
Gama_c.hpp
Exponencial_c.hpp + Exponencial_c.cpp

## Como Compilar e Executar
1. Clone o repositório
git clone https://github.com/Arthurzzz77/Calculadora-de-probabilidade.git
cd Calculadora-de-probabilidade

2. Compile
make

3. Execute
make run

make compila todos os arquivos .cpp de src/ de uma vez.
make run compila (se necessário) e executa o programa.


## Vídeo de Demonstração

link:

O vídeo demonstra a compilação, execução e operação do sistema.

## Arquitetura e Organização

Calculadora-de-probabilidade/

├── src/         Implementações (.cpp)

├── include/     Interfaces e declarações (.hpp)

├── build/       Binários e objetos compilados

├── docs/        Documentação (Doxygen, cartões CRC, User Stories)

├── tests/       Testes

├── Makefile     Script de compilação

└── README.md

## Hierarquia de classes


Distribuicao — classe base abstrata para todas as distribuições
DistribuicaoDiscreta — base para distribuições discretas
Bernoulli, Binomial, Geometrica, BinomialNegativa, Hipergeometrica, Poisson

DistribuicaoContinua — base para distribuições contínuas
Uniforme, Exponencial, Normal, Gama, Beta

Combinatoria — classe utilitária para fatorial, combinação e permutação

## Funcionalidades entregues

P(X = k), P(X ≤ k), Esperança, Variância e Desvio Padrão - para todas as 11 distribuições

## Instruções de Uso com Exemplos

Ao executar make run, o menu principal é exibido:


   CALCULADORA DE PROBABILIDADES

SELECIONE SUA DISTRIBUICAO:
  
   1 - Bernoulli          (discreta)
   
   2 - Binomial           (discreta)
   
   ...
   
   0 - Sair

Escolha:

## Exemplo  — Distribuição Binomial
Escolha: 2
n (número de tentativas): 10
p (probabilidade de sucesso): 0.3
k (valor): 3

P(X = 3) = 0.2668
P(X ≤ 3) = 0.6496
E[X] = 3.0000
Var[X] = 2.1000

obs: Parâmetros decimais devem ser inseridos com ponto (ex: 1.5, não 1,5).

## Tratamento de Exceções e Programação Defensiva

O sistema valida os parâmetros de entrada em todos os construtores das distribuições, lançando std::invalid_argument com mensagem descritiva quando um valor inválido é fornecido. Exemplos:

Bernoulli: p deve estar em [0, 1]
Binomial: n deve ser positivo; p em [0, 1]
Normal: sigma deve ser maior que 0
Poisson: lambda deve ser maior que 0
Hipergeométrica: k não pode exceder min(n, K)

As validações estão implementadas nos construtores de cada classe em include/ e src/.

## Documentação Doxygen

Como acessar:

Abra o arquivo docs/html/index.html no navegador, ou acesse online pelo GitHub Pages:
https://arthurzzz77.github.io/Calculadora-de-probabilidade/html/hierarchy.html

## Planejamento
Etapa 1: Planejamento, cartões CRC e User Stories
Etapa 2: Implementação dos arquivos .hpp
Etapa 3: Implementação dos arquivos .cpp
Etapa 4: Finalização do trabalho e documentação
A divisão inicial foi seguida, com ajustes pontuais por colaboração mútua entre membros.
A implementação da distribuição Normal exigiu atenção especial à integração numérica para o cálculo da acumulada.
A documentação Doxygen foi gerada ao final, a partir dos comentários já presentes nos headers.

##Evidências no GitHub

Commits individuais por membro refletindo a divisão do trabalho
Cartões CRC e User Stories disponíveis em docs/
Histórico completo em: https://github.com/Arthurzzz77/Calculadora-de-probabilidade/commits/main
