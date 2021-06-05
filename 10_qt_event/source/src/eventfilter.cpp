#include "source/inc/eventfilter.h"
#include <QtGui>
#include <QGridLayout>

EventFilter::EventFilter(QWidget *parent, Qt::WindowFlags f)
		: QDialog(parent, f)
{
	setWindowTitle("事件过滤");

	label1 = new QLabel;
	image1.load(":Resource/images/new.png");
	label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label1->setPixmap(QPixmap::fromImage(image1));

	label2 = new QLabel;
	image2.load(":Resource/images/select.png");
	label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label2->setPixmap(QPixmap::fromImage(image2));

	label3 = new QLabel;
	image3.load(":Resource/images/stop.png");
	label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label3->setPixmap(QPixmap::fromImage(image3));

	labelState = new QLabel("鼠标按下标志");
	labelState->setAlignment(Qt::AlignHCenter);

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(label1);
	layoutH1->addWidget(label2);
	layoutH1->addWidget(label3);

	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->addLayout(layoutH1);
	layoutMain->addWidget(labelState);
	setLayout(layoutMain);

	int maxWidth, maxHeight;
	maxWidth = qMax(image1.width(), image2.width());
	maxWidth = qMax(maxWidth, image3.width());
	maxHeight = qMax(image1.height(), image2.height());
	maxHeight = qMax(maxHeight, image3.height());

	resize(maxWidth * 1.8 * 3, maxHeight * 1.8 + 40);

	label1->installEventFilter(this);
	label2->installEventFilter(this);
	label3->installEventFilter(this);
}

bool EventFilter::eventFilter(QObject *object, QEvent *event)
{
	if (object == label1) {
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons() & Qt::LeftButton) {
				labelState->setText("左键按下左边图片");
			} else if (mouseEvent->buttons() & Qt::MiddleButton) {
				labelState->setText("中键按下左边图片");
			} else if (mouseEvent->buttons() & Qt::RightButton) {
				labelState->setText("右键按下左边图片");
			}
			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImage = image1.transformed(matrix);
			label1->setPixmap(QPixmap::fromImage(tmpImage));
		}
		if (event->type() == QEvent::MouseButtonRelease) {
			labelState->setText("鼠标释放左边图片");
			label1->setPixmap(QPixmap::fromImage(image1));
		}
	} else if (object == label2) {
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons() & Qt::LeftButton) {
				labelState->setText("左键按下中间图片");
			} else if (mouseEvent->buttons() & Qt::MiddleButton) {
				labelState->setText("中键按下中间图片");
			} else if (mouseEvent->buttons() & Qt::RightButton) {
				labelState->setText("右键按下中间图片");
			}
			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImage = image2.transformed(matrix);
			label2->setPixmap(QPixmap::fromImage(tmpImage));
		}
		if (event->type() == QEvent::MouseButtonRelease) {
			labelState->setText("鼠标释放中间图片");
			label2->setPixmap(QPixmap::fromImage(image2));
		}
	} else if (object == label3) {
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mouseEvent = (QMouseEvent *)event;
			if (mouseEvent->buttons() & Qt::LeftButton) {
				labelState->setText("左键按下右边图片");
			} else if (mouseEvent->buttons() & Qt::MiddleButton) {
				labelState->setText("中键按下右边图片");
			} else if (mouseEvent->buttons() & Qt::RightButton) {
				labelState->setText("右键按下右边图片");
			}
			QMatrix matrix;
			matrix.scale(1.8, 1.8);
			QImage tmpImage = image3.transformed(matrix);
			label3->setPixmap(QPixmap::fromImage(tmpImage));
		}
		if (event->type() == QEvent::MouseButtonRelease) {
			labelState->setText("鼠标释放右边图片");
			label3->setPixmap(QPixmap::fromImage(image3));
		}
	}
	// qDebug() <<size().width() <<size().height();
	return QDialog::eventFilter(object, event);
}
