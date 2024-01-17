#include "IDrawable.h"

std::shared_ptr<CRect> IDrawable::getBound()
{
    return m_bound;
}

void IDrawable::LeftMouseDownEvent(const CPoint& point)
{
    if (m_bound->PtInRect(point)) {
        onLMouseDown();
    }
}

void IDrawable::draw(){}

void IDrawable::onLMouseDown(){}
