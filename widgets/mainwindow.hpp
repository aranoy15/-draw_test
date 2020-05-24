#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <widgets/renderarea.hpp>
#include <library/shapebase.hpp>
#include <QHash>
#include <QRect>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

signals:
    void set_shape(const QSharedPointer<ShapeBase>& shape);
    void set_pen(const QPen& pen);
    void set_brush(const QBrush& brush);

private slots:
    void shape_changed();
    void pen_changed();
    void brush_changed();

private:
	RenderArea* _render_area;
	QLabel *_shape_label;
	QLabel *_pen_width_label;
	QLabel *_pen_style_label;
	QLabel *_pen_cap_label;
	QLabel *_pen_join_label;
	QLabel *_brush_style_label;
	QComboBox *_shape_combo_box;
	QSpinBox *_pen_width_spin_box;
	QComboBox *_pen_style_combo_box;
	QComboBox *_pen_cap_combo_box;
	QComboBox *_pen_join_combo_box;
	QComboBox *_brush_style_combo_box;

	QHash<QString, QSharedPointer<ShapeBase>> _data;   

    QRect _rect;
	QVector<QPoint> _points;
};