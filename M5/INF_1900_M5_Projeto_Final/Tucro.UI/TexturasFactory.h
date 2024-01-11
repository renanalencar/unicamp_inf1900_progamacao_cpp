#pragma once
#include <afxwin.h>
#include <string>
#include <memory>
#include "PathUtils.h"

struct ConstTexture
{
	uint16_t ID;
	HBITMAP textura;

	ConstTexture(uint16_t id, const HBITMAP& tex): ID(id), textura(tex) {}
};


class TexturasFactory
{
private:
	std::shared_ptr<ConstTexture> m_pCartaPaus;
	std::shared_ptr<ConstTexture> m_pCartaCopas;
	std::shared_ptr<ConstTexture> m_pCartaOuros;
	std::shared_ptr<ConstTexture> m_pCartaEspadas;
	std::shared_ptr<ConstTexture> m_pCartaBack;
	std::shared_ptr<ConstTexture> m_pBackground;

	TexturasFactory();

public:
	static std::shared_ptr<TexturasFactory> getInstance();
	
	std::shared_ptr<ConstTexture> getCartaPaus();
	std::shared_ptr<ConstTexture> getCartaCopas();
	std::shared_ptr<ConstTexture> getCartaOuros();
	std::shared_ptr<ConstTexture> getCartaEspadas();
	std::shared_ptr<ConstTexture> getCartaBack();
	std::shared_ptr<ConstTexture> getBackground();
};

