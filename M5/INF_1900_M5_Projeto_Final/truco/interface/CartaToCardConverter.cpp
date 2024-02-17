#include "CartaToCardConverter.h"

namespace ui {
	std::shared_ptr<Card> CartaToCardConverter::converter(Carta* carta)
	{		
		carta->getValor();
		std::shared_ptr<Card> card = std::make_shared<Card>(getNaipeOfCard(carta->getNaipe()), getValueOfCard(carta->getValor()));		
		return card;		
	}
	CardValues CartaToCardConverter::getValueOfCard(int value)
	{
		if (value >= 1 && value <= 13) {
			return ((CardValues) value);
		}
		else {
			//Disparar excecao
		}
	}

	Naipe CartaToCardConverter::getNaipeOfCard(std::string value)
	{
		if (value == COPAS) {
			return Naipe::COPAS;
		}
		else if (value == PAUS) {
			return Naipe::PAUS;
		}
		else if (value == OUROS) {
			return Naipe::OUROS;
		}
		else if (value == ESPADAS) {
			return Naipe::ESPADAS;
		}
		else {
			return Naipe::NONE;
		}
	}
}