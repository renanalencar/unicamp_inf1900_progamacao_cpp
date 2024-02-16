/**
 * @file carta.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#pragma once
#include <iostream>
#include <string>

const std::string PAUS = "Paus";
const std::string OUROS = "Ouros";
const std::string ESPADAS = "Espadas";
const std::string COPAS = "Copas";

class Carta
{
public:
	Carta(int valor, const std::string& naipe);

	// Métodos getter para valor e naipe
	int getValor() const;

	std::string getNaipe() const;

	// Exibe a carta
	void exibirCarta() const;

private:
	int valor;
	std::string naipe;
};

