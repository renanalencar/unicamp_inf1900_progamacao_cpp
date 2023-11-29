/**
 * @file ex4.cpp
 *
 * @brief Exercício 4.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include <future>

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Função paralela para ordenar uma parte do vetor
void mergeSortParallel(std::vector<int>& arr, int l, int r, int profundidade) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Limite de profundidade para criar tarefas assíncronas
        if (profundidade > 0) {
            auto fut1 = std::async(std::launch::async, mergeSortParallel, std::ref(arr), l, m, profundidade - 1);
            auto fut2 = std::async(std::launch::async, mergeSortParallel, std::ref(arr), m + 1, r, profundidade - 1);

            fut1.wait();
            fut2.wait();
        }
        else {
            // Se a profundidade atingir o limite, alternar para a versão serial
            mergeSortParallel(arr, l, m, 0);
            mergeSortParallel(arr, m + 1, r, 0);
        }

        merge(arr, l, m, r);
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    std::cout << "Array antes da ordenação:" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Profundidade limitada a 2 para criar até 2^2 = 4 threads
    mergeSortParallel(arr, 0, arr.size() - 1, 2);

    std::cout << "Array após a ordenação:" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
