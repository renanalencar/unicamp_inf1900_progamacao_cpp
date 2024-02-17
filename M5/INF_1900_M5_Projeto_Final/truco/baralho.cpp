/**
 * @file baralho.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include <random>
#include "baralho.hpp"

Baralho::Baralho() {
	// Inicializa o baralho com cartas
	for (int valor = 1; valor <= 12; ++valor) {

		//cartas removidas do Truco Paulista
		if (valor >= 8 && valor <= 10) {
			continue;
		}

		for (const std::string& naipe : naipes) {
			cartas.emplace_back(valor, naipe);
		}
	}

	// Embaralha o baralho
	embaralhar();
}

void Baralho::embaralhar() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cartas.begin(), cartas.end(), g);
	indiceCartaAtual = 0;
}

Carta Baralho::distribuirCarta() {
	if (indiceCartaAtual < cartas.size()) {
		return cartas[indiceCartaAtual++];
	}
	else {
		std::cerr << "O baralho está vazio!" << std::endl;
		// Pode ser útil lidar com essa situação de forma adequada ao seu jogo
		return Carta(0, "Vazio");
	}
}