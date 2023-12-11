/**
 * @file truco.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include <iostream>
#include <locale>
#include "jogo.hpp"
#include "jogoviewmodel.hpp"
#include "jogoview.hpp"

int main() {
	// Configuração da localização para lidar com acentuação
	std::locale::global(std::locale("pt_BR.UTF8"));

	Jogo jogo;
	JogoViewModel viewModel(jogo);
	JogoView jogoView(viewModel);

	jogoView.iniciar();

	system("pause");

	return 0;
}
