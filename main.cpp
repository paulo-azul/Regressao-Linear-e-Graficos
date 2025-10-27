#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

    cout << "Compilando e executando MMQ.cpp com as bibliotecas corretas...\n\n";

    int result = system("g++ MMQ.cpp -o MMQ -lboost_iostreams -lboost_system -lboost_filesystem");

    if (result != 0) {
        cerr << "❌ Erro na compilação!" << endl;
        return result;
    }

    cout << "✅ Compilado com sucesso! Executando..." << endl << endl;
    system("./MMQ");

    return 0;
}
