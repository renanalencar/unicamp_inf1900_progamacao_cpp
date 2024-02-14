#include "BaseButton.h"

namespace ui {
	void BaseButton::loadTexture()
	{
		setTexture(PathUtils::getButtonTexture(m_type));
	}

	BaseButton::BaseButton(CWnd* parent, int x, int y, TypeButton type) : BaseControl(parent, x, y, BUTTON_WIDTH, BUTTON_HEIGHT)
	{
		m_type = type;
		loadTexture();
	}
}