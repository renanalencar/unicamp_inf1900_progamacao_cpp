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
