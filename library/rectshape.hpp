#pragma once

#include <library/shapebase.hpp>

class RectShape : public ShapeBase
{
public:
	RectShape(const QRect &rect);
	RectShape(QRect&& rect);
    virtual ~RectShape();

    RectShape(const RectShape &other) noexcept;
    RectShape &operator=(const RectShape &other) noexcept;
    RectShape(RectShape &&other) noexcept;
    RectShape &operator=(RectShape&& other) noexcept;

    void draw(QPainter& painter) override;

protected:
    QRect _rect;
};