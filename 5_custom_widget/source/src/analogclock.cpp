#include "source/inc/analogclock.h"
#include <QTimer>
#include <QTime>
#include <QPainter>

AnalogClock::AnalogClock(QWidget *parent)
			:QWidget(parent)
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout), this, SLOT(update()));
	timer->start(1000);
	setWindowTitle(tr("Analog Clock"));
	resize(200, 200);
}

void AnalogClock::paintEvent(QPaintEvent *event)
{
	static const QPoint hourHand[4] = {
		QPoint(7, 8),
		QPoint(0, -8),
		QPoint(-7, 8),
		QPoint(0, -40)
	};
	static const QPoint minuteHand[4] = {
		QPoint(7, 8),
		QPoint(0, -8),
		QPoint(-7, 8),
		QPoint(0, -70)
	};
	QColor hourColor(127, 0, 127);
	QColor minuteColor(0, 127, 127, 191);

	int side = qMin(width(), height());
	QTime time = QTime::currentTime();

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(width() / 2, height() / 2);
	painter.scale(side / 200.0f, side / 200.0f);
	painter.setPen(Qt::NoPen);
	painter.setBrush(hourColor);

	painter.save();
	painter.rotate(30.0f * ((time.hour() + time.minute() / 60.0f)));
	painter.drawConvexPolygon(hourHand, 4);
	painter.restore();

	painter.setPen(hourColor);
	for (int i = 0; i < 12; ++i) {
		painter.drawLine(88, 0, 96, 0);
		painter.rotate(30.0f);
	}

	painter.setPen(Qt::NoPen);
	painter.setBrush(minuteColor);
	painter.save();
	painter.rotate(6.0f * (time.minute() + time.second() / 60.0f));
	painter.drawConvexPolygon(minuteHand, 4);
	painter.restore();

	painter.setPen(minuteColor);
	for (int i = 0; i < 60;i++) {
		if ((i % 5) != 0)
			painter.drawLine(92, 0, 96, 0);
		painter.rotate(6.0f);
	}
}
