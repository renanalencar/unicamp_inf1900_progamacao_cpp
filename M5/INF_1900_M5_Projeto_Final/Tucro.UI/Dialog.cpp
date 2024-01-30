#include "Dialog.h"

void Dialog::loadIcon()
{
	switch (m_dialogType)
	{
	case DialogType::PedirSeis:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_6));
		break;
	case DialogType::PedirNove:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_9));
		break;
	case DialogType::PedirDoze:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_12));
		break;
	case DialogType::Error:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_ERROR));
		break;
	case DialogType::Info:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_INFO));
		break;
	case DialogType::Quest:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_QUEST));
		break;
	case DialogType::Truco:
		m_pIcon->setTexture(PathUtils::getHUDTexture(IMG_DIALOG_ICONE_TRUCO));
		break;
	default:
		break;
	}
}

Dialog::Dialog(CWnd* window, int x, int y, DialogType type, std::wstring message,
	CommonEventHandle aceiteEventHandler, CommonEventHandle recusarEventHandler, CommonEventHandle pedirEventHandler)
	: BaseControl(window, x, y, DIALOG_WIDTH, DIALOG_HEIGHT)
{	
	auto pCanvas = m_pCanvas.get();

	m_dialogType = type;

	m_aceiteEventHandler = aceiteEventHandler;
	m_recusarEventHandler = recusarEventHandler;
	m_pedirEventHandler = pedirEventHandler;

	setTexture(PathUtils::getDialogTexture(IMG_DIALOG_BACKGROUND));

	m_pIcon = std::make_unique<Drawable>(pCanvas, 10, 10, ICON_WIDTH, ICON_HEIGHT);
	loadIcon();

	m_message = std::make_unique<CustomLabel>();
	m_message->Create(nullptr, WS_CHILD | WS_VISIBLE, CRect(190, 30, 550, 100), pCanvas);
	m_message->setTransparent(true);
	m_message->setForegroundColor(RGB(255,255,255));
	m_message->SetWindowTextW(message.c_str());
	m_message->setFontSize(22);
	
	m_pAceitarButton = ButtonFactory::CreateDialogAceitarButton(pCanvas, 180, 120);
	m_pRecusarButton = ButtonFactory::CreateDialogRecusarButton(pCanvas, 320, 120);
	m_pPedirButton = ButtonFactory::CreateDialogPedirButton(pCanvas, 460, 120, TypeButton::DialogPedirSeis);

	m_pAceitarButton->OnLeftMouseButtonDownHandle = [&](int x, int y) {			
		if (m_aceiteEventHandler != nullptr) {
			m_aceiteEventHandler();
		}
	};

	m_pRecusarButton->OnLeftMouseButtonDownHandle = [&](int x, int y) {
		if (m_recusarEventHandler != nullptr) {
			m_recusarEventHandler();
		}
	};

	m_pPedirButton->OnLeftMouseButtonDownHandle = [&](int x, int y) {
		if (m_pedirEventHandler != nullptr) {
			m_pedirEventHandler();
		}
	};
}


void Dialog::draw()
{
	BaseControl::draw();
	m_pIcon->draw();
	m_pAceitarButton->draw();
	m_pRecusarButton->draw();
	m_pPedirButton->draw();
		
	m_pAceitarButton->setVisible(!(!m_aceiteEventHandler));
	m_pRecusarButton->setVisible(!(!m_recusarEventHandler));
	m_pPedirButton->setVisible(!(!m_pedirEventHandler));
}

void Dialog::LeftMouseButtonDown(const CPoint& point)
{
	if (isEnable() && getBounds()->PtInRect(point)) {	

		CPoint dialogPoint(point.x - getBounds()->left, point.y - getBounds()->top);

		m_pAceitarButton->LeftMouseButtonDown(dialogPoint);
		m_pRecusarButton->LeftMouseButtonDown(dialogPoint);
		m_pPedirButton->LeftMouseButtonDown(dialogPoint);
	}
}

DialogBuilder::DialogBuilder(CWnd* parent)
{
	m_parent = parent;

	m_dialogType = DialogType::PedirSeis;
	m_message = L"";
	m_x = 0;
	m_y = 0;
	m_aceiteEventHandler = nullptr;
	m_recusarEventHandler = nullptr;
	m_pedirEventHandler = nullptr;	
}

std::shared_ptr<Dialog> DialogBuilder::build()
{
	return std::make_shared<Dialog>(m_parent, m_x, m_y, m_dialogType, m_message, m_aceiteEventHandler, m_recusarEventHandler, m_pedirEventHandler);
}

DialogBuilder DialogBuilder::WithDialogType(DialogType type)
{
	m_dialogType = type;
	return *this;
}

DialogBuilder DialogBuilder::WithMessage(std::wstring message)
{
	m_message = message;
	return *this;
}

DialogBuilder DialogBuilder::WithPosition(int x, int y)
{
	m_x = x;
	m_y = y;	
	return *this;
}

DialogBuilder DialogBuilder::WithAceitarButton(CommonEventHandle eventHandler)
{
	m_aceiteEventHandler = eventHandler;
	return *this;
}

DialogBuilder DialogBuilder::WithRecusarButton(CommonEventHandle eventHandler)
{
	m_recusarEventHandler = eventHandler;
	return *this;
}

DialogBuilder DialogBuilder::WithPedirButton(CommonEventHandle eventHandler)
{
	m_pedirEventHandler = eventHandler;
	return *this;
}
