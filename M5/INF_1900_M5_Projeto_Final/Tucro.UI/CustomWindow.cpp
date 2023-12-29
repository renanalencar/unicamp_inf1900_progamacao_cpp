#include "CustomWindow.h"
#include <string>

CustomWindow::CustomWindow(int x, int y, int width, int height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;

	std::string teste = "Texugo";

	static CStringA strA;
	strA = teste.c_str();

	Create(nullptr, _T("Teste"), WS_OVERLAPPEDWINDOW, CRect(m_x, m_y, m_width, m_height));

	this->initComponents();
}

void CustomWindow::initComponents()
{
	
}


