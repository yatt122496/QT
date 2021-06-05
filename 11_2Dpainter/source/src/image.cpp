#include "source/inc/image.h"
#include <QtGui>
#include <QGridLayout>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

ImageWidget::ImageWidget()
{
	resize(200, 200);
	pushButtonOpen = new QPushButton("Open Image", this);
	pushButtonOpen->setGeometry(60, 160, 80, 30);
	connect(pushButtonOpen, SIGNAL(clicked()), this, SLOT(openImage()));
	pushButtonOpen->show();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if (!img.isNull()) {
		painter.drawImage(10, 10, img);
		img.save("test.bmp");
	}
}

void ImageWidget::openImage()
{
	QString filename = QFileDialog::getOpenFileName(this, "OpenImage", "",
								"PNG(*.png);;JPG(*.jpg);;ALL files(*.*)");
	if (filename.isEmpty()) {
		QMessageBox::information(this, "Open Image", "Please select an image to open");
		filename = QFileDialog::getOpenFileName(this, "OpenImage", "",
								"PNG(*.png);;JPG(*.jpg);;ALL files(*.*)");
	}
	if (!(img.load(filename, 0))) {
		QMessageBox::information(this, "Unable to open the Image",
										"Please select a valid image.");
		return;
	}
	QWidget::update();
}
