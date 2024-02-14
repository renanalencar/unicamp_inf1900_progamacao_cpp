#pragma once
#include "DrawArea.h"
#include "BaseViewModel.h"

const int DIALOG_WIDTH = 600;
const int DIALOG_HEIGHT = 180;

class DialogViewModel : public BaseViewModel<DialogViewModel>
{
private:


public:	
	/*CommonEventHandle OnAceiteButtonClick;
	CommonEventHandle OnRecuseButtonClick;
	CommonEventHandle OnPedirButtonClick;*/

	DialogViewModel(BaseView<DialogViewModel>* pView, int x, int y, int width, int heigth);
};

