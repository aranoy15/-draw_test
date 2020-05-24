#include <library/polylineshape.hpp>

PolylineShape::PolylineShape(const QVector<QPoint> &points)
    : PointsShape(points)
{
}

PolylineShape::PolylineShape(QVector<QPoint> &&points)
    : PointsShape(std::move(points))
{
}

PolylineShape::~PolylineShape() {}

PolylineShape::PolylineShape(const PolylineShape &other) noexcept
    : PointsShape(other)
{
}

PolylineShape::PolylineShape(PolylineShape &&other) noexcept
    : PointsShape(other)
{
}

PolylineShape &PolylineShape::operator=(const PolylineShape &other) noexcept
{
    PointsShape::operator=(other);
    return *this;
}

PolylineShape &PolylineShape::operator=(PolylineShape&& other) noexcept
{
    PointsShape::operator=(other);
    return *this;
}

void PolylineShape::draw(QPainter& painter)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);

    painter.drawPolyline(_points.data(), _points.size());
}