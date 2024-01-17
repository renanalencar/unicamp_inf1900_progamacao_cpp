#pragma once
#include <memory>
#include <afxwin.h>
#include "TexturasFactory.h"
#include "PathUtils.h"
#include "Naipe.h"
#include "CartaValor.h"
#include "CartaViewModel.h"
#include "BaseView.h"

class Carta : public BaseView
{
private:
	CFrameWnd* m_pWindow;
	std::shared_ptr<CartaViewModel> m_pViewModel;
	std::shared_ptr<CRect>  m_bound;
	std::unique_ptr<CStatic> m_canvas;

	HBITMAP loadTexture();
	void updateBoundArea();
	void draw();
	void moveTo();

public:
	Carta(CFrameWnd* window, Naipe naipe, CartaValor valor, int x, int y);
	std::shared_ptr<CartaViewModel> getViewModel();
	std::shared_ptr<CRect> getBound();
	// Inherited via IView
	void update() override;	
};



