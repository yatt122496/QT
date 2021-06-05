#include "source/inc/ticker.h"
#include <QtGui>
#include <QGridLayout>

Ticker::Ticker(QWidget *parent)
	: QWidget(parent)
{
	offset = 0;
	myTimerId = 0;
	setWindowTitle("Ticker");
	setText("Ticker......");
}

void Ticker::setText(const QString &newText)
{
	myText = newText;
	update();
	updateGeometry();
}

QSize Ticker::sizeHint() const
{
	return fontMetrics().size(0, text());
}

void Ticker::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	int textWidth = fontMetrics().width(text());
	if (textWidth < 1)
		return;
	int x = -offset;
	while (x < width()) {
		painter.drawText(x, 0, textWidth, height(),
				Qt::AlignLeft|Qt::AlignVCenter, text());
		x += textWidth;
	}
}

void Ticker::showEvent(QShowEvent *)
{
	myTimerId = startTimer(30);
}

void Ticker::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == myTimerId) {
		++offset;
		if (offset >= fontMetrics().width(text()))
			offset = 0;
		// qDebug() <<offset;
		scroll(-1, 0);
	} else {
		QWidget::timerEvent(event);
	}
}

void Ticker::hideEvent(QHideEvent *)
{
	killTimer(myTimerId);
}
