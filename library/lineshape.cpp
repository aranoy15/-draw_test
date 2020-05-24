#include <library/lineshape.hpp>

LineShape::LineShape(const QPoint& first_point, const QPoint& second_point)
    : ShapeBase(), _first_point(first_point), _second_point(second_point)
{
}

LineShape::LineShape(QPoint&& first_point, QPoint&& second_point)
    : ShapeBase(),
      _first_point(std::move(first_point)),
      _second_point(std::move(second_point))
{
}

LineShape::~LineShape() {}

LineShape::LineShape(const LineShape& other) noexcept
    : ShapeBase(other),
      _first_point(other._first_point),
      _second_point(other._second_point)
{
}

LineShape::LineShape(LineShape&& other) noexcept
    : ShapeBase(std::move(other)),
      _first_point(std::move(other._first_point)),
      _second_point(std::move(other._second_point))
{
}

LineShape &LineShape::operator=(const LineShape &other) noexcept
{
    ShapeBase::operator=(other);
    _first_point = other._first_point;
    _second_point = other._second_point;
    return *this;
}

LineShape &LineShape::operator=(LineShape&& other) noexcept
{
    ShapeBase::operator=(std::move(other));
    _first_point = std::move(other._first_point);
    _second_point = std::move(other._second_point);
    return *this;
}

void LineShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawLine(_first_point, _second_point);
}