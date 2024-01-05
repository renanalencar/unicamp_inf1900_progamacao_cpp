#pragma once
#include <afxwin.h>
#include "IWindow.h"

class WindowMFC :  public IWindow
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::wstring m_caption;

public:
	WindowMFC(int x, int y, int width, int height, std::wstring caption = L"new window");
	virtual void initComponents();

	// Inherited via IWindow
	int getX() const override;
	void setX(int x) override;
	int getY() const override;
	void setY(int y) override;
	int getWidth() const override;
	void setWidth(int width) override;
	int getHeight() const override;
	void setHeight(int height) override;
	std::wstring getCaption() const override;
	void setCaption(std::wstring caption) override;

	// Inherited via IWindow
	void show() override;
	void update() override;
};

