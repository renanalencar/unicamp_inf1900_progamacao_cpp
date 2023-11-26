/**
 * @file ex3.cpp
 *
 * @brief Exercício 3.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mutexPrint;
std::mutex mutexTables;
std::condition_variable cvTables;

class Cliente {
public:
    Cliente(int id) : id(id) {}

    void esperarMesa() {
        std::unique_lock<std::mutex> lock(mutexTables);
        cvTables.wait(lock, [this] { return mesasDisponiveis > 0; });

        mesasDisponiveis--;
        mesaAlocada = true;
        mesaId = proximoIdMesa++;
        lock.unlock();

        imprimir("Cliente " + std::to_string(id) + " está aguardando uma mesa.");
        imprimir("Cliente " + std::to_string(id) + " sentou na mesa " + std::to_string(mesaId) + ".");
    }

    void receberPedido() {
        imprimir("Cliente " + std::to_string(id) + " recebeu seu pedido.");
    }

    void liberarMesa() {
        std::lock_guard<std::mutex> lock(mutexTables);
        mesasDisponiveis++;
        mesaAlocada = false;
        cvTables.notify_one();
    }

private:
    int id;
    static int proximoIdMesa;
    static int mesasDisponiveis;
    bool mesaAlocada = false;
    int mesaId = -1;

    void imprimir(const std::string& mensagem) {
        std::lock_guard<std::mutex> lock(mutexPrint);
        std::cout << "\033[1;34m" << mensagem << "\033[0m" << std::endl;
    }
};

int Cliente::proximoIdMesa = 1;
int Cliente::mesasDisponiveis = 5;  // Número inicial de mesas disponíveis

class Garcom {
public:
    Garcom(int id) : id(id) {}

    void atenderCliente(Cliente& cliente) {
        imprimir("Garçom " + std::to_string(id) + " está disponível.");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Simula o tempo para preparar o pedido

        imprimir("Garçom " + std::to_string(id) + " atendeu o cliente " + std::to_string(cliente.getId()) +
            " na mesa " + std::to_string(cliente.getMesaId()) + ".");

        cliente.receberPedido();
        cliente.liberarMesa();
    }

private:
    int id;

    void imprimir(const std::string& mensagem) {
        std::lock_guard<std::mutex> lock(mutexPrint);
        std::cout << "\033[1;32m" << mensagem << "\033[0m" << std::endl;
    }
};

void clienteThread(Cliente& cliente, Garcom& garcom) {
    cliente.esperarMesa();
    garcom.atenderCliente(cliente);
}

int main() {
    const int numMesas = 5;
    const int numGarcons = 3;
    const int numClientes = 10;

    std::vector<Cliente> clientes;
    std::vector<Garcom> garcons;

    for (int i = 0; i < numClientes; ++i) {
        clientes.emplace_back(i);
    }

    for (int i = 0; i < numGarcons; ++i) {
        garcons.emplace_back(i);
    }

    std::vector<std::thread> threads;

    for (int i = 0; i < numClientes; ++i) {
        threads.emplace_back(clienteThread, std::ref(clientes[i]), std::ref(garcons[i % numGarcons]));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
