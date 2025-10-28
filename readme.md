# Calculadora de Regressão Linear (MMQ) com Gnuplot

Este projeto foi desenvolvido por **Paulo Teles Serra Azul**, estudante de Engenharia de Computação da UFBA, como uma ferramenta de apoio para a matéria de Física Experimental (FISD41).

🎯 Objetivo:
 O objetivo do programa é receber um conjunto de dados brutos (X, Y) e realizar uma análise completa de regressão linear, permitindo a linearização de dados diretamente na fonte. 
 
 As funcionalidades principais incluem:
 
 - Linearização de Dados: Permite ao usuário transformar as variáveis de entrada (U e V) antes do cálculo da regressão. Isso possibilita ajustar modelos não-lineares (como exponenciais ou de potência) que podem ser linearizados.
 
 - Transformação Avançada: Oferece um menu com 15 opções de transformação para cada eixo (U e V), incluindo:X, Y, X², Y², XY$, ln(X), ln(Y), ln(X²), (Y²), ln(XY), log(X), log(Y), log(X²), log(Y²), log(XY)
 
 - Cálculo dos Coeficientes: Calcula os coeficientes linear (B) e angular (A) da reta de ajuste (V = AU + B) pelo Método dos Mínimos Quadrados.
 
 - Cálculo de Incertezas: Calcula os desvios (erros) associados aos coeficientes A e B (para N > 2).
 
 - Validação Robusta: O programa checa por entradas matematicamente impossíveis (ex: log(0) ou log(-5)) e encerra a execução com uma mensagem de erro clara, garantindo a integridade do cálculo.
 
 - Plotagem Integrada: Gera um gráfico de alta qualidade dos pontos de dados (transformados) e da reta de regressão ajustada usando o Gnuplot.
 
 - Controle de Escala: Permite que o gráfico final seja visualizado em escalas Linear, Log-X, Log-Y ou Log-Log.📝 
 
 Nota sobre a Implementação: O código foi implementado em C++ moderno (C++11 ou superior). A geração de gráficos não é nativa do C++, então o programa funciona como um "controlador" para o Gnuplot, uma poderosa ferramenta de plotagem científica. A comunicação com o Gnuplot é gerenciada pela biblioteca header-only gnuplot-iostream. Para um gerenciamento de arquivos e streams mais robusto, o código utiliza as bibliotecas Boost (iostreams, system, filesystem). Uma função lambda (`gerar_variavel`) é usada dentro da main para transformar os vetores de dados de forma eficiente e limpa antes do cálculo da regressão. O arquivo main.cpp é um script compilador auxiliar, também em C++, que automatiza o processo de compilação do programa principal (MMQ.cpp) com as flags corretas do Boost.🛠️ 
 
 Dependências para compilar e executar este programa, você precisará de:
 
 - Compilador C++: Um compilador que suporte C++11 ou superior (ex: g++).
 - Gnuplot: O programa que efetivamente gera os gráficos.
        Bash# Em sistemas Debian/Ubuntu (como Pop!_OS):
            `sudo apt update`
            `sudo apt install gnuplot`

- Bibliotecas Boost (Development): Necessárias para a compilação: 
        Bash# Instala os cabeçalhos de desenvolvimento do Boost:
            `sudo apt install libboost-all-dev`

- Biblioteca gnuplot-iostream: O arquivo gnuplot-iostream.h deve estar presente no mesmo diretório do MMQ.cpp.⚙️ 

Como Compilar (Recomendado) O arquivo main.cpp foi criado para simplificar a compilação.

 1. Compile o script auxiliar primeiro
    `g++ main.cpp -o compilar`

2. Execute o script auxiliar. Ele irá compilar o MMQ.cpp e executá-lo
    `./compilar`

🚀 Como Usar o Programa: Execute o programa usando o script compilador: `./compilar` Digite a quantidade de dados (N). Digite todos os N valores de X. Digite todos os N valores de Y. Escolha a Variável de Regressão X (Eixo U): Selecione um número de 1 a 15 (ex: 1 para X, 6 para ln(X)). Escolha a Variável de Regressão Y (Eixo V): Selecione um número de 1 a 15 (ex: 3 para Y, 8 para ln(Y)). O programa irá mostrar a equação ajustada (no formato V = AU + B) e os desvios. Digite 1 para "Sim" quando perguntado se deseja plotar um gráfico ou 2 para finalizar. Escolha a Escala de Plotagem: Selecione o tipo de escala para a janela do gráfico (0 para Linear, 3 para Log-Log, etc.). Pontos da Reta: Digite a quantidade de pontos para desenhar a linha (recomendado: 100). Uma janela do Gnuplot será aberta com seu gráfico. Importante: Feche a janela do gráfico para que o programa possa continuar e finalizar corretamente.

Obs: os pontos de dados são desenhados com pointsize 1.5 e pointtype 7 (círculo preenchido).

💬 Sobre a criação: Foi a primeira vez que usei o Gnuplot e Funções Lambda, favor entrar em contato com qualquer sujestão de melhoria/correção. Tentei começar a comentar o código (iniciar essa prática), então talvez os comentários ainda não sejam adequados (estou me acostumando a fazer).