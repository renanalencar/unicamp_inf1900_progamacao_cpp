#pragma once
#include <memory>

class IWidget {

public:
	virtual int getX() = 0;
	virtual void setX(int x) = 0;
	virtual int getY() = 0;
	virtual void setY(int y) = 0;
	virtual int getWidth() = 0;
	virtual void setWidth(int width) = 0;
	virtual int getHeight() = 0;
	virtual void setHeight(int height) = 0;	
	virtual void update() = 0;
};