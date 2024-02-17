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
		initTexturas();
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
					m_pViewModel->iniciarJogo();					
				})			
			.WithAceitarButton([&]() {
					m_pViewModel->jogarRodada();
					m_dialog->setVisible(false);
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

	void MainWindow::updateManilha()
	{
		Carta* carta = m_pViewModel->getManilha().get();
		if (carta != nullptr) {
			m_manilha = CartaToCardConverter::converter( m_pViewModel->getManilha().get());
			m_manilha->setParent(this);
			m_manilha->draw();
			m_manilha->move(CARD_WIDTH / 2, MAIN_WINDOW_HEIGHT - PLAY_HEIGHT - CARD_HEIGHT / 2);
		}
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
					player->move((MAIN_WINDOW_WIDTH - PLAY_WIDTH) / 2, MAIN_WINDOW_HEIGHT - PLAY_HEIGHT - CARD_HEIGHT/2);
					break;
				case 1:
					player->move(CARD_WIDTH / 2, (MAIN_WINDOW_HEIGHT - CARD_HEIGHT - PLAY_HEIGHT) / 2);
					break;
				case 2:
					player->move((MAIN_WINDOW_WIDTH - PLAY_WIDTH) / 2, PLAY_HEIGHT - CARD_HEIGHT);
					break;
				case 3:
					player->move(MAIN_WINDOW_WIDTH - (CARD_WIDTH/2 + PLAY_WIDTH), (MAIN_WINDOW_HEIGHT - CARD_HEIGHT - PLAY_HEIGHT) / 2);
					break;
				default:
					break;
			}
			
			player->draw();

			index++;
			m_players.push_back(player);
		}

	}

	void MainWindow::updateCartasJogadas()
	{
		auto cartasJogadas = m_pViewModel->getCartasJogadas();

		int index = 0;
		m_cartasJogadas.clear();
		for (auto& carta : cartasJogadas) {
			std::shared_ptr<Card> card = CartaToCardConverter::converter(&carta);
			card->setParent(this);
			card->draw();

			switch (index)
			{
			case 0:
				card->move(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT - (PLAY_HEIGHT + CARD_HEIGHT));
				break;
			case 1:
				card->move(10, MAIN_WINDOW_HEIGHT / 2);
				break;
			case 2:
				card->move(10, MAIN_WINDOW_HEIGHT / 2);
				break;
			case 3:
				card->move(10, MAIN_WINDOW_HEIGHT / 2);
				break;

			default:
				break;
			}
			m_cartasJogadas.push_back(card);
			index++;
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
		updateManilha();
		updateCartasJogadas();
		
	}
}