#include <iostream>

struct MinhaStruct {
    int valor1;
    int valor2;

    MinhaStruct(int v1, int v2) : valor1(v1), valor2(v2) {}
};

class MinhaClasse {
public:
    // Variável estática que é uma struct
    static MinhaStruct minhaVariavel;

    // Método estático para inicializar a variável estática
    static void InicializarVariavel(int v1, int v2) {
        minhaVariavel = MinhaStruct(v1, v2);
    }

    // Outros métodos e membros da classe...
};


int main() {
    // Chamando o método estático para inicializar a variável estática
    MinhaClasse::InicializarVariavel(42, 24);

    // Acessando membros da variável estática (MinhaStruct)
    std::cout << "Valor1: " << MinhaClasse::minhaVariavel.valor1 << std::endl;
    std::cout << "Valor2: " << MinhaClasse::minhaVariavel.valor2 << std::endl;

    return 0;
}