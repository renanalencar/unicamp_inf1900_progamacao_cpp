#pragma once
#include <afxwin.h>
#include <string>
#include <memory>
#include "PathUtils.h"

namespace ui {
	const UINT ID_TEXTURA_COPAS = 1001;
	const UINT ID_TEXTURA_PAUS = 1002;
	const UINT ID_TEXTURA_OUROS = 1003;
	const UINT ID_TEXTURA_ESPADAS = 1004;


	struct ConstTexture
	{
		UINT ID;
		HBITMAP textura;
		ConstTexture(uint16_t id, const HBITMAP& tex) : ID(id), textura(tex) {}
	};


	class TextureFactory
	{
	private:
		std::shared_ptr<ConstTexture> m_pCartaPaus;
		std::shared_ptr<ConstTexture> m_pCartaCopas;
		std::shared_ptr<ConstTexture> m_pCartaOuros;
		std::shared_ptr<ConstTexture> m_pCartaEspadas;
		std::shared_ptr<ConstTexture> m_pCartaBack;
		std::shared_ptr<ConstTexture> m_pBackground;

		TextureFactory();

	public:
		static std::shared_ptr<TextureFactory> getInstance();

		std::shared_ptr<ConstTexture> getCartaPaus();
		std::shared_ptr<ConstTexture> getCartaCopas();
		std::shared_ptr<ConstTexture> getCartaOuros();
		std::shared_ptr<ConstTexture> getCartaEspadas();
		std::shared_ptr<ConstTexture> getCartaBack();
		std::shared_ptr<ConstTexture> getBackground();
	};

}