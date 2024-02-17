#include "TextureFactory.h"

TextureFactory::TextureFactory()
{	
	m_pCartaPaus = std::make_shared<ConstTexture>(ID_TEXTURA_PAUS, PathUtils::loadBitmap(IMG_NIPE_PAUS));
	m_pCartaCopas = std::make_shared<ConstTexture>(ID_TEXTURA_COPAS, PathUtils::loadBitmap(IMG_NIPE_COPAS));
	m_pCartaEspadas = std::make_shared<ConstTexture>(ID_TEXTURA_ESPADAS, PathUtils::loadBitmap(IMG_NIPE_ESPADAS));
	m_pCartaOuros = std::make_shared<ConstTexture>(ID_TEXTURA_OUROS, PathUtils::loadBitmap(IMG_NIPE_OUROS));
	m_pCartaBack = std::make_shared<ConstTexture>(1005, PathUtils::loadBitmap(IMG_BACK_CARTA));
	m_pBackground = std::make_shared<ConstTexture>(1006, PathUtils::loadBitmap(IMG_BACKGROUND));	
}

std::shared_ptr<TextureFactory> TextureFactory::getInstance()
{
	static std::shared_ptr<TextureFactory> m_instance;

	if (!m_instance) {
		m_instance = std::shared_ptr<TextureFactory>(new TextureFactory());
	}
    return m_instance;
}

std::shared_ptr<ConstTexture> TextureFactory::getCartaPaus()
{
	return m_pCartaPaus;
}

std::shared_ptr<ConstTexture> TextureFactory::getCartaCopas()
{
	return m_pCartaCopas;
}

std::shared_ptr<ConstTexture> TextureFactory::getCartaOuros()
{
	return m_pCartaOuros;
}

std::shared_ptr<ConstTexture> TextureFactory::getCartaEspadas()
{
	return m_pCartaEspadas;
}

std::shared_ptr<ConstTexture> TextureFactory::getCartaBack()
{
	return m_pCartaBack;
}

std::shared_ptr<ConstTexture> TextureFactory::getBackground()
{
	return m_pBackground;
}
