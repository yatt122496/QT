#include "source/inc/mouseevent.h"
#include <QtGui>
#include <QGridLayout>

MouseEvent::MouseEvent(QWidget *parent)
		: QWidget(parent)
{
	setWindowTitle("鼠标事件");
	setAutoFillBackground(true);

	labelStatus = new QLabel("");
	labelMousePos = new QLabel("");

	QVBoxLayout *layoutV1 = new QVBoxLayout();
	layoutV1->addWidget(labelStatus);
	layoutV1->addWidget(labelMousePos);
	layoutV1->addStretch();

	QPalette palette = this->palette();
	palette.setColor(QPalette::Window, Qt::white);
	setPalette(palette);

	setMinimumSize(600, 400);
	setMaximumSize(800, 480);

	width = size().width();
	height = size().height();
	pix = new QPixmap(width, height);
	pix->fill(Qt::white);

	image.load(":Resource/images/logo.png");
	drawPix(256, 128);

	QHBoxLayout *layoutMain = new QHBoxLayout();
	layoutMain->addStretch();
	layoutMain->addLayout(layoutV1);
	setLayout(layoutMain);

	this->setMouseTracking(true);

	resize(800, 400);
}

void MouseEvent::drawPix(int x, int y)
{
	pix->fill(Qt::white);
	QPainter *painter = new QPainter;
	painter->begin(pix);
	painter->drawImage(QPoint(x, y), image);
	painter->end();
}

void MouseEvent::mousePressEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
	if (event->button() == Qt::LeftButton) {
		labelMousePos->setText("鼠标左键按下时的位置：" + str);
	} else if (event->button() == Qt::RightButton) {
		labelMousePos->setText("鼠标右键按下时的位置：" + str);
	} else if (event->button() == Qt::MidButton) {
		labelMousePos->setText("鼠标中键按下时的位置：" + str);
	}
}

void MouseEvent::mouseMoveEvent(QMouseEvent *event)
{
	labelStatus->setText("鼠标移动时的位置：" "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")");
	drawPix(event->x(), event->y());
	update();
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
	labelMousePos->setText("鼠标释放时的位置：" + str);
}

void MouseEvent::paintEvent(QPaintEvent *)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(QPoint(0, 0), *pix);
	painter.end();
}
