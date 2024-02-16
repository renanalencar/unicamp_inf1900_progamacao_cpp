#include "BaseException.h"

namespace ui {

	BaseException::BaseException(std::string message)
	{
		const char* _Message = message.c_str();
		std::exception(_Message);
	}
}