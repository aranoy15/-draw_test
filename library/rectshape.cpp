#include <library/rectshape.hpp>

RectShape::RectShape(const QRect &rect)
    : ShapeBase(), _rect(rect)
{
}

RectShape::RectShape(QRect&& rect)
    : ShapeBase(), _rect(std::move(rect))
{
}

RectShape::~RectShape() {}

RectShape::RectShape(const RectShape &other) noexcept
    : ShapeBase(other),
      _rect(other._rect)
{
}

RectShape::RectShape(RectShape &&other) noexcept
    : ShapeBase(other),
      _rect(std::move(other._rect))
{
}

RectShape &RectShape::operator=(const RectShape &other) noexcept
{
    ShapeBase::operator=(other);
    _rect = other._rect;
    return *this;
}

RectShape &RectShape::operator=(RectShape&& other) noexcept
{
    ShapeBase::operator=(other);
    _rect = std::move(other._rect);
    return *this;
}

void RectShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawRect(_rect);
}