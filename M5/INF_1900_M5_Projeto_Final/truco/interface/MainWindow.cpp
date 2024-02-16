#include "MainWindow.h"
#include "../interface/PathUtils.h"
#include "Player.h"

namespace ui {

	BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
		ON_COMMAND(2, OnButtonMsgClick)
		ON_COMMAND(256, OnButtonMsgClick2)
		ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()

	MainWindow::MainWindow()
	{		
		m_pViewModel = std::make_unique<MainWindowsViewModel>(this);
		Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
		//initTexturas();
		initComponentes();
	}

	MainWindow::~MainWindow()
	{

	}

	void MainWindow::initComponentes()
	{
		//Contador de Rodadas
		m_panelRodada = std::make_unique<CustomLabel>();
		m_panelRodada->Create(NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, CRect(0, 0, 100, 27), this);
		m_panelRodada->SetWindowText(L"Rodada: 0");
		m_panelRodada->setFontSize(20);		
		m_panelRodada->setTransparent(true);
		m_panelRodada->setForegroundColor(RGB(255,255,255));


		//Dialog
		m_dialog_builder = std::make_shared<DialogBuilder>(this);
		m_dialog = m_dialog_builder->WithDialogType(DialogType::Info)
			.WithMessage(L"Pronto para Jogar Truco?")
			.WithPosition((MAIN_WINDOW_WIDTH - DIALOG_WIDTH)/2, (MAIN_WINDOW_HEIGHT - DIALOG_HEIGHT) / 2)
			.WithOkButton([&]() {
					m_dialog->setVisible(false); 								
					m_pViewModel->iniciarJogo();					
				})			
			.WithVisible(true).build();
		
		m_dialog->draw();
	}

	void MainWindow::initTexturas()
	{		
		m_texturaFundo = std::make_shared<CStatic>();
		m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this);		
		PathUtils::loadImage(IMG_BACKGROUND, m_texturaFundo);		
	}

	void MainWindow::updateRodada()
	{
		std::wstring message = L"Rodada: " + std::to_wstring(m_pViewModel->getRodada());
	}

	void MainWindow::updateJogadores()
	{
		auto jogadores = m_pViewModel->getJogadores();

		m_players.clear();

		int index = 0;
		for (auto& jogador : jogadores) {
			std::shared_ptr<Player> player = JogadorToPlayerConverter::converter(&jogador);
			player->setParent(this);


			switch (index)
			{
				case 0: 
					player->move((MAIN_WINDOW_WIDTH - PLAY_WIDTH) / 2, MAIN_WINDOW_HEIGHT - (PLAY_HEIGHT + CARD_HEIGHT));
					break;
				case 1:
					player->move(10, MAIN_WINDOW_HEIGHT/ 2);
					break;

				default:
					break;
			}
			
			player->draw();

			index++;
			m_players.push_back(player);
		}

	}

	void MainWindow::OnButtonMsgClick()
	{
		
	}

	void MainWindow::OnButtonMsgClick2()
	{
	
	}

	void MainWindow::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (!m_dialog->isVisible()) {
			//Coloque aqui tudo o que deve executar apenas se a dialog não estiver visivel
		}

		m_dialog->LeftMouseButtonDown(point);
		CFrameWnd::OnLButtonDown(nFlags, point);
	}

	void MainWindow::update()
	{		
		//updateRodada();
		updateJogadores();
		
		//UpdateWindow();
	}
}