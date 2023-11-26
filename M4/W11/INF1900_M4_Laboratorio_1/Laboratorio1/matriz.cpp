/**
 * @file matriz.cpp
 *
 * @brief Classe que representa a matriz.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include "matriz.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;
 
class matriz {
public:

    void getMatriz() {
        srand(time(nullptr));

        // Gerar datasets de entrada com tamanhos diferentes
        Matrix A1 = generateMatrix(100, 100);
        Matrix B1 = generateMatrix(100, 100);

        // Multiplicar as matrizes e imprimir os resultados
        //cout << "Resultado da multiplicação do primeiro dataset:" << endl;
        
        // Obter o tempo inicial
        auto start = std::chrono::high_resolution_clock::now();
        Matrix C1 = multiplyMatrices(A1, B1);
        // Obter o tempo final
        auto end = std::chrono::high_resolution_clock::now();
        // Calcular o tempo de execução
        auto duration = end - start;
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        // Imprimir o tempo de execução
        std::cout << "O tempo de execução do metodo sincrono e: " << milliseconds.count() << " milissegundos" << std::endl;


        Matrix C2(A1.size(), vector<float>(B1[0].size(), 0.0));
        // Obter o tempo inicial
        start = std::chrono::high_resolution_clock::now();
        multiplyMatricesParallel(A1, B1, C2);
        // Obter o tempo final
        end = std::chrono::high_resolution_clock::now();
        // Calcular o tempo de execução
        duration = end - start;
        milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        // Imprimir o tempo de execução
        std::cout << "O tempo de execução do metodo asincrono e: " << milliseconds.count() << " milissegundos" << std::endl;
       
    }
private:
    typedef vector<vector<float>> Matrix;
   
    struct WorkerArgs {
        const Matrix& A;
        const Matrix& B;
        Matrix& result;
        int rowStart;
        int rowEnd;
        int col;
    };

    void worker(const WorkerArgs& args) {
        for (int i = args.rowStart; i < args.rowEnd; ++i) {
            for (int k = 0; k < args.A.size(); ++k) {
                args.result[i][args.col] += args.A[i][k] * args.B[k][args.col];
            }
        }
    }

    Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
        int rowsA = A.size();
        int colsA = A[0].size();
        int rowsB = B.size();
        int colsB = B[0].size();

        if (colsA != rowsB) {
            cerr << "Erro: As matrizes não podem ser multiplicadas!" << endl;
            exit(EXIT_FAILURE);
        }

        Matrix result(rowsA, vector<float>(colsB, 0.0));

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return result;
    }

    void printMatrix(const Matrix& mat) {
        for (const auto& row : mat) {
            for (float val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    Matrix generateMatrix(int rows, int cols) {
        Matrix mat(rows, vector<float>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Gera um número float entre 0 e 1
                mat[i][j] = static_cast<float>(rand()) / RAND_MAX;
            }
        }
        return mat;
    }

    void multiplyMatricesParallel(const Matrix& A, const Matrix& B, Matrix& result) {
        int rowsA = A.size();
        int colsA = A[0].size();
        int rowsB = B.size();
        int colsB = B[0].size();

        if (colsA != rowsB) {
            cerr << "Erro: As matrizes não podem ser multiplicadas!" << endl;
            exit(EXIT_FAILURE);
        }

        // Determine the number of threads to use
        int numThreads = thread::hardware_concurrency();

        // Divide the work among the threads
        vector<thread> threads;
        for (int col = 0; col < colsB; ++col) {
            int rowsPerThread = rowsA / numThreads;
            int remainder = rowsA % numThreads;

            for (int threadId = 0; threadId < numThreads; ++threadId) {
                int rowStart = threadId * rowsPerThread;
                int rowEnd = rowStart + rowsPerThread;

                if (threadId == numThreads - 1) {
                    rowEnd += remainder;
                }

                // Create a worker argument structure
                WorkerArgs args = {
                  A, B, result, rowStart, rowEnd, col
                };

                // Create and start a thread to perform the multiplication
                threads.emplace_back(&matriz::worker, this, args);
            }
        }

        // Wait for all threads to finish
        for (thread& thread : threads) {
            thread.join();
        }
    } 
};