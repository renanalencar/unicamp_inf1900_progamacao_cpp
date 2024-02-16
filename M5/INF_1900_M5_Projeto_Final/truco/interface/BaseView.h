#pragma once
#include <memory>
#include "DrawArea.h"

namespace ui {
	template <class VM>
	class BaseView
	{
	protected:
		std::shared_ptr<VM> m_pViewModel;

	public:
		std::shared_ptr<VM> getViewModel();
		virtual void update() = 0;
	};

	template<class VM>
	inline std::shared_ptr<VM> BaseView<VM>::getViewModel()
	{
		return m_pViewModel;
	}
}