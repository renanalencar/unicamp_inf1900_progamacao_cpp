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
#include <numeric>
#include <execution>
#include <locale>

 // Definição da estrutura WeatherData
struct WeatherData {
	double temperature;
	double humidity;
	double windSpeed;
};

// Função para gerar um conjunto de dados fictícios
std::vector<WeatherData> generateWeatherData(int size) {
	std::vector<WeatherData> data;
	data.reserve(size);

	for (int i = 0; i < size; ++i) {
		WeatherData entry;
		entry.temperature = 20.0 + static_cast<double>(rand()) / RAND_MAX * 10.0;
		entry.humidity = 50.0 + static_cast<double>(rand()) / RAND_MAX * 20.0;
		entry.windSpeed = static_cast<double>(rand()) / RAND_MAX * 5.0;

		data.push_back(entry);
	}

	return data;
}

int main() {
	// Configuração da localização para lidar com acentuação
	std::locale::global(std::locale("pt_BR.UTF8"));

	// Gerar conjunto de dados fictícios
	std::vector<WeatherData> weatherData = generateWeatherData(10000);

	// Usar std::transform_reduce para calcular a média da temperatura
	double averageTemperature = std::transform_reduce(
		std::execution::par,  // Execução paralela se possível
		weatherData.begin(), weatherData.end(),  // Range de dados
		0.0,  // Valor inicial da soma
		std::plus<>(),  // Função de soma
		[](const WeatherData& data) -> double { return data.temperature; },  // Função de transformação
		[](const double sum, const double value) -> double { return sum + value; }  // Função de redução
	) / weatherData.size();  // Dividir pela quantidade de dados

	// Usar std::transform_reduce para calcular a média da umidade
	double averageHumidity = std::transform_reduce(
		std::execution::par, weatherData.begin(), weatherData.end(),
		0.0, std::plus<>(),
		[](const WeatherData& data) -> double { return data.humidity; },
		[](const double sum, const double value) -> double { return sum + value; }
	) / weatherData.size();

	// Usar std::transform_reduce para calcular a média da velocidade do vento
	double averageWindSpeed = std::transform_reduce(
		std::execution::par, weatherData.begin(), weatherData.end(),
		0.0, std::plus<>(),
		[](const WeatherData& data) -> double { return data.windSpeed; },
		[](const double sum, const double value) -> double { return sum + value; }
	) / weatherData.size();

	// Imprimir resultados
	std::cout << "Média da Temperatura: " << averageTemperature << std::endl;
	std::cout << "Média da Umidade: " << averageHumidity << std::endl;
	std::cout << "Média da Velocidade do Vento: " << averageWindSpeed << std::endl;

	return 0;
}
