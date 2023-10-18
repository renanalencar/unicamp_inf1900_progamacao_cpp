/**
 * @file main.cpp
 *
 * @brief Classe com função main para execução dos pontos da atividade.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

// Classe derivada de std::exception para representar a exceção de arquivo não-texto
class NotATextFileException : public std::exception {
public:
    const char* what() const noexcept override {
        return "O arquivo não é um arquivo de texto válido.";
    }
};

int main() {
    std::string filename;

    // Passo 1: Solicitar ao usuário o nome do arquivo de texto
    std::cout << "Digite o nome do arquivo de texto: ";
    std::cin >> filename;

    try {
        // Passo 2: Verificar se o arquivo existe
        if (!fs::exists(filename)) {
            throw fs::filesystem_error("Arquivo não encontrado", fs::errc::no_such_file_or_directory);
        }

        // Passo 3: Tentar abrir o arquivo
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Não foi possível abrir o arquivo.");
        }

        // Passo 4: Tratar exceções durante a abertura do arquivo
        try {
            // Passo 5: Verificar se o arquivo é de texto
            std::string line;
            if (!std::getline(file, line)) {
                throw NotATextFileException();
            }

            // Contagem de linhas, palavras e caracteres
            int lineCount = 1;
            int wordCount = 0;
            int charCount = line.length();

            while (std::getline(file, line)) {
                lineCount++;
                charCount += line.length();

                // Contagem de palavras (considerando espaços como delimitadores)
                bool inWord = false;
                for (char c : line) {
                    if (std::isspace(c)) {
                        inWord = false;
                    } else if (!inWord) {
                        inWord = true;
                        wordCount++;
                    }
                }
            }

            // Passo 6: Exibir informações
            std::cout << "Número de linhas: " << lineCount << std::endl;
            std::cout << "Número de palavras: " << wordCount << std::endl;
            std::cout << "Número de caracteres: " << charCount << std::endl;
        } catch (const NotATextFileException& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar o arquivo: " << e.what() << std::endl;
        }

        // Fechar o arquivo após o processamento
        file.close();

        // Se o programa chegar a este ponto, o arquivo existe e foi aberto com sucesso
        std::cout << "Arquivo aberto e processado com sucesso." << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Erro ao acessar o arquivo: " << e.what() << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao abrir o arquivo: " << e.what() << std::endl;
    }

    return 0;
}
