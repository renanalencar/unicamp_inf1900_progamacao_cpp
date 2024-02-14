#include "ButtonFactory.h"

namespace ui {
	std::shared_ptr<BaseButton> ButtonFactory::CreateButton(CWnd* parent, int x, int y, TypeButton type)
	{
		std::shared_ptr<BaseButton> button = std::make_shared<BaseButton>(parent, x, y, type);


		return button;
	}

	std::shared_ptr<BaseButton> ButtonFactory::CreateDialogAceitarButton(CWnd* parent, int x, int y)
	{
		return CreateButton(parent, x, y, TypeButton::DialogAceitar);
	}

	std::shared_ptr<BaseButton> ButtonFactory::CreateDialogRecusarButton(CWnd* parent, int x, int y)
	{
		return CreateButton(parent, x, y, TypeButton::DialogRecusar);
	}

	std::shared_ptr<BaseButton> ButtonFactory::CreateDialogPedirButton(CWnd* parent, int x, int y, TypeButton type)
	{
		return CreateButton(parent, x, y, type);
	}
}

