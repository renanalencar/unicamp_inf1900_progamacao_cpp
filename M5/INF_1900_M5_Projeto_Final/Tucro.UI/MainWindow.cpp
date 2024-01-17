#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
	ON_COMMAND(3, OnButtonMsgClick2)
END_MESSAGE_MAP()

#define IDC_IMAGE_CONTROL 1
#define IDC_VIEW 115

MainWindow::MainWindow() 
{	
	Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	initComponentes();

	m_carta = std::make_unique<Carta>(this, Naipe::PAUS, CartaValor::KING, 100, 100);	
}

void MainWindow::initComponentes()
{	
	initTexturas();

}

void MainWindow::initTexturas()
{
	m_texturaFundo = std::make_shared<CStatic>();
	m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this, ID_IMG_FUNDO);
	PathUtils::loadImage(IMG_BACKGROUND, m_texturaFundo);

	CButton* button = new CButton(); 
	button->Create(L"move", WS_CHILD | WS_VISIBLE | SS_LEFT, CRect(0, 0, 150, 50), this, 2);

	CButton* button2 = new CButton();
	button2->Create(L"virar", WS_CHILD | WS_VISIBLE | SS_LEFT, CRect(200, 0, 350, 50), this, 3);

}

void MainWindow::OnButtonMsgClick()
{	
//	AfxMessageBox(L"Teste");
	m_carta->getViewModel()->mover(500, 500);
}

void MainWindow::OnButtonMsgClick2()
{
	//	AfxMessageBox(L"Teste");
	m_carta->getViewModel()->virar();
}

