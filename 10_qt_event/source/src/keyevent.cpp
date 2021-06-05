#include "source/inc/keyevent.h"
#include <QtGui>
#include <QGridLayout>

KeyEvent::KeyEvent(QWidget *parent)
		: QWidget(parent)
{
	setWindowTitle("键盘事件");
	setAutoFillBackground(true);

	QPalette palette = this->palette();
	palette.setColor(QPalette::Window, Qt::white);
	setPalette(palette);

	setMinimumSize(600, 400);
	setMaximumSize(800, 480);
	resize(800, 400);

	width = size().width();
	height = size().height();
	pix = new QPixmap(width, height);
	pix->fill(Qt::white);

	image.load(":Resource/images/logo.png");

	startX = 100;
	startY = 100;

	step = 20;

	drawPix();

}

void KeyEvent::drawPix()
{
	pix->fill(Qt::white);
	QPainter *painter = new QPainter;
	QPen pen(Qt::DotLine);

	for (int i = step; i < width; i += step) {
		painter->begin(pix);
		painter->setPen(pen);
		painter->drawLine(QPoint(i, 0), QPoint(i, height));
		painter->end();
	}
	for (int i = step; i < height; i += step) {
		painter->begin(pix);
		painter->setPen(pen);
		painter->drawLine(QPoint(0, i), QPoint(height, i));
		painter->end();
	}
	painter->begin(pix);
	painter->drawImage(QPoint(startX, startY), image);
	painter->end();
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
	if (event->modifiers() == Qt::ControlModifier) {
		if (event->key() == Qt::Key_Left) {
			startX = (startX - 1 < 0) ? startX :startX - 1;
		}
		if (event->key() == Qt::Key_Right) {
			startX = (startX + 1 + image.width() > width) ? startX :startX + 1;
		}
		if (event->key() == Qt::Key_Up) {
			startY = (startY - 1 < 0) ? startY :startY - 1;
		}
		if (event->key() == Qt::Key_Down) {
			startY = (startY + 1 + image.height() > height) ? startY :startY + 1;
		}
	} else {
		startX = startX - startX % step;
		startY = startY - startY % step;

		if (event->key() == Qt::Key_Left) {
			startX = (startX - step < 0) ? startX :startX - step;
		}
		if (event->key() == Qt::Key_Right) {
			startX = (startX + step + image.width() > width) ? startX :startX + step;
		}
		if (event->key() == Qt::Key_Up) {
			startY = (startY - step < 0) ? startY :startY - step;
		}
		if (event->key() == Qt::Key_Down) {
			startY = (startY + step + image.height() > height) ? startY :startY + step;
		}
		if (event->key() == Qt::Key_Home) {
			startX = 0;
			startY = 0;
		}
		if (event->key() == Qt::Key_End) {
			startX = width - image.width();
			startY = height - image.height();
		}
	}
	drawPix();
	update();
}

void KeyEvent::paintEvent(QPaintEvent *)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(QPoint(0, 0), *pix);
	painter.end();
}
