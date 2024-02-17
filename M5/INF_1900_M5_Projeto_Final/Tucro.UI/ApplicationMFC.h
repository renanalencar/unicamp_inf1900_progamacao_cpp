#pragma once
#include <afxwin.h>
#include "MainWindow.h"


class ApplicationMFC : public CWinApp{

private:
	MainWindow* m_MainWindow;

public:
	virtual BOOL InitInstance();


};