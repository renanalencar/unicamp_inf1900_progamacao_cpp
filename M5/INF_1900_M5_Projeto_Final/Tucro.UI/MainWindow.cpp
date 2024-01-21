#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
	ON_COMMAND(256, OnButtonMsgClick2)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

#define IDC_IMAGE_CONTROL 1
#define IDC_VIEW 115

MainWindow::MainWindow() 
{	
	Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	initComponentes();

	m_carta = std::make_unique<Card>(this, Naipe::PAUS, CardValues::KING, 100, 100);	
	m_carta->draw();
}

void MainWindow::initComponentes()
{	
	initTexturas();

	m_texto = std::make_shared<CustomLabel>();
	m_texto->Create(nullptr, WS_CHILD | WS_VISIBLE , CRect(500, 10, 650, 30), this, 999);
	m_texto->SetWindowText(L"Isabel de Souza Vieira Medeiros");	
	m_texto->setForegroundColor(RGB(0,255,0));
	m_texto->setBackgroundColor(RGB(0, 0, 0));
	m_texto->setTransparent(true);
}

void MainWindow::initTexturas()
{
	m_texturaFundo = std::make_shared<CStatic>();
	m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this, ID_IMG_FUNDO);
	PathUtils::loadImage(IMG_BACKGROUND, m_texturaFundo);	

	CButton* button = new CButton(); 
	button->Create(L"move", WS_CHILD | WS_VISIBLE | SS_LEFT, CRect(0, 0, 150, 50), this, 2);
}

void MainWindow::OnButtonMsgClick()
{	
//	AfxMessageBox(L"Teste");
	m_carta->getViewModel()->move(500, 500);
}

void MainWindow::OnButtonMsgClick2()
{
	//	AfxMessageBox(L"Teste");
	m_carta->getViewModel()->turn();
}

void MainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_carta->OnLeftMouseButtonDown(point);

	CFrameWnd::OnLButtonDown(nFlags, point);
}
