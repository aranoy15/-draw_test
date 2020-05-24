#include <widgets/renderarea.hpp>

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), _shape(), _pen(), _brush()
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::set_shape(const QSharedPointer<ShapeBase>& shape)
{
    _shape = shape;
    update();
}

void RenderArea::set_pen(const QPen &pen)
{
    _pen = pen;
    update();
}

void RenderArea::set_brush(const QBrush &brush)
{
    _brush = brush;
    update();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    if (_shape) {
        _shape->set_pen(_pen);
        _shape->set_brush(_brush);

        QPainter painter(this);

		for (int x = 0; x < width(); x += 100) {
			for (int y = 0; y < height(); y += 100) {
				painter.save();
				painter.translate(x, y);

				_shape->draw(painter);
                painter.restore();
			}
		}

        painter.setRenderHint(QPainter::Antialiasing, false);
		painter.setPen(palette().dark().color());
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
	}
}