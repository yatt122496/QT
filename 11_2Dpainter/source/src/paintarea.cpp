#include "source/inc/paintarea.h"
#include <QtGui>
#include <QGridLayout>
#include <QFile>

PaintArea::PaintArea(QWidget *parent)
		: QWidget(parent)
{
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);
	setMinimumSize(300, 300);
}

void PaintArea::setShape(Shape s)
{
	shape = s;
	update();
}

void PaintArea::setPen(QPen p)
{
	pen = p;
	update();
}

void PaintArea::setBrush(QBrush b)
{
	brush = b;
	update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
	fillRule = rule;
	update();
}

void PaintArea::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setPen(pen);
	p.setBrush(brush);
	QRect rect(size().width() / 4, size().height() / 4, size().width() / 2, size().height() / 2);

	static const QPoint points[4] = {
		QPoint(size().width() / 4, size().height() / 4),
		QPoint(size().width() / 2, size().height() * 3 / 8),
		QPoint(size().width() * 3 / 4, size().height() * 5 / 8),
		QPoint(size().width() * 3 / 8, size().height() * 3 / 4)
	};

	int startAngle = 60 * 16;
	int spenAngle = 180 * 16;

	QPainterPath path;
	path.moveTo(size().width() / 8, size().height() * 3 / 8);
	path.lineTo(size().width() * 7 / 8, size().height() * 3 / 8);
	path.lineTo(size().width() / 4, size().height() * 5 / 6);
	path.lineTo(size().width() / 2, size().height() / 8);
	path.lineTo(size().width() * 3 / 4, size().height() * 5 / 6);
	path.lineTo(size().width() / 8, size().height() * 3 / 8);
	path.setFillRule(fillRule);

	switch (shape) {
	case Line: {	//直线
		p.drawLine(rect.topLeft(), rect.bottomRight());
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawLine(rect.topLeft(), rect.bottomRight());
		}
		break;
	}
	case Rectangle: {	//长方形
		p.drawRect(rect);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawRect(rect);
		}
		break;
	}
	case RoundRect: {	//圆角方形
		p.drawRoundRect(rect);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawRoundRect(rect);
		}
		break;
	}
	case Ellipse: {		//椭圆形
		p.drawEllipse(rect);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawEllipse(rect);
		}
		break;
	}
	case Polygon: {		//多边形
		p.drawPolygon(points, 4);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawPolygon(points, 4);
		}
		break;
	}
	case Polyline: {	//多变线
		p.drawPolyline(points, 4);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawPolyline(points, 4);
		}
		break;
	}
	case Points: {		//点
		p.drawPoints(points, 4);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawPoints(points, 4);
		}
		break;
	}
	case Arc: {		//弧
		p.drawArc(rect, startAngle, spenAngle);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawArc(rect, startAngle, spenAngle);
		}
		break;
	}
	case Path: {	//路径
		p.drawPath(path);
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawPath(path);
		}
		break;
	}
	case Text: {	//文字
		p.drawText(rect, Qt::AlignCenter, "Hello Qt!");
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			p.drawText(rect, Qt::AlignCenter, "Hello Qt!");
		}
		break;
	}
	case Pixmap: {		//图片
		p.drawPixmap(size().width() * 3 / 8, size().height() * 3 / 8, QPixmap(":Resource/images/select.png"));
		if (translateFlag || scaleFlag || rotateFlag) {
			p.setBrush(Qt::red);
			if (translateFlag) p.translate(20, 20);
			if (scaleFlag) p.scale(0.5, 0.5);
			if (rotateFlag) p.rotate(30);
			if (shearFlag) p.shear(0.5, 0);
			p.drawPixmap(size().width() * 3 / 8, size().height() * 3 / 8, QPixmap(":Resource/images/select.png"));
		}
		break;
	}
	default:
		break;
	}
}

void PaintArea::saveImage()
{
	QPixmap pix = this->grab(QRect(0, 0, size().width(), size().height()));
	QFile file("img.png");
	if (!file.open(QIODevice::ReadWrite)) {
		qDebug() <<"Open false";
		return;
	}
	QByteArray ba;
	QBuffer buffer(&ba);
	buffer.open(QIODevice::WriteOnly);
	pix.save(&buffer, "PNG");
	file.write(ba);
	file.close();
}

void PaintArea::translateImage()
{
	translateFlag = !translateFlag;
	update();
}

void PaintArea::scaleImage()
{
	scaleFlag = !scaleFlag;
	update();
}

void PaintArea::shearImage()
{
	shearFlag = !shearFlag;
	update();
}

void PaintArea::rotateImage()
{
	rotateFlag = !rotateFlag;
	update();
}
