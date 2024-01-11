#pragma once
#include <memory>
#include <afxwin.h>
#include "TexturasFactory.h"

const int CARTA_WIDTH = 150;
const int CARTA_HEIGHT = 200;

class Carta
{
private:
	CFrameWnd* m_pWindow;
	std::shared_ptr<CStatic> m_canvas;

public:
	Carta(CFrameWnd* window, int x, int y);
};

