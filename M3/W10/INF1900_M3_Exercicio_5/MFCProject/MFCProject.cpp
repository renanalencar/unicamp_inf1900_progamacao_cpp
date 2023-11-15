// MFCProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _AFXDLL
#include <afxwin.h>
#include <afxwin.h>


class CMyWindow : public CFrameWnd {
public:
    CMyWindow() {
        Create(nullptr, _T("Minha Janela"), WS_OVERLAPPEDWINDOW, CRect(100, 100, 500, 300));

        // Crie um controle de "caixa de texto"
        m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 10, 210, 40), this, 1);

        // Crie um botão
        m_Button.Create(_T("Exibir MessageBox"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(220, 10, 370, 40), this, 2);
    }

    afx_msg void OnButtonClicked() {
        CString strText;
        m_Edit.GetWindowText(strText);

        AfxMessageBox(strText, MB_OK | MB_ICONINFORMATION);
    }

    DECLARE_MESSAGE_MAP()

private:
    CEdit m_Edit;
    CButton m_Button;
};

BEGIN_MESSAGE_MAP(CMyWindow, CFrameWnd)
    ON_BN_CLICKED(2, &CMyWindow::OnButtonClicked)
END_MESSAGE_MAP() 

int main() {
    CWinApp app;
    CMyWindow myWindow;

    app.m_pMainWnd = &myWindow;
    myWindow.ShowWindow(SW_SHOW);
    myWindow.UpdateWindow();

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
