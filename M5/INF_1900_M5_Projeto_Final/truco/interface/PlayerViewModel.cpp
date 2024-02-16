#include "PlayerViewModel.h"

namespace ui {
	PlayerViewModel::PlayerViewModel(BaseView<PlayerViewModel>* view, int x, int y)
		: BaseViewModel<PlayerViewModel>(view, x, y, PLAY_WIDTH, PLAY_HEIGHT)
	{

	}
}