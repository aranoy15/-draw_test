#include <library/pointsshape.hpp>

PointsShape::PointsShape(const QVector<QPoint> &points)
    : ShapeBase(), _points(points)
{
}

PointsShape::PointsShape(QVector<QPoint> &&points)
    : ShapeBase(), _points(std::move(points))
{
}

PointsShape::~PointsShape() {}

PointsShape::PointsShape(const PointsShape &other) noexcept
    : ShapeBase(other),
      _points(other._points)
{
}

PointsShape::PointsShape(PointsShape &&other) noexcept
    : ShapeBase(other),
      _points(std::move(other._points))
{
}

PointsShape &PointsShape::operator=(const PointsShape &other) noexcept
{
    ShapeBase::operator=(other);
    _points = other._points;
    return *this;
}

PointsShape &PointsShape::operator=(PointsShape&& other) noexcept
{
    ShapeBase::operator=(other);
    _points = std::move(other._points);
    return *this;
}

void PointsShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawPoints(_points.data(), _points.size());
}