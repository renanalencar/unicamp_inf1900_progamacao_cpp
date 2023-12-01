/**
 * @file ex2.cpp
 *
 * @brief Exercício 2.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <random>
#include <locale>
#include <codecvt>

class ContaBancaria {
public:
    ContaBancaria(int numero, double saldo) : numeroConta(numero), saldo(saldo) {}

    void depositar(double valor) {
        std::lock_guard<std::mutex> lock(mutexConta);
        saldo += valor;
    }

    void sacar(double valor) {
        std::lock_guard<std::mutex> lock(mutexConta);
        saldo -= valor;
    }

    std::mutex& obterMutexConta() {
        return mutexConta;
    }

    double obterSaldo() const {
        return saldo;
    }

    int obterNumeroConta() const {
        return numeroConta;
    }

private:
    int numeroConta;
    double saldo;
    std::mutex mutexConta;
};

std::list<ContaBancaria> contas;
std::mutex mutexCout;

void imprimirInformacoesConta(const ContaBancaria& conta) {
    std::lock_guard<std::mutex> lock(mutexCout);
    std::wcout.imbue(std::locale(""));  // Imbuir a localização para lidar com caracteres acentuados
    std::wcout << L"Conta " << conta.obterNumeroConta() << L": Saldo = R$" << conta.obterSaldo() << std::endl;
}


void transferir(ContaBancaria& origem, ContaBancaria& destino, double valor) {
    std::unique_lock<std::mutex> lockOrigem(origem.obterMutexConta(), std::defer_lock);
    std::unique_lock<std::mutex> lockDestino(destino.obterMutexConta(), std::defer_lock);

    origem.sacar(valor);
    destino.depositar(valor);

    std::lock_guard<std::mutex> lockCout(mutexCout);
    std::wcout.imbue(std::locale(""));  // Imbuir a localização para lidar com caracteres acentuados
    std::wcout << L"Transferência da Conta " << origem.obterNumeroConta() << L" para Conta " << destino.obterNumeroConta() << L": R$" << valor << std::endl;
}

void simularTransacoes() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuicaoContas(0, contas.size() - 1);
    std::uniform_real_distribution<> distribuicaoValores(10.0, 100.0);

    for (int i = 0; i < 10; ++i) {
        int indiceContaOrigem = distribuicaoContas(gen);
        int indiceContaDestino = distribuicaoContas(gen);

        while (indiceContaOrigem == indiceContaDestino) {
            indiceContaDestino = distribuicaoContas(gen);
        }

        double valorTransferencia = distribuicaoValores(gen);

        transferir(*std::next(contas.begin(), indiceContaOrigem), *std::next(contas.begin(), indiceContaDestino), valorTransferencia);
    }
}

int main() {
    // Configuração da localização para lidar com acentuação
    std::locale::global(std::locale("pt_BR.UTF8"));

    // Inicialização de contas
    contas.emplace_back(1, 1000.0);
    contas.emplace_back(2, 1500.0);
    contas.emplace_back(3, 2000.0);

    // Impressão inicial
    std::for_each(contas.begin(), contas.end(), imprimirInformacoesConta);

    // Criação de threads para simulação de transações
    const int numThreads = 3;
    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(simularTransacoes);
    }

    // Aguarda todas as threads terminarem
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Impressão final
    std::for_each(contas.begin(), contas.end(), imprimirInformacoesConta);
    
    system("pause");

    return 0;
}
