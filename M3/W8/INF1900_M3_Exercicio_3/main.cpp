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
#include <memory>
#include <string>
#include <utility>

template <typename T>
class FileResource {
public:
    // Construtor que abre o arquivo
    FileResource(const std::string& filename) : file_(std::make_unique<std::fstream>(filename, std::ios::in | std::ios::binary)) {
        if (!file_->is_open()) {
            throw std::runtime_error("Não foi possível abrir o arquivo.");
        }
    }

    // Método para ler e retornar os dados do arquivo
    T ReadData() {
        T data;
        if (file_->read(reinterpret_cast<char*>(&data), sizeof(T))) {
            return data;
        } else {
            throw std::runtime_error("Erro ao ler os dados do arquivo.");
        }
    }

    // Método para escrever dados no arquivo
    void WriteData(const T& data) {
        if (file_->write(reinterpret_cast<const char*>(&data), sizeof(T))) {
            file_->flush();
        } else {
            throw std::runtime_error("Erro ao escrever os dados no arquivo.");
        }
    }

    // Método para mover o recurso de arquivo para outro objeto FileResource
    void MoveTo(FileResource& other) {
        other.file_ = std::move(file_);
    }

private:
    std::unique_ptr<std::fstream> file_;
};

int main() {
    try {
        FileResource<int> fileInt("int_data.dat");
        int data = fileInt.ReadData();
        std::cout << "Dados lidos: " << data << std::endl;

        FileResource<float> fileFloat("float_data.dat");
        float newData = 42.5;
        fileFloat.WriteData(newData);

        // Movendo o recurso de arquivo de um objeto FileResource para outro
        FileResource<float> movedResource("moved_data.dat");
        fileFloat.MoveTo(movedResource);

        float movedData = movedResource.ReadData();
        std::cout << "Dados movidos: " << movedData << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
