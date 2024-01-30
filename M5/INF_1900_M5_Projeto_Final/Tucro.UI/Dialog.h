#pragma once
#include <memory>
#include <afxwin.h>
#include "DialogViewModel.h"
#include "BaseView.h"
#include "PathUtils.h"
#include "CustomLabel.h"
#include "BaseButton.h"
#include "ButtonFactory.h"


const int ICON_WIDTH = 160;
const int ICON_HEIGHT = 140;

enum class DialogType {
	PedirSeis,
	PedirNove,
	PedirDoze,
	Error,
	Info,
	Quest,
	Truco
};


class Dialog: public BaseControl
{

private:
	DialogType m_dialogType;
	std::unique_ptr<Drawable> m_pIcon;
	std::unique_ptr<CustomLabel> m_message;

	std::shared_ptr<BaseButton> m_pAceitarButton;
	std::shared_ptr<BaseButton> m_pRecusarButton;
	std::shared_ptr<BaseButton> m_pPedirButton;

	CommonEventHandle m_aceiteEventHandler;
	CommonEventHandle m_recusarEventHandler;
	CommonEventHandle m_pedirEventHandler;

	void loadIcon();

public:
	Dialog(CWnd* window, int x, int y, DialogType type, std::wstring message, 
		CommonEventHandle aceiteEventHandler = nullptr, CommonEventHandle recusarEventHandler = nullptr, CommonEventHandle pedirEventHandler = nullptr);

	// Inherited via BaseView
	void draw() override;
	void LeftMouseButtonDown(const CPoint& point) override;
};


class DialogBuilder {

private:
	DialogType m_dialogType;
	std::wstring m_message;
	int m_x;
	int m_y;
	CommonEventHandle m_aceiteEventHandler;
	CommonEventHandle m_recusarEventHandler;
	CommonEventHandle m_pedirEventHandler;
	CWnd* m_parent;

public:
	DialogBuilder(CWnd* parent);
	std::shared_ptr<Dialog> build();
	DialogBuilder WithDialogType(DialogType type);
	DialogBuilder WithMessage(std::wstring message);
	DialogBuilder WithPosition(int x, int y);
	DialogBuilder WithAceitarButton(CommonEventHandle eventHandler);
	DialogBuilder WithRecusarButton(CommonEventHandle eventHandler);
	DialogBuilder WithPedirButton(CommonEventHandle eventHandler);
};

