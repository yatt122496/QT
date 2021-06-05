#include "source/inc/mainwindow.h"
#include <QGridLayout>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

MainWindow::MainWindow()
{
	QSplitter(Qt::Horizontal, 0);
	setOpaqueResize(true);
	QLabel *labelIcon = new QLabel();
	QPixmap icon(":Resource/images/logo.png");
	labelIcon->resize(icon.width(), icon.height());
	labelIcon->setPixmap(icon);
	labelIcon->setAlignment(Qt::AlignCenter);

	QPushButton *pushButtonIcon = new QPushButton("更改头像");

	QListWidget *list = new QListWidget();
	list->insertItem(0, "基本信息");
	list->insertItem(1, "更多信息");

	QVBoxLayout *layoutLeft = new QVBoxLayout();
	layoutLeft->addWidget(labelIcon);
	layoutLeft->addWidget(pushButtonIcon);
	layoutLeft->addWidget(list);

	QWidget *widgetLeft = new QWidget();
	widgetLeft->setLayout(layoutLeft);

	MainWidget *mainWidget = new MainWidget();
	connect(list, SIGNAL(currentRowChanged(int)), mainWidget->stack, SLOT(setCurrentIndex(int)));

	addWidget(widgetLeft);
	addWidget(mainWidget);

	setStretchFactor(1, 5);

	setWindowTitle("布局管理");
	setMinimumSize(600, 400);
	setMaximumSize(800, 480);
}
