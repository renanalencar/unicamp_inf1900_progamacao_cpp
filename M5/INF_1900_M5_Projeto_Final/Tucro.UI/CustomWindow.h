#pragma once
#include <afxwin.h>

class CustomWindow :  public CFrameWnd
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	CustomWindow(int x, int y, int width, int height);
	virtual void initComponents();
};

