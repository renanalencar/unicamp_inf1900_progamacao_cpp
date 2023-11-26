/**
 * @file ex3.cpp
 *
 * @brief Exercício 3.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */
 
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

using Matrix = vector<vector<float>>;

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

Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
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

void printMatrix(const Matrix &mat) {
  for (const auto &row : mat) {
    for (float val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

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

Matrix multiplyMatricesConcurrent(const Matrix& A, const Matrix& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    if (colsA != rowsB) {
        cerr << "Erro: As matrizes não podem ser multiplicadas!" << endl;
        exit(EXIT_FAILURE);
    }

    Matrix result(rowsA, vector<float>(colsB, 0.0));

    int numThreads = std::thread::hardware_concurrency();

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

            WorkerArgs args = {
              A, B, result, rowStart, rowEnd, col
            };

            threads.emplace_back(worker, args);
        }
    }

    for (thread& thread : threads) {
        thread.join();
    }

    return result;
}

int run() {
  srand(time(nullptr));

  // Gerar datasets de entrada com tamanhos diferentes
  Matrix A1 = generateMatrix(100, 100);
  Matrix B1 = generateMatrix(100, 100);

  // Multiplicar as matrizes e imprimir os resultados
  cout << "Resultado da multiplicação do primeiro dataset:" << endl;
  Matrix C1 = multiplyMatricesConcurrent(A1, B1);
  printMatrix(C1);

  return 0;
}
