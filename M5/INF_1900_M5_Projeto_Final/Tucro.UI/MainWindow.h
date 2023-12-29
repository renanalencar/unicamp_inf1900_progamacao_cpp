#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <atlimage.h>

#include "CustomWindow.h"
class MainWindow :  public CustomWindow
{
protected:
	CBitmap bitmap;
	CStatic pImage;


public:
	MainWindow();
	// Inherited via CustomWindow
	void initComponents() override;
	afx_msg void OnButtonMsgClick();

	DECLARE_MESSAGE_MAP();

	// Inherited via CustomWindow
	void show() override;
	void update() override;
};

