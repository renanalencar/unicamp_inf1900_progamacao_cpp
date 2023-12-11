#include <iostream>
/**
 * @file ex2.cpp
 *
 * @brief Exercício 2.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <atomic>
#include <thread>
#include <vector>
#include <random>

// Variável atômica para armazenar o valor máximo
std::atomic<int> maximo(0);

// Função para geração de números aleatórios
int gerarNumeroAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuicao(1, 1000);
    return distribuicao(gen);
}

// Função executada por cada thread
void atualizarMaximo(int idThread, int iteracoes) {
    for (int i = 0; i < iteracoes; ++i) {
        int valorAleatorio = gerarNumeroAleatorio();

        // Atualiza o máximo atomicamente
        maximo.store(std::max(maximo.load(), valorAleatorio));

        // Imprime o ID da thread e o valor aleatório gerado
        std::cout << "Thread: " << idThread << " | Valor: " << valorAleatorio << std::endl;
    }
}

int main() {
    // Número total de threads
    const int numThreads = 5;

    // Número de iterações por thread
    const int iteracoesPorThread = 10;

    // Vetor para armazenar as threads
    std::vector<std::thread> threads;

    // Lança as threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(atualizarMaximo, i, iteracoesPorThread);
    }

    // Aguarda todas as threads concluírem
    for (auto& thread : threads) {
        thread.join();
    }

    // Imprime o valor máximo encontrado
    std::cout << "Variavel Atomica: " << maximo << std::endl;

    return 0;
}
