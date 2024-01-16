#pragma once
#include <memory>
#include <afxwin.h>
#include "TexturasFactory.h"
#include "PathUtils.h"
#include "Naipe.h"
#include "CartaValor.h"

const int CARTA_WIDTH = 90;
const int CARTA_HEIGHT = 120;

class Carta
{
private:
	CFrameWnd* m_pWindow;
	std::shared_ptr<CRect>  m_bound;
	std::shared_ptr<CStatic> m_canvas;
	Naipe m_naipe;
	CartaValor m_valor;
	HBITMAP m_textura;

	void loadTexture();
public:
	Carta(CFrameWnd* window, Naipe naipe, CartaValor valor, int x = 0, int y = 0);
	void draw();
	void moveTo(int x, int y);
};


