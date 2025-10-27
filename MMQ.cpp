#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include "gnuplot-iostream.h"
using namespace std;
using namespace gnuplotio;

//plotagem dos gráficos

void plotar_graficos(vector<pair<double, double>> reta, vector<double> x, vector<double> y, int tipo_escala) {
    
    Gnuplot gp;

    gp << "set title 'Ajuste Linear (MMQ)'\n";
    gp << "set xlabel 'X'\n";
    gp << "set ylabel 'Y'\n";

    if (tipo_escala == 1){
        gp << "set logscale x\n";
    }else if (tipo_escala == 2){
        gp << "set logscale y\n";
    }else if (tipo_escala == 3){
        gp << "set logscale xy\n";
    }else{
        gp << "unset logscale\n";
    }

    gp << "plot '-' with points title 'Dados', "
          "'-' with lines title 'Ajuste Linear'\n";
    gp.send1d(make_pair(x, y));
    gp.send1d(reta);

    gp << "pause mouse close\n";
}



int main(){
    vector<double>x, y;
    double entrada, sumX=0, sumY=0, sumXY=0, sumX2=0, sumY2=0, A, B, desvioA, desvioB, erro_padrão_reg;
    int n, decisao_grafico, tipo_escala, escolha_x, escolha_y, qtd_pontos;

    cout << "Calculadora de MMQ" << endl;
    cout << " Digite a quantidade de dados (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Erro: N deve ser maior que zero." << endl;
        return 1;
    }

    //Populando X

    cout << endl << "Digite todos os X: ";

    for(int i=0; i<n ; i++){
        cin >> entrada;
        x.push_back(entrada);
    }

    //Populando Y

    cout << endl << "Digite todos os Y: ";

    for(int i=0; i<n ; i++){
        cin >> entrada;
        y.push_back(entrada);
    }

    //função aninhada para decidir as variáveis do eixo X e Y na hora de plotar o gráfico

    auto gerar_variavel = [&](int tipo) -> vector<double> {
        vector<double> v;

        for (int i = 0; i < n; i++) {
            switch (tipo) {
                case 1: v.push_back(x[i]); break;
                case 2: v.push_back(x[i] * x[i]); break;
                case 3: v.push_back(y[i]); break;
                case 4: v.push_back(y[i] * y[i]); break;
                case 5: v.push_back(x[i] * y[i]); break;
            }
        }
        return v;
    };

    //calculando os somatórios

    for(int i=0; i<n; i++){
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    //Calculando A e B

    double denominador = ((sumX*sumX) - (n*sumX2));

    //verificando se o denominador não é zero (ou próximo disso (bit flutuante))

    if(abs(denominador) < 1e-9){
        cout << "Erro, o denominador não pode ser zero, verificar os valores digitados de X (não podem ser iguais)" << endl;
        return 1;
    }

    A = ((sumX * sumY) - (n*sumXY))/ denominador;
    B = ((sumXY * sumX) - (sumX2*sumY))/ denominador;

    cout << "A equação ajustada com MMQ ficou: " << "Y = " << A << "x + " << B << endl;

    //Calculando os desvios

    if(n > 2){
        erro_padrão_reg = sqrt((sumY2 - (B*sumY) - (A*sumXY))/(n-2));
        desvioA = (erro_padrão_reg * sqrt(n/((n*sumX2)-(sumX*sumX))));
        desvioB = (erro_padrão_reg * sqrt(sumX2 / ((n*sumX2) - (sumX*sumX))));
        cout << "E os desvios de A e B são respectivamente: " << desvioA << " e " << desvioB << endl;
    }else{
        cout << "Não é possível calcular os desvios (N <= 2) " << endl;
    }

    cout << "Deseja plotar um gráfico? (Digite 1 pra sim e 2 pra não): ";
    cin >> decisao_grafico;

    while (decisao_grafico == 1) {

        //configuração do gráfico

        cout << endl << "Escolha o tipo de escala do gráfico:\n";
        cout << "0 - Linear\n";
        cout << "1 - Log X\n";
        cout << "2 - Log Y\n";
        cout << "3 - Log-Log\n";
        cout << "Digite sua escolha: ";
        cin >> tipo_escala;

        cout << endl << "Escolha a variável do eixo X:\n";
        cout << "1 - X\n";
        cout << "2 - X²\n";
        cout << "3 - Y\n";
        cout << "4 - Y²\n";
        cout << "5 - XY\n";
        cin >> escolha_x;

        cout << endl << "Escolha a variável do eixo Y:\n";
        cout << "1 - Y\n";
        cout << "2 - Y²\n";
        cout << "3 - X\n";
        cout << "4 - X²\n";
        cout << "5 - XY\n";
        cin >> escolha_y;

        cout << endl << "Quantos pontos o gráfico deve ter? (recomendado 100)" << endl;
        cout << "Obs: com muitos pontos a geração ficará lenta e com poucos o gráfico ficará incompleto" << endl;
        cin >> qtd_pontos;

        if(qtd_pontos <= 0){
            cerr << "A quantidade de pontos deve ser positiva (>0)";
            return 1;
        }

        //Ajustes dos pontos e eixos baseados nas configurações

        if(tipo_escala >= 0 && tipo_escala <= 3){
            if(escolha_x >= 1 && escolha_x <=5 && escolha_y >= 1 && escolha_y <=5){
                vector<double> eixoX = gerar_variavel(escolha_x);
                vector<double> eixoY = gerar_variavel(escolha_y);
                vector<pair<double, double>> reta;
                
                double x_min = *min_element(eixoX.begin(), eixoX.end());
                double x_max = *max_element(eixoX.begin(), eixoX.end());
            
                double passoX = (qtd_pontos > 1) ? (x_max - x_min) / (qtd_pontos - 1) : 0;

                for (int i = 0; i < qtd_pontos; i++) {
                    double xi = x_min + i * passoX;
                    double yi = A * xi + B; 
                    reta.push_back(make_pair(xi, yi));
                }
                
                plotar_graficos(reta, eixoX, eixoY, tipo_escala);

            }else{
                cerr << "Escolha variáveis válidas para o eixo X e Y [1, 5]" << endl;
            }
        }else{
            cerr << "Digite um tipo de escala válido [0, 3]" << endl;
        }
        
        cout << endl << "Deseja plotar mais um gráfico? (Digite 1 pra sim e 2 pra não): ";
        if (!(cin >> decisao_grafico)) {
            cerr << "\nErro na leitura da entrada. Encerrando." << endl;
            decisao_grafico = 2; 
        }
    }
    
    cout << "Finalizando o programa" << endl;
    return 0;
}

