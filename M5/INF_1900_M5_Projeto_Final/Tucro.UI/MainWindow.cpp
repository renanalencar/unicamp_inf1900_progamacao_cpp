#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
END_MESSAGE_MAP()

#define IDC_IMAGE_CONTROL 1
#define IDC_VIEW 115

MainWindow::MainWindow() 
{	
	Create(NULL, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	initComponentes();

	m_carta = std::make_unique<Carta>(this, Naipe::PAUS, CartaValor::KING, 100, 100);
	m_carta->draw();
	
	//_buttonMsg.Create(_T("Message"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 100, 45), this, 2);
}

void MainWindow::initComponentes()
{	
	initTexturas();

}

void MainWindow::initTexturas()
{
	m_texturaFundo = std::make_shared<CStatic>();
	m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this, ID_IMG_FUNDO);

	//HBITMAP textura = (HBITMAP)LoadImage(NULL, L"F:/Documentos/Cursos/Curso_c_plus_plus/Trabalhofinal/unicamp_inf1900_progamacao_cpp/M5/INF_1900_M5_Projeto_Final/Tucro.UI/assets/c_paus.bmp", IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	//m_texturaFundo->SetBitmap(textura);
	PathUtils::loadImage(IMG_BACKGROUND, m_texturaFundo);


}

void MainWindow::OnButtonMsgClick()
{	
	AfxMessageBox(L"Teste");
}

