#pragma once
#include <string>
#include <iostream>
#include <afxwin.h>
#include <afxext.h>
#include <atlimage.h>
#include "AssetsConstants.h"
#include "CardValues.h"
#include "Naipe.h"
#include "TypeButtons.h"

namespace ui {
	const std::wstring BASE_PATH = L"F:/Documentos/Cursos/Curso_c_plus_plus/Trabalhofinal/unicamp_inf1900_progamacao_cpp/M5/INF_1900_M5_Projeto_Final/Tucro.UI";

	class PathUtils
	{
	public:
		static std::wstring getPathAssets();
		static void loadImage(const std::wstring imgName, std::shared_ptr<CStatic> canvas);
		static HBITMAP loadBitmap(const std::wstring imgName);

		static HBITMAP getCardTexture(const CardValues& valor, const Naipe& naipe);
		static HBITMAP getHUDTexture(std::wstring hudTextureName);
		static HBITMAP getButtonTexture(TypeButton type);
		static HBITMAP getDialogTexture(std::wstring hudTextureName);
	};

}