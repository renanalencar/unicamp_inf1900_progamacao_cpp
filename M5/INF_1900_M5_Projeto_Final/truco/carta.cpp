/**
 * @file carta.hpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include "carta.hpp"

Carta::Carta(int valor, const std::string& naipe) : valor(valor), naipe(naipe) {}

// Métodos getter para valor e naipe
int Carta::getValor() const {
	return valor;
}

std::string Carta::getNaipe() const {
	return naipe;
}

// Exibe a carta
void Carta::exibirCarta() const {
	std::cout << valor << " de " << naipe;
}