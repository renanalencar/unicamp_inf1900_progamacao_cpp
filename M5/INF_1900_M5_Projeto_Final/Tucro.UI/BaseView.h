#pragma once
#include <memory>

template <class V>
class BaseView
{
protected:
	std::shared_ptr<V> m_pViewModel;

public:
	std::shared_ptr<V> getViewModel();
	virtual void update() = 0;
};

template<class V>
inline std::shared_ptr<V> BaseView<V>::getViewModel()
{
	return m_pViewModel;
}
