
# Exercício 2: Sistema Bancário

## Explicação sobre o deadlock

No código do exercício 2, o deadlock ocorre devido à possível aquisição concorrente de mutexes de diferentes contas em ordens diferentes nas threads, o que pode levar a uma situação de bloqueio mútuo. O deadlock ocorre quando uma thread espera por um recurso que está sendo mantido por outra thread, e ambas ficam bloqueadas indefinidamente.

Para evitar o deadlock, uma estratégia comum é estabelecer uma ordem fixa para a aquisição dos mutexes e garantir que todas as threads sigam essa ordem. Neste caso, a estratégia utilizada foi adquirir o mutex da conta de origem antes do mutex da conta de destino na função `transferir`. Isso cria uma ordem consistente de aquisição de mutexes em todas as partes do código que chamam essa função.

```cpp
void transferir(ContaBancaria& origem, ContaBancaria& destino, double valor) {
    // Adquire o mutex da conta de origem primeiro
    std::unique_lock<std::mutex> lockOrigem(origem.obterMutexConta());

    // Em seguida, adquire o mutex da conta de destino
    std::unique_lock<std::mutex> lockDestino(destino.obterMutexConta());

    origem.sacar(valor);
    destino.depositar(valor);

    std::lock_guard<std::mutex> lockCout(mutexCout);
    std::wcout.imbue(std::locale(""));
    std::wcout << L"Transferência da Conta " << origem.obterNumeroConta() << L" para Conta " << destino.obterNumeroConta() << L": R$" << valor << std::endl;
}
```

Essa ordem consistente de aquisição de mutexes ajuda a evitar a situação em que uma thread adquire o mutex da conta A e aguarda pelo mutex da conta B, enquanto outra thread adquire o mutex da conta B e aguarda pelo mutex da conta A, prevenindo assim a ocorrência de deadlock.