#include <iostream>
#include <memory>
#include <type_traits>

// Classe FileResource
template <typename T>
class FileResource {
public:
    // Construtor
    FileResource(T& resource) {
        // Aloca um ponteiro para o recurso
        resource_ = std::make_unique<T>(resource);
    }

    // Destrutor
    ~FileResource() {
        // Libera o recurso
        resource_.reset();
    }

    // Lê os dados do arquivo
    void ReadData() {
        // Imprime o tipo do recurso
        std::cout << typeid(T).name() << " sendo lido" << std::endl;
    }

    // Escreve os dados no arquivo
    void WriteData() {
        // Imprime o tipo do recurso
        std::cout << typeid(T).name() << " sendo escrito" << std::endl;
    }

    // Move o recurso para outro objeto FileResource
    void MoveTo(FileResource<T>& other) {
        // Troca os ponteiros para os recursos
        std::swap(resource_, other.resource_);
    }

private:
    // Ponteiro para o recurso
    std::unique_ptr<T> resource_;
};
