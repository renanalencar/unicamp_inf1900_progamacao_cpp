#include "MainWindow.h"
#include "../interface/PathUtils.h"

namespace ui {

	BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
		ON_COMMAND(2, OnButtonMsgClick)
		ON_COMMAND(256, OnButtonMsgClick2)
		ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()

	MainWindow::MainWindow()
	{		
		Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));

		initComponentes();
		jogo = std::make_unique<Jogo>();		
	}

	MainWindow::~MainWindow()
	{

	}

	void MainWindow::initComponentes()
	{
		initTexturas();

		//Contador de Rodadas
		m_panelRodada = std::make_unique<CustomLabel>();
		m_panelRodada->Create(NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, CRect(0, 0, 100, 200), this);
		m_panelRodada->SetWindowText(L"Rodada: 3");
		m_panelRodada->setFontSize(20);		
		m_panelRodada->setTransparent(true);
		m_panelRodada->setForegroundColor(RGB(255,255,255));
	}

	void MainWindow::initTexturas()
	{		
		m_texturaFundo = std::make_shared<CStatic>();
		m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this, ID_IMG_FUNDO);
		PathUtils::loadImage(IMG_BACKGROUND, m_texturaFundo);		
	}

	void MainWindow::OnButtonMsgClick()
	{
		jogo->iniciarJogo();
	}

	void MainWindow::OnButtonMsgClick2()
	{
	
	}

	void MainWindow::OnLButtonDown(UINT nFlags, CPoint point)
	{
	
	}
}