#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <atlimage.h>

#include "WindowMFC.h"
class MainWindow :  public WindowMFC
{
protected:
	CBitmap bitmap;
	CStatic pImage;


public:
	MainWindow();
	// Inherited via WindowMFC
	void initComponents() override;
	afx_msg void OnButtonMsgClick();

	DECLARE_MESSAGE_MAP();

	// Inherited via WindowMFC
	void show() override;
	void update() override;
};

