#pragma once
#include <memory>
#include <string>
#include "Card.h"
#include "../Carta.hpp"

namespace ui {
	class CartaToCardConverter
	{
	private:
		static CardValues getValueOfCard(int value);
		static Naipe getNaipeOfCard(std::string value);
	public:
		static std::shared_ptr<Card> converter(Carta* carta);
	};
}