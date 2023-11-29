#include <iostream>
/**
 * @file ex3_1.cpp
 *
 * @brief Exercício 3.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

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

    // Criação de tarefas assíncronas usando std::packaged_task
    std::packaged_task<int(const std::vector<int>&, size_t, size_t)> task1(calcularSomaParte);
    std::packaged_task<int(const std::vector<int>&, size_t, size_t)> task2(calcularSomaParte);

    // Obtém os futuros associados às tarefas
    std::future<int> futuro1 = task1.get_future();
    std::future<int> futuro2 = task2.get_future();

    // Lança as tarefas assíncronas
    std::thread thread1(std::move(task1), std::cref(vetor), 0, metade);
    std::thread thread2(std::move(task2), std::cref(vetor), metade, tamanhoVetor);

    // Aguarda o término das tarefas
    thread1.join();
    thread2.join();

    // Obtém os resultados das tarefas
    int resultado1 = futuro1.get();
    int resultado2 = futuro2.get();

    // Soma total
    int somaTotal = resultado1 + resultado2;

    // Exibe o resultado
    std::cout << "Soma do Vetor: " << somaTotal << std::endl;

    return 0;
}
