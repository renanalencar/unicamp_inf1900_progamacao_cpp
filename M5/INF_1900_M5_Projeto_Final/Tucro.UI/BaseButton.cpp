#include "BaseButton.h"

void BaseButton::loadTexture()
{	
	setTexture(PathUtils::getButtonTexture(m_type));
}

BaseButton::BaseButton(CWnd* window, int x, int y, TypeButton type) : BaseControl(window, x, y, BUTTON_WIDTH, BUTTON_HEIGHT)
{
	m_type = type;
	loadTexture();	
}


