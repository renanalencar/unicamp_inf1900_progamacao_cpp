#pragma once
#include "BaseView.h"
#include "CardViewModel.h"
#include "PlayerViewModel.h"

namespace ui {
	constexpr int PLAY_WIDTH = (3 * CARD_WIDTH) + 30;
	constexpr int PLAY_HEIGHT = (CARD_HEIGHT + 10);

	class PlayerViewModel : public BaseViewModel<PlayerViewModel>
	{	

	public:
		explicit PlayerViewModel(BaseView<PlayerViewModel>* view, int x, int y);
	};
}
