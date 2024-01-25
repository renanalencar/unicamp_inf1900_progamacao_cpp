#pragma once
#include <memory>
#include <afxwin.h>

class Drawable
{
protected:
	std::unique_ptr<CStatic> m_pCanvas;

private:
	CWnd* m_pWindow;	
	std::shared_ptr<CRect>  m_pBounds;
	bool m_enable;		
	HBITMAP m_texture;

public:
	Drawable(CWnd* window, int x, int y, int width, int height);
	virtual void draw();
		
	
	bool isEnable() const;
	void setEnable(bool value);
	std::shared_ptr<CRect> getBounds() const;
	void setBounds(const CRect& rect);
	void setTexture(HBITMAP texture);
	void move(int x, int y);
	void resize(int width, int height);    
};

