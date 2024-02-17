/**
 * @file jogo.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */
#include "jogo.hpp"

Jogo::Jogo() : baralho(), rodadaAtual(0), pontosJogador1(0), pontosJogador2(0) {
	// Adicione os jogadores ao jogo (aqui assumimos dois jogadores)
	jogadores.emplace_back("Jogador 1");
	jogadores.emplace_back("Jogador 2");
	jogadores.emplace_back("Jogador 3");
	jogadores.emplace_back("Jogador 4");
}

void Jogo::iniciarJogo() {
	std::cout << "Iniciando jogo de truco!" << std::endl;
	baralho.embaralhar();

	// Distribuir cartas aos jogadores
	for (Jogador& jogador : jogadores) {
		for (int i = 0; i < 3; ++i) {
			jogador.adicionarCarta(baralho.distribuirCarta());
		}
	}
}

void Jogo::jogarRodada() {
	std::cout << "Iniciando rodada " << rodadaAtual + 1 << std::endl;

	// Exibir as cartas dos jogadores
	for (const Jogador& jogador : jogadores) {
		jogador.exibirCartas();
	}

	Carta _manilha = baralho.distribuirCarta();
	manilha = std::make_shared<Carta>(_manilha);

	// Lógica da rodada (aqui você pode adicionar a lógica específica do truco)
	std::vector<Carta> cartasJogadas;

	// Cada jogador faz um lance (simplificado para escolher a primeira carta)
	for (Jogador& jogador : jogadores) {
		Carta cartaJogada = jogador.fazerLance();
		cartasJogadas.push_back(cartaJogada);
	}

	// Identificar o vencedor da rodada (simplificado para a carta mais alta)
	auto cartaVencedora = *std::max_element(cartasJogadas.begin(), cartasJogadas.end(),
		[](const Carta& carta1, const Carta& carta2) {
			return carta1.getValor() < carta2.getValor();
		});

	// Exibir resultado da rodada
	std::cout << "Carta vencedora: ";
	cartaVencedora.exibirCarta();
	std::cout << std::endl;

	// Atualizar pontos (aqui você pode adicionar lógica específica do truco)
	if (jogadores[0].possuiCarta(cartaVencedora)) {
		pontosJogador1++;
	}
	else if (jogadores[1].possuiCarta(cartaVencedora)) {
		pontosJogador2++;
	}

	// Exibir pontuação
	std::cout << "Pontuação: " << jogadores[0].getNome() << " - " << pontosJogador1
		<< ", " << jogadores[1].getNome() << " - " << pontosJogador2 << std::endl;

	// Incrementar o número da rodada
	rodadaAtual++;
}

int Jogo::getRodadaAtual()
{
	return rodadaAtual;
}

std::shared_ptr<Carta> Jogo::getManilha()
{
	return manilha;
}

std::vector<Jogador> Jogo::getJogadores()
{
	return jogadores;
}

// Adicione mais métodos conforme necessário para a lógica do jogo