#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
	ON_COMMAND(2, OnButtonMsgClick)
END_MESSAGE_MAP()

#define IDC_IMAGE_CONTROL 1
#define IDC_VIEW 115

MainWindow::MainWindow() : CustomWindow(0,0,1024,780)
{	

	pImage.Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(10, 10, 800, 600), this, IDC_VIEW);

	CStatic* pImageControl;
	pImageControl = (CStatic*) GetDlgItem(IDC_VIEW);

	CString filePath = "F:/Documentos/Cursos/Curso_c_plus_plus/Trabalhofinal/unicamp_inf1900_progamacao_cpp/M5/INF_1900_M5_Projeto_Final/Tucro.UI/assests/paus.bmp";
	CString filePath2 = "D:/Downloads/CPP_321_EXE_MFC_GUI_RPG_Game_Hills_of_Darkness_ver3/media/center.bmp";

	HBITMAP IntroPix = (HBITMAP)LoadImage(NULL, filePath2, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (IntroPix) {
		CImage image;
		image.Load(filePath2);
		//pImage.ModifyStyle(SS_ENHMETAFILE, SS_BITMAP);
		pImage.SetBitmap((HBITMAP)image.Detach());
	}
	else
	{
		AfxMessageBox(_T("Falha ao carregar a imagem."), MB_OK);
	}

	/*
	CImage image;
	if (image.Load(filePath) == S_OK)
	{
		//CStatic* pImageControl = (CStatic*)GetDlgItem(IDC_IMAGE_CONTROL); // Substitua IDC_STATIC_IMAGEM pelo ID do seu controle de imagem
		if (pImageControl)
		{
			//pImageControl.SetBitmap((HBITMAP)image.Detach()); // Define a imagem no controle
			//pImage.SetBitmap((HBITMAP)image.Detach());
			pImageControl->SetBitmap(IntroPix);
		}
	}
	else
	{
		AfxMessageBox(_T("Falha ao carregar a imagem."), MB_OK);
	}
	*/
}

void MainWindow::initComponents() 
{
	CustomWindow::initComponents();	
}



void MainWindow::OnButtonMsgClick()
{	
	AfxMessageBox(L"Teste");
}

void MainWindow::show()
{
}

void MainWindow::update()
{
}
