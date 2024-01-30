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

	bbutton = new BaseButton(this, 300, 200, TypeButton::PlayerTruco);
	bbutton->draw();
	bbutton->OnLeftMouseButtonDownHandle = [&](int x, int y) {buttonOnclick(x, y); };


	DialogBuilder builder(this);
	m_dialog = builder.WithMessage(L"AAAAAAAAAAAAAA bbbbbbbbbbbbb \n cccccccccccccc dddddddddddddd eeeeeeeeeeeeeee")
					  .WithDialogType(DialogType::Truco)
					  .WithPosition(0, ((int)MAIN_WINDOW_HEIGHT / 2))
				      //.WithAceitarButton([&]() {m_texto->SetWindowText(L"deu certo");})
					  .WithRecusarButton([&]() {m_texto->SetWindowText(L"deu certo de novo"); })
					  .WithPedirButton([&]() {m_dialog->setVisible(false); })
					  .build();

	m_dialog->draw();
}

void MainWindow::initComponentes()
{	
	initTexturas();

	m_texto = std::make_shared<CustomLabel>();
	m_texto->Create(nullptr, WS_CHILD | WS_VISIBLE | SS_LEFT , CRect(500, 10, 650, 30), this);
	m_texto->SetWindowText(L"Texto Transparente ccccccccccccc bbbbbbbbbbbbbbbbbbbbb");
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
	//m_carta->getViewModel()->move(100, 100);
	
	m_dialog->setVisible(!m_dialog->isVisible());
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
	if (!m_dialog->isVisible()) {
		bbutton->LeftMouseButtonDown(point);
		m_carta->LeftMouseButtonDown(point);
	}

	m_dialog->LeftMouseButtonDown(point);
	CFrameWnd::OnLButtonDown(nFlags, point);
}
