// ex2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Ferramenta {
    int numeroRegistro;
    string nomeFerramenta;
    int quantidade;
    double preco;
};

// Função para inicializar o arquivo de acesso aleatório com registros vazios
void inicializarArquivo(const string& arquivoNome) {
    ofstream arquivo(arquivoNome, ios::binary | ios::out);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    Ferramenta ferramentaVazia = { 0, "", 0, 0.0 };

    for (int i = 0; i < 100; ++i) {
        arquivo.write(reinterpret_cast<char*>(&ferramentaVazia), sizeof(Ferramenta));
    }

    arquivo.close();
}

// Função para adicionar uma ferramenta ao arquivo
void adicionarFerramenta(const string& arquivoNome, const Ferramenta& ferramenta, int numeroRegistro) {
    fstream arquivo(arquivoNome, ios::binary | ios::in | ios::out);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    // Posiciona o ponteiro de leitura/gravação no registro correto
    arquivo.seekp(numeroRegistro * sizeof(Ferramenta), ios::beg);
    arquivo.write(reinterpret_cast<const char*>(&ferramenta), sizeof(Ferramenta));

    arquivo.close();
}

// Função para listar todas as ferramentas do arquivo
void listarFerramentas(const string& arquivoNome) {
    ifstream arquivo(arquivoNome, ios::binary | ios::in);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    Ferramenta ferramenta;

    while (arquivo.read(reinterpret_cast<char*>(&ferramenta), sizeof(Ferramenta))) {
        if (ferramenta.numeroRegistro != 0) {
            cout << "Número de Registro: " << ferramenta.numeroRegistro << endl;
            cout << "Nome da Ferramenta: " << ferramenta.nomeFerramenta << endl;
            cout << "Quantidade: " << ferramenta.quantidade << endl;
            cout << "Preço: " << ferramenta.preco << endl << endl;
        }
    }

    arquivo.close();
}

// Função para excluir uma ferramenta com base no número de registro
void excluirFerramenta(const string& arquivoNome, int numeroRegistro) {
    Ferramenta ferramentaVazia = { 0, "", 0, 0.0 };

    fstream arquivo(arquivoNome, ios::binary | ios::in | ios::out);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    arquivo.seekp(numeroRegistro * sizeof(Ferramenta), ios::beg);
    arquivo.write(reinterpret_cast<const char*>(&ferramentaVazia), sizeof(Ferramenta));

    arquivo.close();
}

int main() {
    const string arquivoNome = "hardware.dat";

    // Inicializa o arquivo com registros vazios (apenas na primeira execução)
    ifstream arquivoVerificador(arquivoNome);
    if (!arquivoVerificador) {
        inicializarArquivo(arquivoNome);
    }
    arquivoVerificador.close();

    while (true) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar uma ferramenta" << endl;
        cout << "2. Listar todas as ferramentas" << endl;
        cout << "3. Excluir uma ferramenta" << endl;
        cout << "4. Sair" << endl;

        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            Ferramenta novaFerramenta;
            cout << "Número de Registro: ";
            cin >> novaFerramenta.numeroRegistro;
            cout << "Nome da Ferramenta: ";
            cin >> novaFerramenta.nomeFerramenta;
            cout << "Quantidade: ";
            cin >> novaFerramenta.quantidade;
            cout << "Preço: ";
            cin >> novaFerramenta.preco;

            adicionarFerramenta(arquivoNome, novaFerramenta, novaFerramenta.numeroRegistro);
            cout << "Ferramenta adicionada com sucesso." << endl;
        }
        else if (escolha == 2) {
            listarFerramentas(arquivoNome);
        }
        else if (escolha == 3) {
            int numeroRegistro;
            cout << "Informe o número de registro da ferramenta a ser excluída: ";
            cin >> numeroRegistro;

            excluirFerramenta(arquivoNome, numeroRegistro);
            cout << "Ferramenta excluída com sucesso." << endl;
        }
        else if (escolha == 4) {
            break;
        }
        else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
