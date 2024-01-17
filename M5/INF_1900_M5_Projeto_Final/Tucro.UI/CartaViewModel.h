#pragma once
#include <memory>
#include "Naipe.h"
#include "CartaValor.h"
#include "BaseView.h"



const int CARTA_WIDTH = 91;
const int CARTA_HEIGHT = 120;

struct DrawArea {
	int X0;
	int Y0;
	int Xf;
	int Yf;
};

class CartaViewModel
{
private:
	bool m_virada;
	bool m_ativa;
	Naipe m_naipe;
	CartaValor m_valor;
	DrawArea m_drawArea;
	BaseView* m_pView;


public:
	CartaViewModel(BaseView* view, const Naipe& naipe, const CartaValor& valor, int x, int y);
	bool virada() const;
	Naipe getNaipe() const;
	CartaValor getValor() const;
	DrawArea getDrawArea();
	void mover(int x, int y);
	void virar();
};

