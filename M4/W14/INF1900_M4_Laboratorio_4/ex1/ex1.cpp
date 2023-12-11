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
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <locale>
#include "ex1_exemplo.cpp"  // Incluindo o código do pool de threads

using Matrix = std::vector<std::vector<float>>;

Matrix multiplyMatricesParallel(const Matrix& A, const Matrix& B, thread_pool& pool) {
	int rowsA = A.size();
	int colsA = A[0].size();
	int rowsB = B.size();
	int colsB = B[0].size();

	if (colsA != rowsB) {
		std::cerr << "Erro: As matrizes não podem ser multiplicadas!" << std::endl;
		exit(EXIT_FAILURE);
	}

	Matrix result(rowsA, std::vector<float>(colsB, 0.0));

	// Função para calcular uma linha da matriz resultante de forma paralela
	auto multiplyRow = [&](int i) {
		for (int j = 0; j < colsB; j++) {
			for (int k = 0; k < colsA; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
		};

	// Enfileirar as tarefas para multiplicar cada linha de forma paralela
	for (int i = 0; i < rowsA; i++) {
		pool.submit([=, &multiplyRow]() { multiplyRow(i); });
	}

	// Aguardar a conclusão de todas as tarefas
	pool.~thread_pool();

	return result;
}

Matrix generateMatrix(int rows, int cols) {
	Matrix mat(rows, std::vector<float>(cols));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat[i][j] = static_cast<float>(rand()) / RAND_MAX; // Gera um número float entre 0 e 1
		}
	}
	return mat;
}

Matrix multiplyMatricesSerial(const Matrix& A, const Matrix& B) {
	int rowsA = A.size();
	int colsA = A[0].size();
	int rowsB = B.size();
	int colsB = B[0].size();

	if (colsA != rowsB) {
		std::cerr << "Erro: As matrizes não podem ser multiplicadas!" << std::endl;
		exit(EXIT_FAILURE);
	}

	Matrix result(rowsA, std::vector<float>(colsB, 0.0));

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
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	// Configuração da localização para lidar com acentuação
	std::locale::global(std::locale("pt_BR.UTF8"));

	srand(time(nullptr));

	// Gerar datasets de entrada com tamanhos diferentes
	Matrix A = generateMatrix(100, 100);
	Matrix B = generateMatrix(100, 100);

	// Multiplicação serial de matrizes
	auto start_serial = std::chrono::high_resolution_clock::now();
	Matrix C_serial = multiplyMatricesSerial(A, B);
	auto end_serial = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_serial = end_serial - start_serial;

	std::cout << "Resultado da multiplicação serial:" << std::endl;
	printMatrix(C_serial);
	std::cout << "Tempo serial: " << duration_serial.count() << " segundos" << std::endl;

	// Multiplicação paralela de matrizes usando o pool de threads
	auto start_parallel = std::chrono::high_resolution_clock::now();

	// Criar o pool de threads
	thread_pool pool;

	// Multiplicar as matrizes de forma paralela
	Matrix C_parallel = multiplyMatricesParallel(A, B, pool);

	auto end_parallel = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_parallel = end_parallel - start_parallel;

	std::cout << "Resultado da multiplicação paralela:" << std::endl;
	printMatrix(C_parallel);

	std::cout << "Tempo paralelo: " << duration_parallel.count() << " segundos" << std::endl;

	// Calcular e imprimir o speedup
	double speedup = duration_serial.count() / duration_parallel.count();
	std::cout << "Speedup: " << speedup << std::endl;

	// Verificar se as matrizes são iguais (com uma margem de erro)
	const double epsilon = 1e-5;  // Margem de erro permitida
	bool matricesEqual = true;

	// Comparar as matrizes C_serial e C_parallel
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (abs(C_serial[i][j] - C_parallel[i][j]) > epsilon) {
				matricesEqual = false;
				break;  // Se um elemento estiver fora da margem de erro, não é necessário verificar o restante
			}
		}
		if (!matricesEqual) {
			break;  // Se um elemento estiver fora da margem de erro, não é necessário verificar o restante das linhas
		}
	}

	if (matricesEqual) {
		std::cout << "As matrizes são iguais dentro da margem de erro." << std::endl;
	}
	else {
		std::cout << "Erro: As matrizes não são iguais." << std::endl;
	}



	if (matricesEqual) {
		std::cout << "As matrizes são iguais dentro da margem de erro." << std::endl;
	}
	else {
		std::cout << "Erro: As matrizes não são iguais." << std::endl;
	}

	system("pause");

	return 0;
}
