#include <library/polygonshape.hpp>

PolygonShape::PolygonShape(const QVector<QPoint> &points)
    : PointsShape(points)
{
}

PolygonShape::PolygonShape(QVector<QPoint> &&points)
    : PointsShape(std::move(points))
{
}

PolygonShape::~PolygonShape() {}

PolygonShape::PolygonShape(const PolygonShape &other) noexcept
    : PointsShape(other)
{
}

PolygonShape::PolygonShape(PolygonShape &&other) noexcept
    : PointsShape(other)
{
}

PolygonShape &PolygonShape::operator=(const PolygonShape &other) noexcept
{
    PointsShape::operator=(other);
    return *this;
}

PolygonShape &PolygonShape::operator=(PolygonShape&& other) noexcept
{
    PointsShape::operator=(other);
    return *this;
}

void PolygonShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawPolygon(_points.data(), _points.size());
}