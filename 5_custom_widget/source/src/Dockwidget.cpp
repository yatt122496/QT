#include "source/inc/Dockwidget.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>

Dock::Dock()
{
	styleLabel = new QLabel("style");
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SolidLine"), (int)Qt::SolidLine);
	styleComboBox->addItem(tr("DashLine"), (int)Qt::DashLine);
	styleComboBox->addItem(tr("DotLine"), (int)Qt::DotLine);
	styleComboBox->addItem(tr("DashDotLine"), (int)Qt::DashDotLine);
	styleComboBox->addItem(tr("DashDotDotLine"), (int)Qt::DashDotDotLine);

	widthLabel = new QLabel("width");
	widthSpinBox = new QSpinBox;
	widthSpinBox->setValue(3);

	colorLabel = new QLabel("Color");
	colorBtn = new QToolButton;
	QPixmap pixmap(20, 20);
	pixmap.fill(Qt::black);
	colorBtn->setIcon(QIcon(pixmap));

	clearBtn = new QToolButton();
	clearBtn->setText("clear");

	QGridLayout *v = new QGridLayout(this);
	v->addWidget(styleLabel, 0, 0);
	v->addWidget(styleComboBox, 0, 1);
	v->addWidget(widthLabel, 1, 0);
	v->addWidget(widthSpinBox, 1, 1);
	v->addWidget(colorLabel, 2, 0);
	v->addWidget(colorBtn, 2, 1);
	v->addWidget(clearBtn, 3, 0);
	resize(40, 50);
}

