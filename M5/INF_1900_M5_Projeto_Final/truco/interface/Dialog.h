#pragma once
#include <memory>
#include <afxwin.h>
#include "BaseView.h"
#include "PathUtils.h"
#include "CustomLabel.h"
#include "BaseButton.h"
#include "ButtonFactory.h"

namespace ui {

	const int ICON_WIDTH = 160;
	const int ICON_HEIGHT = 140;

	const int DIALOG_WIDTH = 600;
	const int DIALOG_HEIGHT = 180;

	enum class DialogType {
		PedirSeis,
		PedirNove,
		PedirDoze,
		Error,
		Info,
		Quest,
		Truco
	};


	class Dialog : public BaseControl
	{

	private:
		DialogType m_dialogType;
		std::unique_ptr<Drawable> m_pIcon;
		std::unique_ptr<CustomLabel> m_message;

		std::shared_ptr<BaseButton> m_pAceitarButton;
		std::shared_ptr<BaseButton> m_pOkButton;
		std::shared_ptr<BaseButton> m_pRecusarButton;
		std::shared_ptr<BaseButton> m_pPedirButton;

		CommonEventHandle m_aceiteEventHandler;
		CommonEventHandle m_okEventHandler;
		CommonEventHandle m_recusarEventHandler;
		CommonEventHandle m_pedirEventHandler;

		void loadIcon();

	public:
		Dialog(CWnd* window, int x, int y, DialogType type, std::wstring message, bool isVisible = false,
			CommonEventHandle aceiteEventHandler = nullptr, CommonEventHandle recusarEventHandler = nullptr, CommonEventHandle pedirEventHandler = nullptr, CommonEventHandle okEventHandler = nullptr);

		void setMessage(std::wstring message);

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
		bool m_isVisible;
		CommonEventHandle m_aceiteEventHandler;
		CommonEventHandle m_okEventHandler;
		CommonEventHandle m_recusarEventHandler;
		CommonEventHandle m_pedirEventHandler;
		CWnd* m_parent;

	public:
		DialogBuilder(CWnd* parent);
		std::shared_ptr<Dialog> build();
		DialogBuilder WithDialogType(DialogType type);
		DialogBuilder WithMessage(std::wstring message);
		DialogBuilder WithPosition(int x, int y);
		DialogBuilder WithVisible(bool isVisible);
		DialogBuilder WithAceitarButton(CommonEventHandle eventHandler);
		DialogBuilder WithOkButton(CommonEventHandle eventHandler);
		DialogBuilder WithRecusarButton(CommonEventHandle eventHandler);
		DialogBuilder WithPedirButton(CommonEventHandle eventHandler);
	};

}