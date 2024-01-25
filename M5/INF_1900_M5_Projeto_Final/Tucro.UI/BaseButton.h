#pragma once
#include <afxwin.h>
#include <memory>

#include "PathUtils.h"
#include "AssetsConstants.h"

class BaseButton : public CStatic
{
private:
	const int BUTTON_WIDTH = 120;
	const int BUTTON_HEIGHT = 44;

public:	
	

	virtual BOOL Create(DWORD dwStyle,int x, int y, CWnd* pParentWnd, UINT nID = 0xffff);
	
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

