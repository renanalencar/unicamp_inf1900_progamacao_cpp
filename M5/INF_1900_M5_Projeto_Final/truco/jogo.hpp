/**
 * @file jogo.hpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#pragma once
#include <algorithm>
#include "baralho.hpp"
#include "jogador.hpp"

// Assume que as classes Carta e Jogador foram definidas anteriormente

class Jogo {
public:
	Jogo();

	void iniciarJogo();

	void jogarRodada();

	// Adicione mais métodos conforme necessário para a lógica do jogo
	int getRodadaAtual();
	std::shared_ptr<Carta> getManilha();
	std::vector<Jogador> getJogadores();
	std::vector<Carta> getCartasJogadas();

private:
	Baralho baralho;

	std::vector<Jogador> jogadores;	
	std::vector<Carta> cartasJogadas;
	std::shared_ptr<Carta> manilha;
	
	int rodadaAtual;
	int pontosJogador1;
	int pontosJogador2;
};
