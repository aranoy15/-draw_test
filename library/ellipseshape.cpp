#include <library/ellipseshape.hpp>

EllipseShape::EllipseShape(const QRect &rect)
    : RectShape(rect)
{
}

EllipseShape::EllipseShape(QRect&& rect)
    : RectShape(std::move(rect))
{
}

EllipseShape::~EllipseShape() {}

EllipseShape::EllipseShape(const EllipseShape &other) noexcept
    : RectShape(other)
{
}

EllipseShape::EllipseShape(EllipseShape &&other) noexcept
    : RectShape(std::move(other))
{
}

EllipseShape &EllipseShape::operator=(const EllipseShape &other) noexcept
{
    RectShape::operator=(other);
    return *this;
}

EllipseShape &EllipseShape::operator=(EllipseShape&& other) noexcept
{
    RectShape::operator=(other);
    return *this;
}

void EllipseShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawEllipse(_rect);
}