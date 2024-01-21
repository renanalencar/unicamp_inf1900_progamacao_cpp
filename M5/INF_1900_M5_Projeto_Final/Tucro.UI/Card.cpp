
#include "Card.h"

Card::Card(CFrameWnd* window, Naipe naipe, CardValues valor, int x, int y) : BaseView(), Drawable(window, x, y, CARD_WIDTH, CARD_HEIGHT)
{	
	m_pViewModel = std::make_shared<CardViewModel>(this, naipe, valor, x, y);	
	
}

void Card::leftMouseButtonDownHandle(const CPoint& point)
{
	m_pViewModel->onLeftMouseButtonClick();
}


std::shared_ptr<CardViewModel> Card::getViewModel()
{
	return m_pViewModel;
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
	setBounds(new CRect(m_pViewModel->getDrawArea().X0, m_pViewModel->getDrawArea().Y0, m_pViewModel->getDrawArea().Xf, m_pViewModel->getDrawArea().Yf));	
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
	move(m_pViewModel->getDrawArea().X0, m_pViewModel->getDrawArea().Y0);
}
