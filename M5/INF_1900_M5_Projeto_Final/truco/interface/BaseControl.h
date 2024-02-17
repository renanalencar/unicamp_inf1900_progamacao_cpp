#pragma once
#include <afxdisp.h>
#include <functional>
#include "Drawable.h"

namespace ui {
	using MouseEventHandle = std::function<void(const int&, const int&)>;
	using CommonEventHandle = std::function<void()>;


	class BaseControl : public Drawable
	{
	public:
		MouseEventHandle OnLeftMouseButtonDownHandle;

		BaseControl(CWnd* window, int x, int y, int width, int height);
		virtual void LeftMouseButtonDown(const CPoint& point);
	};

}