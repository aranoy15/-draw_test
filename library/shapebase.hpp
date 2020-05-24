#pragma once

#include <QPen>
#include <QPainter>
#include <QSharedPointer>

class ShapeBase
{
public:
    ShapeBase();
    virtual ~ShapeBase();

    ShapeBase(const ShapeBase &other) noexcept;
    ShapeBase &operator=(const ShapeBase &other) noexcept;
    ShapeBase(ShapeBase &&other) noexcept;
    ShapeBase &operator=(ShapeBase&& other) noexcept;

    virtual void draw(QPainter &painter) = 0;

    template<class T, class... Arg>
    static QSharedPointer<T> make_shape(Arg&&... args);

	void set_pen(const QPen &pen) { _pen = pen; }
	void set_pen(QPen &&pen) noexcept { _pen = std::move(pen); }

	void set_brush(const QBrush &brush) { _brush = brush; }
	void set_brush(QBrush &&brush) { _brush = std::move(brush); }

protected:
    QPen _pen;
    QBrush _brush;
};

template<class T, class... Arg>
QSharedPointer<T> ShapeBase::make_shape(Arg&&... args)
{
    return QSharedPointer<T>(new T(std::forward<Arg>(args)...));
}