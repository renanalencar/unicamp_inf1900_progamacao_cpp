/**
 * @file ex1.cpp
 *
 * @brief Exercício 1.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

// Contador global atômico
std::atomic<int> contador(0);

// Função executada por cada thread
void incrementaContador(int incrementos) {
    for (int i = 0; i < incrementos; ++i) {
        contador++; // Operação de incremento atômico
    }
}

int main() {
    // Número total de threads
    const int numThreads = 5;

    // Número de incrementos por thread
    const int incrementosPorThread = 100000;

    // Vetor para armazenar as threads
    std::vector<std::thread> threads;

    // Lança as threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementaContador, incrementosPorThread);
    }

    // Aguarda todas as threads concluírem
    for (auto& thread : threads) {
        thread.join();
    }

    // Imprime o resultado
    std::cout << "Threads: " << numThreads << " | Contador: " << contador << std::endl;

    return 0;
}
