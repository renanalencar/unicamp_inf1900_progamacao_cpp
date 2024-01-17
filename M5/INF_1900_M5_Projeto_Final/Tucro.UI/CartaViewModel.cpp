#include "CartaViewModel.h"

CartaViewModel::CartaViewModel(BaseView* view, const Naipe& naipe, const CartaValor& valor, int x, int y)
{
	m_naipe = naipe;
	m_valor = valor;
	m_virada = false;
	m_ativa = true;
	m_drawArea.X0 = x;
	m_drawArea.Y0 = y;
	m_drawArea.Xf = x + CARTA_WIDTH;
	m_drawArea.Yf = y + CARTA_HEIGHT;
	m_pView = view;
}

bool CartaViewModel::virada() const
{
	return m_virada;
}

Naipe CartaViewModel::getNaipe() const
{
	return m_naipe;
}

CartaValor CartaViewModel::getValor() const
{
	return m_valor;
}

DrawArea CartaViewModel::getDrawArea()
{
	return m_drawArea;
}

void CartaViewModel::mover(int x, int y)
{
	m_drawArea.X0 = x;
	m_drawArea.Y0 = y;
	m_drawArea.Xf = x + CARTA_WIDTH;
	m_drawArea.Yf = y + CARTA_HEIGHT;

	m_pView->update();
}

void CartaViewModel::virar()
{
	m_virada = !m_virada;
	m_pView->update();
}


