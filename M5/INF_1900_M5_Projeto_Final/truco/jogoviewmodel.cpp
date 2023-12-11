/**
 * @file jogoviewmodel.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include "jogoviewmodel.hpp"

// ViewModel simplificada para interagir entre a l�gica do Jogo e a interface do usu�rio
JogoViewModel::JogoViewModel(Jogo& jogo) : jogo(jogo) {}

void JogoViewModel::iniciarJogo() {
	jogo.iniciarJogo();
	exibirMensagem("Jogo iniciado!");
}

void JogoViewModel::jogarRodada() {
	jogo.jogarRodada();
	exibirMensagem("Rodada jogada!");
}

// M�todos para intera��o com a interface do usu�rio, por exemplo:
void JogoViewModel::exibirMensagem(const std::string& mensagem) const {
	std::cout << mensagem << std::endl;
}