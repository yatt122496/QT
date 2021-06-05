#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPainter>

class PaintArea : public QWidget
{
	Q_OBJECT
public:
	PaintArea(QWidget *parent = 0);
	enum Shape{ Line, Rectangle, RoundRect, Ellipse,
		Polygon, Polyline, Points, Arc, Path, Text, Pixmap };
	void setShape(Shape);
	void setPen(QPen);
	void setBrush(QBrush);
	void setFillRule(Qt::FillRule);
	void paintEvent(QPaintEvent *);

public slots:
	void saveImage();
	void translateImage();
	void scaleImage();
	void shearImage();
	void rotateImage();

private:
	Shape shape;
	QPen pen;
	QBrush brush;
	Qt::FillRule fillRule;
	int translateFlag = 0;
	int scaleFlag = 0;
	int shearFlag = 0;
	int rotateFlag = 0;
};
#endif
