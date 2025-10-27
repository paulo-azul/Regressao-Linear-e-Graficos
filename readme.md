# Calculadora de Regressão Linear (MMQ) com Gnuplot

Este projeto foi desenvolvido por **Paulo Teles Serra Azul**, estudante de Engenharia de Computação da UFBA, como uma ferramenta de apoio para a matéria de Física Experimental (FISD41).

Objetivo do programa é receber um conjunto de dados (X, Y) e realizar uma análise completa de regressão linear, incluindo: 

 - Calcular os coeficientes linear (B) e angular (A) da reta de ajuste (Y = Ax + B) pelo Método dos Mínimos Quadrados.

 - Calcular os desvios (erros) associados aos coeficientes A e B.Gerar um gráfico de alta qualidade dos pontos de dados originais e da reta de ajuste.
 
 - Permitir a linearização de dados diretamente no gráfico, oferecendo escalas Linear, Log-X, Log-Y e Log-Log.
 
 - Permitir a transformação de variáveis nos eixos (ex: plotar X² vs Y) para verificar visualmente a linearização.
 
 Nota sobre a Implementação: código foi implementado em C++ moderno (C++11 ou superior). A geração de gráficos não é nativa do C++, então o programa atua como um "controlador" para o Gnuplot, uma poderosa ferramenta de plotagem científica. A comunicação com o Gnuplot é gerenciada pela biblioteca header-only gnuplot-iostream. Para um gerenciamento de arquivos e streams mais robusto, o código utiliza as bibliotecas Boost (iostreams, system, filesystem). Uma função lambda (gerar_variavel) é usada dentro da main para transformar os vetores de dados de forma eficiente e limpa antes da plotagem. O arquivo main.cpp é um script compilador auxiliar, também em C++, que automatiza o processo de compilação do programa principal (MMQ.cpp) com as flags corretas do Boost.
 
 Dependências Para compilar e executar este programa, você precisará de:
  - Compilador C++: Um compilador que suporte C++11 ou superior (ex: g++).
  - Gnuplot: O programa que efetivamente gera os gráficos. Comando para baixar:
        - Bash# Em sistemas Debian/Ubuntu (como Pop!_OS):

            `sudo apt update`
            `sudo apt install gnuplot`

  - Bibliotecas Boost (Development): Necessárias para a compilação com main.cpp. Comando para baixar:
        - Bash# Instala os cabeçalhos de desenvolvimento do Boost:

            `sudo apt install libboost-all-dev`

  - Biblioteca gnuplot-iostream: O arquivo gnuplot-iostream.h deve estar presente no mesmo diretório do MMQ.cpp.

Como Compilar (Recomendado) O arquivo main.cpp foi criado para simplificar a compilação.
    Bash# 1. Compile o script auxiliar primeiro
    `g++ main.cpp -o compilar`

# 2. Execute o script auxiliar. Ele irá compilar e executar o MMQ
`./compilar`

Como Usar o Programa: Execute o programa compilado (./MMQ ou usando ./compilar). Digite a quantidade de dados ($N$).Digite todos os N valores de X. Digite todos os N valores de Y. O programa exibirá a equação ajustada e os desvios. Digite 1 para "Sim" quando perguntado se deseja plotar um gráfico ou 2 para finalizar o programa. Escolha a Escala: (0 para Linear, 3 para Log-Log, etc.). Escolha os Eixos: Selecione as variáveis para os eixos X e Y (ex: 1 para X, 2 para X², ...). Pontos da Reta: Digite a quantidade de pontos para desenhar a linha (recomendado: 100). Uma janela do Gnuplot será aberta.

*Importante*: Feche a janela do gráfico para que o programa continue. 

Sobre a criação: Foi a primeira vez que usei o Gnuplot e Funções Lambda, favor entrar em contato com qualquer sujestã de melhoria/correção. Tentei começar a comentar o código (iniciar essa prática), então talvez os comentários ainda não sejam adequados (estou me acostumando a fazer)
