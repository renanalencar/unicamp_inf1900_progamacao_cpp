#pragma once
#include <string>
#include <vector>
#include "IWidget.h"
#include "IComponent.h"

class IWindow : public IWidget {
public:
	virtual std::string getCaption() = 0;
	virtual void setCaption(std::string caption) = 0;
	virtual void initComponents() = 0;
	virtual void show() = 0;
	virtual std::vector<std::shared_ptr<IComponent>> getWidgets() = 0;
};
