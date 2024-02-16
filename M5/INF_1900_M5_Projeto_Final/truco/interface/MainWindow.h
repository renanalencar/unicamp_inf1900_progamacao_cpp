#pragma once
#include <memory>
#include <afxwin.h>
#include "CustomLabel.h"
#include "../jogo.hpp"
#include "Dialog.h"
#include "MainWindowsViewModel.h"
#include "JogadorToPlayerConverter.h"

namespace ui {	
	class MainWindow : public CFrameWnd, public BaseView<MainWindowsViewModel>
	{
	private:					
		std::shared_ptr<CStatic> m_texturaFundo;
		std::unique_ptr<CustomLabel> m_panelRodada;

		std::shared_ptr<Dialog> m_dialog;
		std::unique_ptr<DialogBuilder> m_dialog_builder;

		void initComponentes();
		void initTexturas();

		void updateRodada();
		void updateJogadores();

	public:
		MainWindow();
		virtual ~MainWindow();

		afx_msg void OnButtonMsgClick();
		afx_msg void OnButtonMsgClick2();
		void OnLButtonDown(UINT nFlags, CPoint point);

		DECLARE_MESSAGE_MAP();

		// Inherited via BaseView
		void update() override;
	};
}



