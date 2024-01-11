#include <iostream>

struct MinhaStruct {
    int valor1;
    int valor2;

    MinhaStruct(int v1, int v2) : valor1(v1), valor2(v2) {}
};

class MinhaClasse {
public:
    // Vari�vel est�tica que � uma struct
    static MinhaStruct minhaVariavel;

    // M�todo est�tico para inicializar a vari�vel est�tica
    static void InicializarVariavel(int v1, int v2) {
        minhaVariavel = MinhaStruct(v1, v2);
    }

    // Outros m�todos e membros da classe...
};


int main() {
    // Chamando o m�todo est�tico para inicializar a vari�vel est�tica
    MinhaClasse::InicializarVariavel(42, 24);

    // Acessando membros da vari�vel est�tica (MinhaStruct)
    std::cout << "Valor1: " << MinhaClasse::minhaVariavel.valor1 << std::endl;
    std::cout << "Valor2: " << MinhaClasse::minhaVariavel.valor2 << std::endl;

    return 0;
}