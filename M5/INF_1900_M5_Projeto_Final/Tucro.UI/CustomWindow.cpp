#include "CustomWindow.h"
#include <string>

CustomWindow::CustomWindow(int x, int y, int width, int height, std::wstring caption)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_caption = caption;

	LPCTSTR szTemp = m_caption.c_str();

	Create(nullptr, szTemp, WS_OVERLAPPEDWINDOW, CRect(m_x, m_y, m_width, m_height));

	this->initComponents();
}

void CustomWindow::initComponents()
{
	
}

int CustomWindow::getX() const
{
	return this->m_x;
}

void CustomWindow::setX(int x)
{
	this->m_x = x;
}

int CustomWindow::getY() const
{
	return this->m_y;
}

void CustomWindow::setY(int y)
{
	this->m_y = y;
}

int CustomWindow::getWidth() const
{
	return this->m_width;
}

void CustomWindow::setWidth(int width)
{
	this->m_width = width;
}

int CustomWindow::getHeight() const
{
	return this->m_height;
}

void CustomWindow::setHeight(int height)
{
	this->m_height = height;
}

std::wstring CustomWindow::getCaption() const
{
	return this->m_caption;
}

void CustomWindow::setCaption(std::wstring caption)
{
	this->m_caption = caption;
}

void CustomWindow::show()
{
	this->ShowWindow(SW_SHOW);
}

void CustomWindow::update()
{
	this->UpdateWindow();
}


