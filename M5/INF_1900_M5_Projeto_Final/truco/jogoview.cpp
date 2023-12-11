/**
 * @file jogoview.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include "jogoview.hpp"

// Classe JogoView simplificada para interagir com o usuário via linha de comando
JogoView::JogoView(JogoViewModel& viewModel) : viewModel(viewModel) {}

void JogoView::iniciar() {
	int opcao;
	do {
		exibirMenu();
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;

		processarOpcao(opcao);
	} while (opcao != 0);
}

void JogoView::exibirMenu() const {
	std::cout << "\n=== Menu ===" << std::endl;
	std::cout << "1. Iniciar Jogo" << std::endl;
	std::cout << "2. Jogar Rodada" << std::endl;
	std::cout << "0. Sair" << std::endl;
}

void JogoView::processarOpcao(int opcao) {
	switch (opcao) {
	case 1:
		viewModel.iniciarJogo();
		break;
	case 2:
		viewModel.jogarRodada();
		break;
	case 0:
		std::cout << "Saindo do jogo. Até mais!\n";
		break;
	default:
		std::cout << "Opção inválida. Tente novamente.\n";
		break;
	}
}