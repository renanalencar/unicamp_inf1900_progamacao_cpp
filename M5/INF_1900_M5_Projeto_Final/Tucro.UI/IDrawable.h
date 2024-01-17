#pragma once
#include <memory>
#include <afxwin.h>

class IDrawable
{
protected:
	CFrameWnd* m_pWindow;	
	std::shared_ptr<CRect>  m_bound;
	std::unique_ptr<CStatic> m_canvas;

public:
	std::shared_ptr<CRect> getBound();
    void LeftMouseDownEvent(const CPoint& point);
	virtual void draw();
	virtual void onLMouseDown();
};

