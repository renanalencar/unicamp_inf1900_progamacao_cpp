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

// ViewModel simplificada para interagir entre a lógica do Jogo e a interface do usuário
JogoViewModel::JogoViewModel(Jogo& jogo) : jogo(jogo) {}

void JogoViewModel::iniciarJogo() {
	jogo.iniciarJogo();
	exibirMensagem("Jogo iniciado!");
}

void JogoViewModel::jogarRodada() {
	jogo.jogarRodada();
	exibirMensagem("Rodada jogada!");
}

// Métodos para interação com a interface do usuário, por exemplo:
void JogoViewModel::exibirMensagem(const std::string& mensagem) const {
	std::cout << mensagem << std::endl;
}