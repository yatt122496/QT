#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <QWidget>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>

class MouseEvent : public QWidget
{
	Q_OBJECT
public:
	MouseEvent(QWidget *parent = 0);

protected:
	void drawPix(int x, int y);
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

private:
	QPixmap *pix;
	QImage image;
	QLabel *labelStatus;
	QLabel *labelMousePos;
	int width;
	int height;
};

#endif
