#pragma once
#include <memory>
#include "Player.h"
#include "../jogador.hpp"
#include "CartaToCardConverter.h"

namespace ui {
	class JogadorToPlayerConverter
	{
	public:
		static std::shared_ptr<Player> converter(Jogador* jogador);
	};
}
