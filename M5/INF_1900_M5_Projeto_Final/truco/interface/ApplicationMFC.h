#pragma once
#include <afxwin.h>
#include "MainWindow.h"
#include "../jogo.hpp"

namespace ui {

	class ApplicationMFC : public CWinApp{

	private:
		MainWindow* m_MainWindow;					
	public:
		virtual BOOL InitInstance();
	};
}