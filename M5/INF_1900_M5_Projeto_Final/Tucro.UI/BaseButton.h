#pragma once
#include <afxwin.h>
#include <memory>

#include "PathUtils.h"
#include "AssetsConstants.h"
#include "BaseControl.h"
#include "TypeButtons.h"

const int BUTTON_WIDTH = 120;
const int BUTTON_HEIGHT = 44;

class BaseButton : public BaseControl
{
private:
	TypeButton m_type;

	void loadTexture();
public: 
	BaseButton(CWnd* parent, int x, int y, TypeButton type);
};

