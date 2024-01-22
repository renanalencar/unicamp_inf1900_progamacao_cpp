#include "CardViewModel.h"

CardViewModel::CardViewModel(BaseView<CardViewModel>* view, const Naipe& naipe, const CardValues& valor, int x, int y): 
	BaseViewModel<CardViewModel>(view, x, y, CARD_WIDTH, CARD_HEIGHT)
{
	m_naipe = naipe;
	m_value = valor;
	m_IsDown = false;			
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

void CardViewModel::turn()
{
	m_IsDown = !m_IsDown;
	m_pView->update();
}

void CardViewModel::onLeftMouseButtonClick()
{
	turn();
}


