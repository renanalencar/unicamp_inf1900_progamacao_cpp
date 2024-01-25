#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
	ON_COMMAND(256, OnButtonMsgClick2)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

MainWindow::MainWindow() 
{	
	Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW , CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	initComponentes();

	m_carta = std::make_unique<Card>(this, Naipe::PAUS, CardValues::KING, 100, 100);	
	m_carta->draw();

	bbutton = new BaseButton(this, 300, 200, TypeButton::MesaTruco);
	bbutton->draw();
	bbutton->OnLeftMouseButtonDownHandle = [&](int x, int y) {buttonOnclick(x, y); };
}

void MainWindow::initComponentes()
{	
	initTexturas();

	m_texto = std::make_shared<CustomLabel>();
	m_texto->Create(nullptr, WS_CHILD | WS_VISIBLE , CRect(500, 10, 650, 30), this);
	m_texto->SetWindowText(L"Texto Transparente");
	m_texto->setFontSize(30);
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

void MainWindow::buttonOnclick(int x, int y)
{
	m_carta->getViewModel()->move(100, 100);
}

void MainWindow::OnButtonMsgClick()
{	
	m_carta->getViewModel()->move(500, 500);
}

void MainWindow::OnButtonMsgClick2()
{		
	m_carta->getViewModel()->turn();
}

void MainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
	bbutton->LeftMouseButtonDown(point);
	m_carta->LeftMouseButtonDown(point);
	CFrameWnd::OnLButtonDown(nFlags, point);
}
