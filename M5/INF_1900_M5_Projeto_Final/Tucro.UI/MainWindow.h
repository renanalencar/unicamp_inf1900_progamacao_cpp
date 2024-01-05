#pragma once
#include <memory>
#include <afxwin.h>
#include <afxext.h>

#include "PathUtils.h"
#include "AssetsConstants.h"


class MainWindow : public CFrameWnd
{

private:
	
	const unsigned short int ID_IMG_FUNDO = 1;

	const unsigned short int MAIN_WINDOW_WIDTH = 1024;
	const unsigned short int MAIN_WINDOW_HEIGHT = 780;

	std::shared_ptr<CStatic> m_texturaFundo;
	
	void initComponentes();
	void initTexturas();

protected:
	CStatic pImage;

public:
	MainWindow();
	
	afx_msg void OnButtonMsgClick();

	DECLARE_MESSAGE_MAP();	
};

