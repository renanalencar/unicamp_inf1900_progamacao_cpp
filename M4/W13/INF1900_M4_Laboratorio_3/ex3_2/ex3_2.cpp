/**
 * @file ex3_2.cpp
 *
 * @brief Exercício 3.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include <future>
#include <numeric>
#include <random>

 // Função para calcular a soma de uma parte do vetor
int calcularSomaParte(const std::vector<int>& vetor, size_t inicio, size_t fim) {
    return std::accumulate(vetor.begin() + inicio, vetor.begin() + fim, 0);
}

int main() {
    // Inicialização do vetor
    const size_t tamanhoVetor = 100;
    std::vector<int> vetor(tamanhoVetor);

    // Preenchimento do vetor com valores aleatórios
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<> distribuicao(1, 100);
    for (int& elemento : vetor) {
        elemento = distribuicao(gerador);
    }

    // Divisão do vetor
    size_t metade = tamanhoVetor / 2;

    // Criação de tarefas assíncronas usando std::async
    std::future<int> futuro1 = std::async(calcularSomaParte, std::cref(vetor), 0, metade);
    std::future<int> futuro2 = std::async(calcularSomaParte, std::cref(vetor), metade, tamanhoVetor);

    // Obtém os resultados das tarefas
    int resultado1 = futuro1.get();
    int resultado2 = futuro2.get();

    // Soma total
    int somaTotal = resultado1 + resultado2;

    // Exibe o resultado
    std::cout << "Soma do Vetor: " << somaTotal << std::endl;

    return 0;
}
