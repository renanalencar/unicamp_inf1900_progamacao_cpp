#include "BaseButton.h"


BEGIN_MESSAGE_MAP(BaseButton, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL BaseButton::Create(DWORD dwStyle, int x, int y, CWnd* pParentWnd, UINT nID)
{
    return CStatic::Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT), pParentWnd, nID);
}

void BaseButton::OnPaint()
{
    std::unique_ptr<CPaintDC> pDC;
    pDC = std::make_unique<CPaintDC>(this);

    CDC memDC;
    memDC.CreateCompatibleDC(pDC.get());
    memDC.SelectObject(PathUtils::getHUDTexture(IMG_TRUCO_MESA_BUTTON));

    pDC->BitBlt(0, 0, 120, 44, &memDC, 0, 0, SRCCOPY);

}
