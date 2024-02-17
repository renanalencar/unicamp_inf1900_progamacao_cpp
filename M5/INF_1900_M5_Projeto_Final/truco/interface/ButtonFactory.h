#pragma once
#include "BaseButton.h"
#include "TypeButtons.h"

namespace ui {
	class ButtonFactory
	{
	private:
		static std::shared_ptr<BaseButton> CreateButton(CWnd* parent, int x, int y, TypeButton type);

	public:
		static std::shared_ptr<BaseButton> CreateDialogAceitarButton(CWnd* parent, int x, int y);
		static std::shared_ptr<BaseButton> CreateDialogRecusarButton(CWnd* parent, int x, int y);
		static std::shared_ptr<BaseButton> CreateDialogPedirButton(CWnd* parent, int x, int y, TypeButton type);
	};
}