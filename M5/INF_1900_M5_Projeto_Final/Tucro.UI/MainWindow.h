#pragma once
#include <memory>
#include <afxwin.h>

#include "PathUtils.h"
#include "AssetsConstants.h"
#include "Card.h"
#include "CustomLabel.h"


class MainWindow : public CFrameWnd
{

private:
	
	const unsigned short int ID_IMG_FUNDO = 1;

	const unsigned short int MAIN_WINDOW_WIDTH = 1043;
	const unsigned short int MAIN_WINDOW_HEIGHT = 823;

	void initComponentes();
	void initTexturas();	

protected:	
	std::shared_ptr<CStatic> m_texturaFundo;
	std::unique_ptr<Card> m_carta;	
	std::shared_ptr<CustomLabel> m_texto;

public:
	MainWindow();
	
	afx_msg void OnButtonMsgClick();
	afx_msg void OnButtonMsgClick2();
	void OnLButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP();	
};




