#include "ApplicationMFC.h"

BOOL ApplicationMFC::InitInstance()
{
    m_pMainWnd = new MainWindow();
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}



