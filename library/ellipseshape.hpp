#pragma once

#include <library/rectshape.hpp>

class EllipseShape : public RectShape
{
public:
	EllipseShape(const QRect &rect);
	EllipseShape(QRect&& rect);
    virtual ~EllipseShape();

    EllipseShape(const EllipseShape &other) noexcept;
    EllipseShape &operator=(const EllipseShape &other) noexcept;
    EllipseShape(EllipseShape &&other) noexcept;
    EllipseShape &operator=(EllipseShape&& other) noexcept;

    void draw(QPainter& painter) override; 
};