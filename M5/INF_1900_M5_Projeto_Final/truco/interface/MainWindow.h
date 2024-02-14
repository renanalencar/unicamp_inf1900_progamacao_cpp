#pragma once
#include <memory>
#include <afxwin.h>
#include "CustomLabel.h"
#include "../jogo.hpp"
#include "Dialog.h"


namespace ui {

	const int ID_IMG_FUNDO = 1;
	const int MAIN_WINDOW_WIDTH = 1043;
	const int MAIN_WINDOW_HEIGHT = 823;
	
	class MainWindow : public CFrameWnd
	{
	private:	
		std::unique_ptr<Jogo> jogo;

		std::shared_ptr<CStatic> m_texturaFundo;
		std::unique_ptr<CustomLabel> m_panelRodada;

		std::shared_ptr<Dialog> m_dialog;
		std::unique_ptr<DialogBuilder> m_dialog_builder;

		void initComponentes();
		void initTexturas();

	public:
		MainWindow();
		virtual ~MainWindow();

		afx_msg void OnButtonMsgClick();
		afx_msg void OnButtonMsgClick2();
		void OnLButtonDown(UINT nFlags, CPoint point);

		DECLARE_MESSAGE_MAP();
	};
}



