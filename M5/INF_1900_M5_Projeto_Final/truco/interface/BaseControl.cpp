#include "BaseControl.h"

namespace ui {
    BaseControl::BaseControl(CWnd* window, int x, int y, int width, int height) : Drawable(window, x, y, width, height)
    {
        OnLeftMouseButtonDownHandle = nullptr;
    }

    void BaseControl::LeftMouseButtonDown(const CPoint& point)
    {
        if (isEnable() && OnLeftMouseButtonDownHandle != nullptr && getBounds()->PtInRect(point)) {
            OnLeftMouseButtonDownHandle(point.x, point.y);
        }
    }
}