
#include "Carta.h"

Carta::Carta(CFrameWnd* window, int x, int y)
{
	m_pWindow = window;

	m_canvas = std::make_shared<CStatic>();
	m_canvas->Create(NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(x, y, CARTA_WIDTH, CARTA_HEIGHT), window, TexturasFactory::getInstance()->getCartaPaus()->ID);

	HBITMAP textura = TexturasFactory::getInstance()->getCartaPaus()->textura;
	m_canvas->SetBitmap(textura);	
}
