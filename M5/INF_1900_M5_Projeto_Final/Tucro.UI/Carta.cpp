
#include "Carta.h"

Carta::Carta(CFrameWnd* window, Naipe naipe, CartaValor valor,  int x, int y) : BaseView(), IDrawable()
{
	m_pWindow = window;
	m_pViewModel = std::make_shared<CartaViewModel>(this, naipe, valor, x, y);	
	m_canvas = std::make_unique<CStatic>();

	updateBoundArea();
	DWORD dwCartaStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP;
	CRect rectArea(m_bound.get());
	m_canvas->Create(NULL, dwCartaStyle, rectArea, m_pWindow, 256);
}

std::shared_ptr<CartaViewModel> Carta::getViewModel()
{
	return m_pViewModel;
}

//std::shared_ptr<CRect> Carta::getBound()
//{
//	return m_bound;
//}

HBITMAP Carta::loadTexture()
{
	HBITMAP textura;

	if (m_pViewModel->virada()) {		
		textura = PathUtils::loadBitmap(IMG_BACK_CARTA);
	}
	else {
		textura = PathUtils::getTexture(m_pViewModel->getValor(), m_pViewModel->getNaipe());
	}

	return textura;
}

void Carta::updateBoundArea()
{
	m_bound = std::make_shared<CRect>(m_pViewModel->getDrawArea().X0, m_pViewModel->getDrawArea().Y0, m_pViewModel->getDrawArea().Xf, m_pViewModel->getDrawArea().Yf);
}

void Carta::draw()
{	
	m_canvas->SetBitmap(loadTexture());
}

void Carta::moveTo()
{	
	updateBoundArea();
	m_canvas->MoveWindow(m_bound.get());	
}

void Carta::update()
{
	draw();
	moveTo();
}

void Carta::onLMouseDown()
{
	m_pViewModel->virar();
	update();
}
