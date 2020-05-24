#include <widgets/mainwindow.hpp>
#include <library/lineshape.hpp>
#include <library/pointsshape.hpp>
#include <library/polylineshape.hpp>
#include <library/rectshape.hpp>
#include <library/ellipseshape.hpp>
#include <QtWidgets>

Window::Window()
    : _render_area(new RenderArea),
      _shape_label(new QLabel(tr("Shape:"))),
      _pen_width_label(new QLabel(tr("Pen Width: "))),
      _pen_style_label(new QLabel(tr("Pen Style: "))),
      _pen_cap_label(new QLabel(tr("Pen Cap: "))),
      _pen_join_label(new QLabel(tr("Pen Join: "))),
      _brush_style_label(new QLabel(tr("Brush: "))),
      _shape_combo_box(new QComboBox),
      _pen_width_spin_box(new QSpinBox),
      _pen_style_combo_box(new QComboBox),
      _pen_cap_combo_box(new QComboBox),
      _pen_join_combo_box(new QComboBox),
      _brush_style_combo_box(new QComboBox),
      _data(),
      _rect(10, 20, 80, 60),
      _points({QPoint(10, 80), QPoint(20, 10), QPoint(80, 30), QPoint(90, 70)})
{

	_data["Line"] = ShapeBase::make_shape<LineShape>(_rect.bottomLeft(), _rect.topRight()).staticCast<ShapeBase>();
    _data["Points"] = ShapeBase::make_shape<PointsShape>(_points).staticCast<ShapeBase>();
    _data["Polyline"] = ShapeBase::make_shape<PolylineShape>(_points).staticCast<ShapeBase>();
    _data["Rectangle"] = ShapeBase::make_shape<RectShape>(_rect).staticCast<ShapeBase>();
    _data["Ellipse"] = ShapeBase::make_shape<EllipseShape>(_rect).staticCast<ShapeBase>();

    for (auto& t : _data.keys()) {
        _shape_combo_box->addItem(t);
    }

    _pen_width_spin_box->setRange(0, 20);
    _pen_width_spin_box->setSpecialValueText(tr("0 (cosmetic pen)"));

    _pen_style_combo_box->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    _pen_style_combo_box->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    _pen_style_combo_box->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    _pen_style_combo_box->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    _pen_style_combo_box->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    _pen_style_combo_box->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    _pen_cap_combo_box->addItem(tr("Flat"), Qt::FlatCap);
    _pen_cap_combo_box->addItem(tr("Square"), Qt::SquareCap);
    _pen_cap_combo_box->addItem(tr("Round"), Qt::RoundCap);

    _pen_join_combo_box->addItem(tr("Miter"), Qt::MiterJoin);
    _pen_join_combo_box->addItem(tr("Bevel"), Qt::BevelJoin);
    _pen_join_combo_box->addItem(tr("Round"), Qt::RoundJoin);

    _brush_style_combo_box->addItem(tr("Linear Gradient"), static_cast<int>(Qt::LinearGradientPattern));
    _brush_style_combo_box->addItem(tr("Radial Gradient"), static_cast<int>(Qt::RadialGradientPattern));
    _brush_style_combo_box->addItem(tr("Conical Gradient"), static_cast<int>(Qt::ConicalGradientPattern));
    _brush_style_combo_box->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    _brush_style_combo_box->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    _brush_style_combo_box->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    _brush_style_combo_box->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    _brush_style_combo_box->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    _brush_style_combo_box->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    _brush_style_combo_box->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    _brush_style_combo_box->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    _brush_style_combo_box->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    _brush_style_combo_box->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    _brush_style_combo_box->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    _brush_style_combo_box->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    _brush_style_combo_box->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    _brush_style_combo_box->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    _brush_style_combo_box->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    connect(_shape_combo_box, QOverload<int>::of(&QComboBox::activated), this, &Window::shape_changed);
    connect(_pen_width_spin_box, QOverload<int>::of(&QSpinBox::valueChanged), this, &Window::pen_changed);
    connect(_pen_style_combo_box, QOverload<int>::of(&QComboBox::activated), this, &Window::pen_changed);
    connect(_pen_cap_combo_box, QOverload<int>::of(&QComboBox::activated), this, &Window::pen_changed);
    connect(_pen_join_combo_box, QOverload<int>::of(&QComboBox::activated), this, &Window::pen_changed);
    connect(_brush_style_combo_box, QOverload<int>::of(&QComboBox::activated), this, &Window::brush_changed);

    QGridLayout *main_layout = new QGridLayout;

    main_layout->setColumnStretch(0, 1);
    main_layout->setColumnStretch(3, 1);
    main_layout->addWidget(_render_area, 0, 0, 1, 4);
    main_layout->addWidget(_shape_label, 2, 0, Qt::AlignRight);
    main_layout->addWidget(_shape_combo_box, 2, 1);
    main_layout->addWidget(_pen_width_label, 3, 0, Qt::AlignRight);
    main_layout->addWidget(_pen_width_spin_box, 3, 1);
    main_layout->addWidget(_pen_style_label, 4, 0, Qt::AlignRight);
    main_layout->addWidget(_pen_style_combo_box, 4, 1);
    main_layout->addWidget(_pen_cap_label, 3, 2, Qt::AlignRight);
    main_layout->addWidget(_pen_cap_combo_box, 3, 3);
    main_layout->addWidget(_pen_join_label, 2, 2, Qt::AlignRight);
    main_layout->addWidget(_pen_join_combo_box, 2, 3);
    main_layout->addWidget(_brush_style_label, 4, 2, Qt::AlignRight);
    main_layout->addWidget(_brush_style_combo_box, 4, 3);
    setLayout(main_layout);

    setWindowTitle(tr("Рисовальщик"));

    connect(this, &Window::set_shape, _render_area, &RenderArea::set_shape);
    connect(this, &Window::set_pen, _render_area, &RenderArea::set_pen);
    connect(this, &Window::set_brush, _render_area, &RenderArea::set_brush);

    shape_changed();
    pen_changed();
    brush_changed();
}

