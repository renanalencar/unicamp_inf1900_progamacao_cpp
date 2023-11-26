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
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

class ContaBancaria {
public:
    ContaBancaria(int numero, double saldo) : numero(numero), saldo(saldo) {}

    int getNumero() const {
        return numero;
    }

    double getSaldo() const {
        return saldo;
    }

    void depositar(double valor) {
        std::lock_guard<std::mutex> lock(mutexConta);
        saldo += valor;
    }

    bool sacar(double valor) {
        std::lock_guard<std::mutex> lock(mutexConta);
        if (valor <= saldo) {
            saldo -= valor;
            return true;
        }
        return false;
    }

    void transferir(ContaBancaria& destino, double valor) {
        std::lock(mutexConta, destino.mutexConta);
        std::lock_guard<std::mutex> selfLock(mutexConta, std::adopt_lock);
        std::lock_guard<std::mutex> destLock(destino.mutexConta, std::adopt_lock);

        if (sacar(valor)) {
            destino.depositar(valor);
            std::cout << "Transferência de conta " << numero << " para conta " << destino.getNumero() << ": $" << valor << std::endl;
        }
        else {
            std::cout << "Transferência falhou de conta " << numero << " para conta " << destino.getNumero() << ": Saldo insuficiente." << std::endl;
        }
    }

private:
    int numero;
    double saldo;
    mutable std::mutex mutexConta;
};

void simularTransacoes(std::vector<ContaBancaria>& contas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribuicaoContas(0, contas.size() - 1);

    for (int i = 0; i < 10; ++i) {
        int contaOrigem = distribuicaoContas(gen);
        int contaDestino = distribuicaoContas(gen);

        if (contaOrigem != contaDestino) {
            double valor = static_cast<double>(distribuicaoContas(gen)) * 10.0;
            contas[contaOrigem].transferir(contas[contaDestino], valor);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Introduz uma pequena pausa para aumentar a chance de deadlock
    }
}

int main() {
    std::vector<ContaBancaria> contas = {
        ContaBancaria(1, 1000.0),
        ContaBancaria(2, 1500.0),
        ContaBancaria(3, 2000.0)
        // Adicione mais contas conforme necessário
    };

    std::cout << "Saldo inicial das contas:" << std::endl;
    for (const auto& conta : contas) {
        std::cout << "Conta " << conta.getNumero() << ": $" << conta.getSaldo() << std::endl;
    }

    std::thread thread1(simularTransacoes, std::ref(contas));
    std::thread thread2(simularTransacoes, std::ref(contas));

    thread1.join();
    thread2.join();

    std::cout << "Saldo final das contas:" << std::endl;
    for (const auto& conta : contas) {
        std::cout << "Conta " << conta.getNumero() << ": $" << conta.getSaldo() << std::endl;
    }

    return 0;
}

