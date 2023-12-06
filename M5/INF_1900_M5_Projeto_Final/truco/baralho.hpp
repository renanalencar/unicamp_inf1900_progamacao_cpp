/**
 * @file baralho.hpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "carta.hpp"

class Baralho {
public:
	Baralho();

	void embaralhar();

	Carta distribuirCarta();

private:
	std::vector<Carta> cartas;
	int indiceCartaAtual;
	const std::vector<std::string> naipes = { "Copas", "Espadas", "Ouros", "Paus" };
};

