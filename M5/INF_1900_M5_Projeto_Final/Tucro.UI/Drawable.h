#pragma once
#include <memory>
#include <afxwin.h>

class Drawable
{
private:
	CFrameWnd* m_pWindow;	
	std::shared_ptr<CRect>  m_pBounds;
	std::unique_ptr<CStatic> m_pCanvas;
	bool m_enable;		
	HBITMAP m_texture;	

public:
	Drawable(CFrameWnd* window, int x, int y, int width, int height);
	virtual void draw();
	virtual void leftMouseButtonDownHandle(const CPoint& point);
	
	
	bool isEnable() const;
	void setEnable(bool value);
	std::shared_ptr<CRect> getBounds() const;
	void setBounds(const CRect& rect);
	void setTexture(HBITMAP texture);
	void move(int x, int y);
	void resize(int width, int height);
    void OnLeftMouseButtonDown(const CPoint& point);
};

