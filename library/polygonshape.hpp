#pragma once

#include <library/pointsshape.hpp>

class PolygonShape : public PointsShape
{
public:
	PolygonShape(const QVector<QPoint> &points);
	PolygonShape(QVector<QPoint> &&points);

	PolygonShape(const PolygonShape &other) noexcept;
	PolygonShape &operator=(const PolygonShape &other) noexcept;
	PolygonShape(PolygonShape &&other) noexcept;
	PolygonShape &operator=(PolygonShape &&other) noexcept;

	virtual ~PolygonShape();

	void draw(QPainter &painter) override;
};