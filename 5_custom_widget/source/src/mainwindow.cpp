#include "source/inc/mainwindow.h"
// #include "./ui_mainwindow.h"
#include <QtGui>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
{
	drawWidget = new DrawWidget;
	setCentralWidget(drawWidget);

	dock = new Dock;
	connect(dock->styleComboBox, SIGNAL(activated(int)), this, SLOT(ShowStyle()));
	connect(dock->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowWidth()));
	connect(dock->colorBtn, SIGNAL(clicked()), this, SLOT(ShowColor()));
	connect(dock->clearBtn, SIGNAL(clicked()), drawWidget, SLOT(clear()));

	dockWidget = new QDockWidget("Setting", this);
	dockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidget->setAllowedAreas(Qt::RightDockWidgetArea);

	dockWidget->setWidget(dock);
	addDockWidget(Qt::RightDockWidgetArea, dockWidget);
	dockWidget->setMaximumSize(200, 200);
	// dockWidget->setFloating(true);

	setMinimumSize(800, 480);
	setMaximumSize(800, 480);
	drawWidget->setStyle(dock->styleComboBox->itemData(
				dock->styleComboBox->currentIndex(), Qt::UserRole).toInt());
	drawWidget->setWidth(dock->widthSpinBox->value());
	drawWidget->setColor(Qt::black);
}

MainWindow::~MainWindow()
{

}

void MainWindow::ShowStyle()
{
	drawWidget->setStyle(dock->styleComboBox->itemData(
				dock->styleComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWindow::ShowColor()
{
	QColor color = QColorDialog::getColor(drawWidget->getColor(), this);
	if (color.isValid()) {
		drawWidget->setColor(color);
		QPixmap p(20, 20);
		p.fill(color);
		dock->colorBtn->setIcon(QIcon(p));
	}
}

void MainWindow::ShowWidth()
{
	drawWidget->setWidth(dock->widthSpinBox->value());
}
