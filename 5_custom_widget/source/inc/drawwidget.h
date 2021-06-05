#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QColor>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>

class DrawWidget : public QWidget
{
	Q_OBJECT
public:
	DrawWidget();
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
	QColor getColor();
public slots:
	void setStyle(int);
	void setWidth(int);
	void setColor(QColor);
	void clear();
private:
	QPixmap *pix;
	QPoint startPos;
	QPoint endPos;
	int style;
	int weight;
	QColor color;
};
#endif
