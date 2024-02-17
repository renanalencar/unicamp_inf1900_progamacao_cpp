#pragma once
#include "BaseException.h"
#include "CommonException.h"

namespace ui {
	CommonException::CommonException(std::string message) : BaseException(message)
	{
	}
}