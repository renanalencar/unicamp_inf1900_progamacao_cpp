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
#include <thread>
#include <mutex>

std::mutex mutexContador;
int contador = 0;

void incrementar() {
    std::lock_guard<std::mutex> lock(mutexContador);  // Adquire o mutex automaticamente e libera ao sair do escopo
    contador++;
}

void decrementar() {
    std::lock_guard<std::mutex> lock(mutexContador);
    contador--;
}

int main() {
    const int numThreads = 8;
    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        if (i % 2 == 0) {
            threads[i] = std::thread(incrementar);
        }
        else {
            threads[i] = std::thread(decrementar);
        }
    }

    // Aguarda todas as threads terminarem
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Verifica se o valor do contador é zero
    if (contador == 0) {
        std::cout << "Operações de incremento e decremento estão balanceadas. Contador: " << contador << std::endl;
    }
    else {
        std::cout << "Erro: o valor do contador não é zero. Contador: " << contador << std::endl;
    }

    return 0;
}
