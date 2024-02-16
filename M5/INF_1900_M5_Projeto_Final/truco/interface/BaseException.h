#pragma once
#include <stdexcept>
#include <string>

namespace ui {

	class BaseException : public std::exception
	{

	public:
		BaseException(std::string message);

	};

}

