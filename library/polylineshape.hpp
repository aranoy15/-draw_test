#pragma once

#include <library/pointsshape.hpp>

class PolylineShape : public PointsShape
{
public:
	PolylineShape(const QVector<QPoint> &points);
	PolylineShape(QVector<QPoint> &&points);

	PolylineShape(const PolylineShape &other) noexcept;
	PolylineShape &operator=(const PolylineShape &other) noexcept;
	PolylineShape(PolylineShape &&other) noexcept;
	PolylineShape &operator=(PolylineShape &&other) noexcept;

	virtual ~PolylineShape();

	void draw(QPainter &painter) override;
};