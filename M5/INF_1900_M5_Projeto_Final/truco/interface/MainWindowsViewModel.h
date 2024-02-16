#pragma once
#include <memory>
#include "BaseViewModel.h"
#include "../jogo.hpp"

namespace ui {

	const int MAIN_WINDOW_WIDTH = 1043;
	const int MAIN_WINDOW_HEIGHT = 823;

	class MainWindowsViewModel : public ui::BaseViewModel<MainWindowsViewModel>
	{
	private:
		std::unique_ptr<Jogo> m_jogo;

	public:
		MainWindowsViewModel(BaseView<MainWindowsViewModel>* view);
		void iniciarJogo();
		void jogarRodada();
		int getRodada();
		std::vector<Jogador> getJogadores();
	};
}