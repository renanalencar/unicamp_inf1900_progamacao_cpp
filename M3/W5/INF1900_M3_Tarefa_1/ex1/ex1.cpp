/**
 * @file ex1.cpp
 *
 * @brief Classe com função main para execução dos pontos da atividade.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF8");
	
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
