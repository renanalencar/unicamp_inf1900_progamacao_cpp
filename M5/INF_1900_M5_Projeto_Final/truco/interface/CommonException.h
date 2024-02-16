#pragma once
#include "BaseException.h"

namespace ui {

	class CommonException :
		public BaseException
	{
	public:
		CommonException(std::string message);
	};

}

