#pragma once
#include <afxwin.h>
#include <memory>

namespace ui {
    enum class FontWeight {
        Dontcare = FW_DONTCARE,
        Thin = FW_THIN,
        Extraligh = FW_EXTRALIGHT,
        Light = FW_LIGHT,
        Normal = FW_NORMAL,
        Medium = FW_MEDIUM,
        Semibold = FW_SEMIBOLD,
        Bold = FW_BOLD,
        Extrabold = FW_EXTRABOLD,
        Heavy = FW_HEAVY
    };



    class CustomLabel : public CStatic
    {

    private:
        COLORREF m_foregorund;
        COLORREF m_backgorund;
        UINT8 m_fontSize;
        FontWeight m_fontWeight;
        bool m_isTransparent;
    public:
        CustomLabel();
        virtual ~CustomLabel();

        void setBackgroundColor(COLORREF color = RGB(0, 0, 0));
        COLORREF getBackgroundColor() const;
        void setForegroundColor(COLORREF color = RGB(0, 0, 0));
        COLORREF getForegroundColor() const;
        void setFontSize(UINT8 value);
        UINT8 getFontSize();
        void setFontWeigth(FontWeight weight);
        FontWeight getFontWeigth();
        void setTransparent(bool value);

    protected:
        afx_msg void OnPaint();
        DECLARE_MESSAGE_MAP()
    };
}