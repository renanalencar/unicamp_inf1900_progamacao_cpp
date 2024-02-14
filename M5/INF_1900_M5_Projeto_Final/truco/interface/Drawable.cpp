#include "Drawable.h"

namespace ui {
    Drawable::Drawable(CWnd* window, int x, int y, int width, int height)
    {
        m_pWindow = window;
        m_enable = true;
        m_pCanvas = std::make_unique<CStatic>();
        m_pBounds = std::make_shared<CRect>(x, y, x + width, y + height);
        m_visible = true;

        DWORD dwCartaStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP;
        m_pCanvas->Create(L"DRAWABLE", dwCartaStyle, *m_pBounds.get(), m_pWindow);
    }

    void Drawable::setEnable(bool value)
    {
        m_enable = value;
    }

    std::shared_ptr<CRect> Drawable::getBounds() const
    {
        return m_pBounds;
    }

    void Drawable::setBounds(const CRect& rect)
    {
        m_pBounds.reset(new CRect(rect));
    }

    void Drawable::setTexture(HBITMAP texture)
    {
        m_texture = texture;
    }


    void Drawable::move(int x, int y)
    {
        setBounds(new CRect(x, y, m_pBounds->Width() + x, m_pBounds->Height() + y));
        m_pCanvas->MoveWindow(m_pBounds.get());
    }

    void Drawable::resize(int width, int height)
    {
        setBounds(new CRect(m_pBounds->left, m_pBounds->top, width + m_pBounds->left, height + m_pBounds->top));
        m_pCanvas->MoveWindow(m_pBounds.get(), false);
    }

    bool Drawable::isEnable() const
    {
        return m_enable;
    }

    bool Drawable::isVisible() const
    {
        return m_visible;
    }

    void Drawable::setVisible(bool value)
    {
        if (value) {
            m_pCanvas->ShowWindow(SW_SHOW);
        }
        else
            m_pCanvas->ShowWindow(SW_HIDE);
        m_visible = value;
    }

    void Drawable::draw() {
        m_pCanvas->SetBitmap(m_texture);
        m_pCanvas->MoveWindow(*m_pBounds.get());
    }

}