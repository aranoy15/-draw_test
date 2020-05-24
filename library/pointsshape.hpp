#pragma once

#include <library/shapebase.hpp>

class PointsShape : public ShapeBase
{
public:
    PointsShape(const QVector<QPoint>& points); 
    PointsShape(QVector<QPoint>&& points);
    virtual ~PointsShape();

    PointsShape(const PointsShape &other) noexcept;
    PointsShape &operator=(const PointsShape &other) noexcept;
    PointsShape(PointsShape &&other) noexcept;
    PointsShape &operator=(PointsShape&& other) noexcept;

    void draw(QPainter& painter) override;

protected:
    QVector<QPoint> _points;
};