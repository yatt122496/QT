#include "source/inc/painter.h"
#include <QtGui>
#include <QGridLayout>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

Painter::Painter(QWidget *parent)
		: QMainWindow(parent)
{
	resize(420, 450);
	setWindowTitle("Painter");
	showWidget = new ShowWidget(this);
	setCentralWidget(showWidget);

	actionOpenFile = new QAction(QIcon(":Resource/images/open.png"), "Open", this);
	actionOpenFile->setShortcut(tr("Ctrl+O"));
	actionOpenFile->setStatusTip("open a Image");
	connect(actionOpenFile, SIGNAL(triggered()), this, SLOT(showOpenFile()));

	actionPrintImage = new QAction(QIcon(":Resource/images/new.png"), "PrintImage", this);
	actionPrintImage->setStatusTip("print a Image");
	connect(actionPrintImage, SIGNAL(triggered()), this, SLOT(showPrintImage()));

	toolBarTool = addToolBar("Tools");
	toolBarTool->addAction(actionOpenFile);
	toolBarTool->addAction(actionPrintImage);
}

void Painter::showOpenFile()
{
	fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
		QWidget::update();
}

void Painter::paintEvent(QPaintEvent *event)
{
	if (image.load(fileName))
		showWidget->labelImage->setPixmap(QPixmap::fromImage(image));
}

void Painter::showPrintImage()
{
	QPrinter printer;
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec()) {
		QPainter painter(&printer);
		QRect rect = painter.viewport();
		QSize size = image.size();
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		painter.setWindow(image.rect());
		painter.drawImage(0, 0, image);
	}
}
