#pragma once
#include <memory>
#include "Naipe.h"
#include "CardValues.h"
#include "BaseView.h"
#include "DrawArea.h"
#include "BaseViewModel.h"

namespace ui {
	const int CARD_WIDTH = 91;
	const int CARD_HEIGHT = 120;


	class CardViewModel : public BaseViewModel<CardViewModel>
	{
	private:
		bool m_IsDown;
		Naipe m_naipe;
		CardValues m_value;

	public:
		bool operator ==(const CardViewModel& other);

		CardViewModel(BaseView<CardViewModel>* view, const Naipe& naipe, const CardValues& valor, int x, int y);
		bool isDown() const;
		Naipe getNaipe() const;
		CardValues getValue() const;
		void turn();
		void OnLeftMouseButtonClick();
	};
}