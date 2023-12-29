#pragma once
#include "IWidget.h"
#include "IWindow.h"

class IComponent : public IWidget{
public:
	virtual int getTag() = 0;
	virtual void setTag(int tag) = 0;
	virtual void init() = 0;	
};
