#include <windows.h>

// Constante para a mensagem personalizada
#define WM_MINHA_MENSAGEM (WM_USER + 1)

// Função de procedimento da janela
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registre a classe da janela
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("MyWinClass"), NULL };
    RegisterClassEx(&wc);

    // Crie a janela com os estilos apropriados
    HWND hwnd = CreateWindow(wc.lpszClassName, _T("Minha Janela"), WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, wc.hInstance, NULL);

    // Crie um controle de "caixa de texto"
    HWND hEdit = CreateWindow(_T("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 10, 10, 200, 30, hwnd, (HMENU)1, wc.hInstance, NULL);

    // Crie um botão
    HWND hButton = CreateWindow(_T("BUTTON"), _T("Exibir MessageBox"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 220, 10, 150, 30, hwnd, (HMENU)2, wc.hInstance, NULL);

    // Mostre a janela
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        // Configurações iniciais aqui
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == 2) { // Verifica se o controle é o botão (ID 2)
            TCHAR szText[256];
            GetWindowText(GetDlgItem(hwnd, 1), szText, 256); // Obtém o texto da caixa de texto (ID 1)

            // Exibe o texto em uma MessageBox
            MessageBox(hwnd, szText, _T("Texto da Caixa de Texto"), MB_OK | MB_ICONINFORMATION);
        }
        break;
    case WM_MINHA_MENSAGEM:
        // Trate a mensagem personalizada
        MessageBox(hwnd, _T("Mensagem Personalizada Recebida"), _T("Mensagem Personalizada"), MB_OK | MB_ICONINFORMATION);
        break;
    case WM_DESTROY:
        PostQuitMessage(0); // Encerra o aplicativo
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
