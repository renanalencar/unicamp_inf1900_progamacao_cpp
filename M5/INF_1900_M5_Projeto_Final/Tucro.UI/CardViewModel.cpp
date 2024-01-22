#include "CardViewModel.h"

CardViewModel::CardViewModel(BaseView<CardViewModel>* view, const Naipe& naipe, const CardValues& valor, int x, int y)
{
	m_naipe = naipe;
	m_value = valor;
	m_IsDown = false;
	m_ativa = true;
	m_drawArea.X0 = x;
	m_drawArea.Y0 = y;
	m_drawArea.Xf = x + CARD_WIDTH;
	m_drawArea.Yf = y + CARD_HEIGHT;
	m_pView = view;
}

bool CardViewModel::isDown() const
{
	return m_IsDown;
}

Naipe CardViewModel::getNaipe() const
{
	return m_naipe;
}

CardValues CardViewModel::getValue() const
{
	return m_value;
}

DrawArea CardViewModel::getDrawArea()
{
	return m_drawArea;
}

void CardViewModel::move(int x, int y)
{
	m_drawArea.X0 = x;
	m_drawArea.Y0 = y;
	m_drawArea.Xf = x + CARD_WIDTH;
	m_drawArea.Yf = y + CARD_HEIGHT;

	m_pView->update();
}

void CardViewModel::turn()
{
	m_IsDown = !m_IsDown;
	m_pView->update();
}

void CardViewModel::onLeftMouseButtonClick()
{
	turn();
}


