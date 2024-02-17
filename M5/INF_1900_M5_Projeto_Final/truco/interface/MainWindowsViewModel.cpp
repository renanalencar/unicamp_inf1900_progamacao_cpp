#include "MainWindowsViewModel.h"

namespace ui {
	MainWindowsViewModel::MainWindowsViewModel(BaseView<MainWindowsViewModel>* view)
		: BaseViewModel<MainWindowsViewModel>(view, 0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT)
	{
		m_jogo = std::make_unique<Jogo>();
	}

	void MainWindowsViewModel::iniciarJogo()
	{
		m_jogo->iniciarJogo();
		m_pView->update();
	}

	void MainWindowsViewModel::jogarRodada()
	{
		m_jogo->jogarRodada();
		m_pView->update();
	}
	int MainWindowsViewModel::getRodada()
	{
		return m_jogo->getRodadaAtual();
	}
	std::vector<Jogador> MainWindowsViewModel::getJogadores()
	{
		return m_jogo->getJogadores();
	}
	std::shared_ptr<Carta> MainWindowsViewModel::getManilha()
	{
		return m_jogo->getManilha();
	}
}