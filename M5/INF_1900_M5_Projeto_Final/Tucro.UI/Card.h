#pragma once
#include <memory>
#include <afxwin.h>
#include "TextureFactory.h"
#include "PathUtils.h"
#include "Naipe.h"
#include "CardValues.h"
#include "CardViewModel.h"
#include "BaseView.h"
#include "BaseControl.h"

class Card : public BaseView<CardViewModel>, public BaseControl
{
private:		
	HBITMAP loadTexture();
	void updateBoundArea();	

public:
	Card(CWnd* window, Naipe naipe, CardValues valor, int x, int y);
	
	// Inherited via IView
	void onLeftMouseButtonDownHandle(int x, int y);
	void draw() override;
	void update() override;
};




