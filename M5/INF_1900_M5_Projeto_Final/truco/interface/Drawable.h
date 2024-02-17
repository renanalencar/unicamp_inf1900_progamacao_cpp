#pragma once
#include <memory>
#include <afxwin.h>
namespace ui {

	class Drawable
	{
	protected:
		std::unique_ptr<CStatic> m_pCanvas;
		CWnd* m_pWindow;

	private:
		std::shared_ptr<CRect>  m_pBounds;
		bool m_enable;
		bool m_visible;
		HBITMAP m_texture;

	public:
		Drawable(CWnd* window, int x, int y, int width, int height);
		void CreateCanvas();
		virtual void draw();
		virtual void setParent(CWnd* parent);

		bool isEnable() const;
		void setEnable(bool value);
		bool isVisible() const;
		void setVisible(bool value);
		std::shared_ptr<CRect> getBounds() const;
		void setBounds(const CRect& rect);
		void setTexture(HBITMAP texture);
		void move(int x, int y);
		CWnd* getParent();
		void resize(int width, int height);
	};

}