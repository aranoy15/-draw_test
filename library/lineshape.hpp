#pragma once

#include <library/shapebase.hpp>

class LineShape : public ShapeBase
{
public:
    LineShape(const QPoint& first_point, const QPoint& second_point);
    LineShape(QPoint&& first_point, QPoint&& second_point);
    virtual ~LineShape();

    LineShape(const LineShape &other) noexcept;
    LineShape &operator=(const LineShape &other) noexcept;
    LineShape(LineShape &&other) noexcept;
    LineShape &operator=(LineShape&& other) noexcept;

    void draw(QPainter& painter) override;

private:
    QPoint _first_point;
    QPoint _second_point;
};