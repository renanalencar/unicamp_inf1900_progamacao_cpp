#pragma once
#include <memory>
#include "Naipe.h"
#include "CardValues.h"
#include "BaseView.h"



const int CARD_WIDTH = 91;
const int CARD_HEIGHT = 120;

struct DrawArea {
	int X0;
	int Y0;
	int Xf;
	int Yf;
};

class CardViewModel
{
private:
	bool m_IsDown;
	bool m_ativa;
	Naipe m_naipe;
	CardValues m_value;
	DrawArea m_drawArea;
	BaseView<CardViewModel>* m_pView;


public:
	CardViewModel(BaseView<CardViewModel>* view, const Naipe& naipe, const CardValues& valor, int x, int y);
	bool isDown() const;
	Naipe getNaipe() const;
	CardValues getValue() const;
	DrawArea getDrawArea();
	void move(int x, int y);
	void turn();
	void onLeftMouseButtonClick();
};

