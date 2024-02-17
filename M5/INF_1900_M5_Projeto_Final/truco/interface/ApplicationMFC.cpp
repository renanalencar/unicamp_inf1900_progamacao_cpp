#include "ApplicationMFC.h"

namespace ui {
    BOOL ApplicationMFC::InitInstance()
    {
        m_MainWindow = new MainWindow();

        m_pMainWnd = m_MainWindow;
        m_pMainWnd->ShowWindow(SW_SHOW);
        m_pMainWnd->UpdateWindow();

        return TRUE;
    }

}

