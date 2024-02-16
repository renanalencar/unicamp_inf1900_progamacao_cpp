#pragma once
#include "BaseView.h"

namespace ui {

	template <class VM>
	class BaseViewModel
	{
	protected:
		bool m_enable;
		DrawArea m_drawArea;
		BaseView<VM>* m_pView;

	public:
		BaseViewModel(BaseView<VM>* pView, int x, int y, int width, int heigth);
		DrawArea getDrawArea();
		void move(int x, int y);
	};

	template<class VM>
	inline BaseViewModel<VM>::BaseViewModel(BaseView<VM>* pView, int x, int y, int width, int heigth)
	{
		m_drawArea.Left = x;
		m_drawArea.Top = y;
		m_drawArea.Width = width;
		m_drawArea.Height = heigth;

		m_pView = pView;
		m_enable = true;
	}

	template<class VM>
	inline DrawArea BaseViewModel<VM>::getDrawArea()
	{
		return m_drawArea;
	}

	template<class VM>
	inline void BaseViewModel<VM>::move(int x, int y)
	{
		m_drawArea.Left = x;
		m_drawArea.Top = y;

		m_pView->update();
	}
}