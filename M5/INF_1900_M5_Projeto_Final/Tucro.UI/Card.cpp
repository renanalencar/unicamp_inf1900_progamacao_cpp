
#include "Card.h"

Card::Card(CFrameWnd* window, Naipe naipe, CardValues valor, int x, int y) : BaseView<CardViewModel>(), Drawable(window, x, y, CARD_WIDTH, CARD_HEIGHT)
{	
	m_pViewModel = std::make_unique<CardViewModel>(this, naipe, valor, x, y);
}

void Card::leftMouseButtonDownHandle(const CPoint& point)
{
	m_pViewModel->onLeftMouseButtonClick();
}

HBITMAP Card::loadTexture()
{
	HBITMAP textura;

	if (m_pViewModel->isDown()) {		
		textura = PathUtils::loadBitmap(IMG_BACK_CARTA);
	}
	else {
		textura = PathUtils::getTexture(m_pViewModel->getValue(), m_pViewModel->getNaipe());
	}

	return textura;
}

void Card::updateBoundArea()
{
	setBounds(new CRect(m_pViewModel->getDrawArea().Left, m_pViewModel->getDrawArea().Top, m_pViewModel->getDrawArea().Width + m_pViewModel->getDrawArea().Left, m_pViewModel->getDrawArea().Height + m_pViewModel->getDrawArea().Top));
}

void Card::draw()
{	
	updateBoundArea();
	setTexture(loadTexture());
	Drawable::draw();
}

void Card::update()
{
	draw();
	move(m_pViewModel->getDrawArea().Left, m_pViewModel->getDrawArea().Top);
}


