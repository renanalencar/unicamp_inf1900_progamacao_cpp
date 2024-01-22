#pragma once
#include <memory>
#include <afxwin.h>
#include "TextureFactory.h"
#include "PathUtils.h"
#include "Naipe.h"
#include "CardValues.h"
#include "CardViewModel.h"
#include "BaseView.h"
#include "Drawable.h"

class Card : public BaseView<CardViewModel>, public Drawable
{
private:		
	HBITMAP loadTexture();
	void updateBoundArea();	

public:
	Card(CFrameWnd* window, Naipe naipe, CardValues valor, int x, int y);	
	
	// Inherited via IView
	void leftMouseButtonDownHandle(const CPoint& point) override;
	void draw() override;
	void update() override;
};