void Window::shape_changed()
{
    QString key = _shape_combo_box->currentText();
    _render_area->set_shape(_data[key]);
}

void Window::pen_changed()
{
    int width = _pen_width_spin_box->value();
    Qt::PenStyle style = Qt::PenStyle(_pen_style_combo_box->itemData(_pen_style_combo_box->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(_pen_cap_combo_box->itemData(_pen_cap_combo_box->currentIndex()).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(_pen_join_combo_box->itemData(_pen_join_combo_box->currentIndex()).toInt());

    QPen pen(Qt::blue, width, style, cap, join);

    emit set_pen(pen);
}

void Window::brush_changed()
{
	Qt::BrushStyle style = Qt::BrushStyle(
	    _brush_style_combo_box->itemData(_brush_style_combo_box->currentIndex())
	        .toInt());
    

    QBrush brush;

	if (style == Qt::LinearGradientPattern) {
        QLinearGradient linear_gradient(0, 0, 100, 100);
        linear_gradient.setColorAt(0.0, Qt::white);
        linear_gradient.setColorAt(0.2, Qt::green);
        linear_gradient.setColorAt(1.0, Qt::black);
        brush = linear_gradient;
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radial_gradient(50, 50, 50, 70, 70);
        radial_gradient.setColorAt(0.0, Qt::white);
        radial_gradient.setColorAt(0.2, Qt::green);
        radial_gradient.setColorAt(1.0, Qt::black);
        brush = radial_gradient;
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conical_gradient(50, 50, 150);
        conical_gradient.setColorAt(0.0, Qt::white);
        conical_gradient.setColorAt(0.2, Qt::green);
        conical_gradient.setColorAt(1.0, Qt::black);
        brush = conical_gradient;
    } else {
        brush = QBrush(Qt::green, style);
    }

    emit set_brush(brush);
}