// inf1900_m3_a1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Criando diretórios
    fs::create_directory("diretorio1");
    fs::create_directories("diretorio2/diretorio3");

    // Copiando um arquivo
    fs::copy("arquivo_origem.txt", "arquivo_destino.txt", fs::copy_options::overwrite_existing);

    // Renomeando um arquivo
    fs::rename("arquivo_destino.txt", "arquivo_renomeado.txt");

    // Definindo permissões para um arquivo
    fs::permissions("arquivo_renomeado.txt", fs::perms::owner_read | fs::perms::owner_write);

    // Verificando a existência de um arquivo ou diretório
    bool existe = fs::exists("arquivo_renomeado.txt");
    std::cout << "Arquivo existe? " << existe << std::endl;

    // Verificando se é um arquivo regular ou diretório
    bool e_arquivo = fs::is_regular_file("arquivo_renomeado.txt");
    std::cout << "É um arquivo regular? " << e_arquivo << std::endl;

    bool e_diretorio = fs::is_directory("diretorio1");
    std::cout << "É um diretório? " << e_diretorio << std::endl;

    // Verificando se um diretório está vazio
    bool esta_vazio = fs::is_empty("diretorio1");
    std::cout << "Diretório está vazio? " << esta_vazio << std::endl;

    // Removendo um arquivo
    fs::remove("arquivo_renomeado.txt");

    // Removendo um diretório e seu conteúdo recursivamente
    fs::remove_all("diretorio1");

    try {
        // Tentando acessar um arquivo que não existe
        fs::directory_entry entry("arquivo_inexistente.txt");
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao acessar arquivo inexistente: " << e.what() << std::endl;
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
