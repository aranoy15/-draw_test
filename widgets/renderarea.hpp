#pragma once

#include <QWidget>
#include <QPen>
#include <library/shapebase.hpp>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void set_shape(const QSharedPointer<ShapeBase>& shape);
    void set_pen(const QPen &pen);
	void set_brush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QSharedPointer<ShapeBase> _shape;
    QPen _pen;
    QBrush _brush;
};