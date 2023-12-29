#pragma once
#include <afxwin.h>
#include <string>
#include <vector>
#include "IWidget.h"
#include "IComponent.h"

class IWindow : public CFrameWnd {

public:
	virtual int getX() const = 0;
	virtual void setX(int x) = 0;
	virtual int getY() const = 0;
	virtual void setY(int y) = 0;
	virtual int getWidth() const = 0;
	virtual void setWidth(int width) = 0;
	virtual int getHeight() const = 0;
	virtual void setHeight(int height) = 0;
	virtual std::wstring getCaption() const = 0;
	virtual void setCaption(std::wstring caption) = 0;	
	virtual void show() = 0;
	virtual void update() = 0;	
	virtual void initComponents() = 0;
};
