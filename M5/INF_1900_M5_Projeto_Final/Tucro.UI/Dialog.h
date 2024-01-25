#pragma once
#include <memory>
#include <afxwin.h>
#include "DialogViewModel.h"
#include "BaseView.h"
#include "Drawable.h"

class Dialog: public BaseView<DialogViewModel>, public Drawable
{

};

