#pragma once
#include <stdexcept>
#include <string>

namespace ui {

	class BaseException : public std::exception
	{
	private:
		std::string m_message;

	public:
		explicit BaseException(const std::string& message);
		const char* what() const noexcept override;
	};

}

