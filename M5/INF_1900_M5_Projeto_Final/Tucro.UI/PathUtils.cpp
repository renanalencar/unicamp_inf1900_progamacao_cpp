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

HBITMAP PathUtils::getTexture(const CartaValor& valor, const Naipe& naipe)
{
	std::wstring filename = getPathAssets() + L"/cartas/";

	switch (valor)
	{
		case CartaValor::A: filename += L"a_"; break;
		case CartaValor::DOIS: filename += L"2_"; break;
		case CartaValor::TRES: filename += L"3_"; break;
		case CartaValor::QUATRO: filename += L"4_"; break;
		case CartaValor::CINCO: filename += L"5_"; break;
		case CartaValor::SEIS: filename += L"6_"; break;
		case CartaValor::SETE: filename += L"7_"; break;
		case CartaValor::OITO: filename += L"8_"; break;
		case CartaValor::NOVE: filename += L"9_"; break;
		case CartaValor::DEZ: filename += L"10_"; break;
		case CartaValor::VALET: filename += L"j_"; break;
		case CartaValor::QUEEN: filename += L"q_"; break;
		case CartaValor::KING: filename += L"k_"; break;
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
