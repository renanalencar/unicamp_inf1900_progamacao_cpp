#include "BaseException.h"

namespace ui {

	BaseException::BaseException(const std::string& message) : m_message(m_message)	{}

	const char* BaseException::what() const noexcept
	{
		return m_message.c_str();
	}

}