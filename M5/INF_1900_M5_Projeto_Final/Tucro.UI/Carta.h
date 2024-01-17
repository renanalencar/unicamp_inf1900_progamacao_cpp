#pragma once
#include <memory>
#include <afxwin.h>
#include "TexturasFactory.h"
#include "PathUtils.h"
#include "Naipe.h"
#include "CartaValor.h"
#include "CartaViewModel.h"
#include "BaseView.h"
#include "IDrawable.h"

class Carta : public BaseView, public IDrawable
{
private:
	CFrameWnd* m_pWindow;
	std::shared_ptr<CartaViewModel> m_pViewModel;
	
	HBITMAP loadTexture();
	void updateBoundArea();
	void moveTo();

public:
	Carta(CFrameWnd* window, Naipe naipe, CartaValor valor, int x, int y);
	std::shared_ptr<CartaViewModel> getViewModel();
	
	// Inherited via IView
	void draw() override;
	void update() override;	
	void onLMouseDown() override;
};




