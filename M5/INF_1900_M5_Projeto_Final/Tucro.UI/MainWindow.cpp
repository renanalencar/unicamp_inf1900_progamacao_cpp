#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
END_MESSAGE_MAP()

#define IDC_IMAGE_CONTROL 1
#define IDC_VIEW 115

MainWindow::MainWindow() 
{	
	Create(nullptr, L"Truco", WS_OVERLAPPEDWINDOW, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	initComponentes();
}

void MainWindow::initComponentes()
{
	initTexturas();

	pImage.Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(10, 10, 800, 600), this, IDC_VIEW);

	CStatic* pImageControl;
	pImageControl = (CStatic*)GetDlgItem(IDC_VIEW);
	
	CString filePath2 = "D:/Downloads/CPP_321_EXE_MFC_GUI_RPG_Game_Hills_of_Darkness_ver3/media/center.bmp";

	HBITMAP IntroPix = (HBITMAP)LoadImage(NULL, filePath2, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (IntroPix) {				
		pImage.SetBitmap(IntroPix);
	}
	else
	{
		AfxMessageBox(_T("Falha ao carregar a imagem."), MB_OK);
	}
}

void MainWindow::initTexturas()
{
	m_texturaFundo = std::make_shared<CStatic>();
	m_texturaFundo->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), this, ID_IMG_FUNDO);

	PathUtils::loadImage(IMG_FUNDO, m_texturaFundo);

}



void MainWindow::OnButtonMsgClick()
{	
	AfxMessageBox(L"Teste");
}

