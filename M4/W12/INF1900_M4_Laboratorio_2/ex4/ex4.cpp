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
#include <thread>
#include <mutex>
#include <locale>

std::mutex mergeMutex;

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

void parallelMergeSort(std::vector<int>& arr, int l, int r, int depth) {
    if (l < r) {
        int m = l + (r - l) / 2;

        if (depth > 0) {
            std::thread leftThread(parallelMergeSort, std::ref(arr), l, m, depth - 1);
            std::thread rightThread(parallelMergeSort, std::ref(arr), m + 1, r, depth - 1);

            leftThread.join();
            rightThread.join();
        }
        else {
            parallelMergeSort(arr, l, m, depth);
            parallelMergeSort(arr, m + 1, r, depth);
        }

        std::lock_guard<std::mutex> lock(mergeMutex);
        merge(arr, l, m, r);
    }
}

int main() {
    // Configuração da localização para lidar com acentuação
    std::locale::global(std::locale("pt_BR.UTF8"));

    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    std::cout << "Array antes da ordenação:" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int numThreads = 2;  // Defina o número desejado de threads
    parallelMergeSort(arr, 0, arr.size() - 1, numThreads);

    std::cout << "Array após a ordenação:" << std::endl;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    system("pause");

    return 0;
}
