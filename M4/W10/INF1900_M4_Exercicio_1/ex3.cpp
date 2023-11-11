#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<float>> Matrix;

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

int main() {
  srand(time(nullptr));

  // Gerar datasets de entrada com tamanhos diferentes
  Matrix A1 = generateMatrix(100, 100);
  Matrix B1 = generateMatrix(100, 100);

  // Multiplicar as matrizes e imprimir os resultados
  cout << "Resultado da multiplicação do primeiro dataset:" << endl;
  Matrix C1 = multiplyMatrices(A1, B1);
  printMatrix(C1);

  return 0;
}
