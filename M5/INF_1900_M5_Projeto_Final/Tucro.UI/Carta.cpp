
#include "Carta.h"



Carta::Carta(CFrameWnd* window, Naipe naipe, CartaValor valor,  int x, int y)
{
	m_pWindow = window;
	m_bound = std::make_shared<CRect>(x, y, x + CARTA_WIDTH, y + CARTA_HEIGHT);
	m_canvas = std::make_shared<CStatic>();	
	m_naipe = naipe;
	m_valor = valor;
	loadTexture();
}

void Carta::loadTexture()
{
	m_textura = PathUtils::getTexture(m_valor, m_naipe);
}

void Carta::draw()
{
	DWORD dwCartaStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP;
	CRect rectArea(m_bound.get());

	m_canvas->Create(NULL, dwCartaStyle, rectArea, m_pWindow);
	m_canvas->SetBitmap(m_textura);
}

void Carta::moveTo(int x, int y)
{
	m_bound = std::make_shared<CRect>(x, y, x + CARTA_WIDTH, y + CARTA_HEIGHT);
	m_canvas->MoveWindow(m_bound.get());
}
