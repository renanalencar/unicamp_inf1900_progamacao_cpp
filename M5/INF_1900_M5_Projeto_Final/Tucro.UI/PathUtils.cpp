#include "PathUtils.h"


std::wstring PathUtils::getPathAssets()
{     
    return  BASE_PATH + L"/" + ASSETS_PATH;
}

void PathUtils::loadImage(const std::wstring imgName, std::shared_ptr<CStatic> canvas)
{
	std::wstring filename = getPathAssets() + L"/" + imgName;

	HBITMAP IntroPix = (HBITMAP)LoadImage(NULL, filename.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);	

	if (IntroPix) {		
		canvas->SetBitmap(IntroPix);
	}
	else
	{
		std::wstring error = L"Falha ao carregar a image: " + filename;
		AfxMessageBox(error.c_str(), MB_OK);
	}
}

HBITMAP PathUtils::loadBitmap(const std::wstring imgName)
{
	std::wstring filename = getPathAssets() + L"/" + imgName;

	HBITMAP bitmap = (HBITMAP)LoadImage(NULL, filename.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (!bitmap) {
		std::wstring error = L"Falha ao carregar a image: " + filename;
		AfxMessageBox(error.c_str(), MB_OK);
	}

	return bitmap;
}

HBITMAP PathUtils::getCardTexture(const CardValues& valor, const Naipe& naipe)
{
	std::wstring filename = getPathAssets() + L"/cartas/";

	switch (valor)
	{
		case CardValues::A: filename += L"a_"; break;
		case CardValues::DOIS: filename += L"2_"; break;
		case CardValues::TRES: filename += L"3_"; break;
		case CardValues::QUATRO: filename += L"4_"; break;
		case CardValues::CINCO: filename += L"5_"; break;
		case CardValues::SEIS: filename += L"6_"; break;
		case CardValues::SETE: filename += L"7_"; break;
		case CardValues::OITO: filename += L"8_"; break;
		case CardValues::NOVE: filename += L"9_"; break;
		case CardValues::DEZ: filename += L"10_"; break;
		case CardValues::VALET: filename += L"j_"; break;
		case CardValues::QUEEN: filename += L"q_"; break;
		case CardValues::KING: filename += L"k_"; break;
		default:
		break;
	}

	switch (naipe)
	{
		case Naipe::PAUS: filename += L"paus"; break;
		case Naipe::ESPADAS: filename += L"espadas"; break;
		case Naipe::COPAS: filename += L"copas"; break;
		case Naipe::OUROS: filename += L"ouros"; break;
		default:
		break;
	}
	filename += L".bmp";

	HBITMAP bitmap = (HBITMAP)LoadImage(NULL, filename.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (!bitmap) {
		std::wstring error = L"Falha ao carregar a image: " + filename;
		AfxMessageBox(error.c_str(), MB_OK);
	}

	return bitmap;	
}

HBITMAP PathUtils::getHUDTexture(std::wstring hudTextureName)
{
	std::wstring filename = getPathAssets() + L"/hud/";
	filename += hudTextureName;	

	HBITMAP bitmap = (HBITMAP)LoadImage(NULL, filename.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (!bitmap) {
		std::wstring error = L"Falha ao carregar a image: " + filename;
		AfxMessageBox(error.c_str(), MB_OK);
	}

	return bitmap;
}

HBITMAP PathUtils::getButtonTexture(TypeButton type)
{
	switch (type) {
		case TypeButton::PlayerTruco:
			return getHUDTexture(IMG_TRUCO_PLAYER_BUTTON_RECT);
		case TypeButton::DialogAceitar:
			return getHUDTexture(IMG_DIALOG_BUTTON_ACEITAR);
		case TypeButton::DialogRecusar:
			return getHUDTexture(IMG_DIALOG_BUTTON_RECUSAR);
		case TypeButton::DialogPedirSeis:
			return getHUDTexture(IMG_DIALOG_BUTTON_PEDIR_6);
		case TypeButton::DialogPedirNove:
			return getHUDTexture(IMG_DIALOG_BUTTON_PEDIR_9);
		case TypeButton::DialogPedirDoze:
			return getHUDTexture(IMG_DIALOG_BUTTON_PEDIR_12);
	}
}

HBITMAP PathUtils::getDialogTexture(std::wstring hudTextureName)
{
	return getHUDTexture(hudTextureName);
}
