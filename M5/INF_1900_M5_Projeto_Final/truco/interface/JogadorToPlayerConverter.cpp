#include "JogadorToPlayerConverter.h"

namespace ui {
	std::shared_ptr<Player> JogadorToPlayerConverter::converter(Jogador* jogador)
	{
		std::shared_ptr<Player> player = std::make_shared<Player>();

		for (auto& carta : jogador->getMao()) {
			std::shared_ptr<Card> card = CartaToCardConverter::converter(&carta);			
			player->addCard(card);
		}
		
		return player;
	}
}