#include "WindowMFC.h"
#include <string>

WindowMFC::WindowMFC(int x, int y, int width, int height, std::wstring caption)
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

void WindowMFC::initComponents()
{
	
}

int WindowMFC::getX() const
{
	return this->m_x;
}

void WindowMFC::setX(int x)
{
	this->m_x = x;
}

int WindowMFC::getY() const
{
	return this->m_y;
}

void WindowMFC::setY(int y)
{
	this->m_y = y;
}

int WindowMFC::getWidth() const
{
	return this->m_width;
}

void WindowMFC::setWidth(int width)
{
	this->m_width = width;
}

int WindowMFC::getHeight() const
{
	return this->m_height;
}

void WindowMFC::setHeight(int height)
{
	this->m_height = height;
}

std::wstring WindowMFC::getCaption() const
{
	return this->m_caption;
}

void WindowMFC::setCaption(std::wstring caption)
{
	this->m_caption = caption;
}

void WindowMFC::show()
{
	this->ShowWindow(SW_SHOW);
}

void WindowMFC::update()
{
	this->UpdateWindow();
}


