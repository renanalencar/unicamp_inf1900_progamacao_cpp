#pragma once
#include <afxdisp.h>
#include <functional>
#include "Drawable.h"


using MouseEventHandle = std::function<void(const int&, const int&)>;


class BaseControl : public Drawable
{
public:	
	MouseEventHandle OnLeftMouseButtonDownHandle;

	BaseControl(CWnd* window, int x, int y, int width, int height);
	void LeftMouseButtonDown(const CPoint& point);	
};

