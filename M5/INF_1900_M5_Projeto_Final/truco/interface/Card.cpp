#include "Card.h"

namespace ui {
	Card::Card(Naipe naipe, CardValues valor):Card(nullptr, naipe, valor,0, 0)
	{

	}
	Card::Card(CWnd* window, Naipe naipe, CardValues valor, int x, int y) 
		: BaseView<CardViewModel>(), BaseControl(window, x, y, CARD_WIDTH, CARD_HEIGHT)
	{
		m_pViewModel = std::make_unique<CardViewModel>(this, naipe, valor, x, y);
		OnLeftMouseButtonDownHandle = [&](int x, int y) {onLeftMouseButtonDownHandle(x, y); };
	}

	void Card::onLeftMouseButtonDownHandle(int x, int y)
	{
		m_pViewModel->OnLeftMouseButtonClick();
	}

	HBITMAP Card::loadTexture()
	{
		HBITMAP textura;

		if (m_pViewModel->isDown()) {
			textura = PathUtils::loadBitmap(IMG_BACK_CARTA);
		}
		else {
			textura = PathUtils::getCardTexture(m_pViewModel->getValue(), m_pViewModel->getNaipe());
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
}