#include "Drawable.h"

Drawable::Drawable(CFrameWnd* window, int x, int y, int width, int height)
{
    m_pWindow = window;
    m_enable = true;    
    m_pCanvas = std::make_unique<CStatic>();
    m_pBounds = std::make_shared<CRect>(x, y, x + width, y + height);

    DWORD dwCartaStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP;
    m_pCanvas->Create(NULL, dwCartaStyle, *m_pBounds.get(), m_pWindow, 256);
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

void Drawable::OnLeftMouseButtonDown(const CPoint& point)
{
    if (isEnable() && m_pBounds->PtInRect(point)) {
        leftMouseButtonDownHandle(point);
    }
}

bool Drawable::isEnable() const
{
    return m_enable;
}

void Drawable::draw(){    
    m_pCanvas->SetBitmap(m_texture);     
}

void Drawable::leftMouseButtonDownHandle(const CPoint& point)
{
}

