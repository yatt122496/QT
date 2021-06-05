#include "source/inc/showwidget.h"
#include <QtGui>
#include <QGridLayout>

ShowWidget::ShowWidget(QWidget *parent)
			: QWidget(parent)
{
	labelImage = new QLabel(this);
	labelImage->setScaledContents(true);
	labelImage->setGeometry(0, 0, 400, 400);
}
