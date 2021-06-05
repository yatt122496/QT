#include "source/inc/uplistview.h"
#include <QGridLayout>
#include <QtGui>

UplistView::UplistView(QWidget *parent)
		: QListView(parent)
{
	connect(this, SIGNAL(activated(const QModelIndex &)), this, SLOT(uponelevel(const QModelIndex &)));

	// buttonUpOneLevel = new QPushButton("..");
	// connect(buttonUpOneLevel, SIGNAL(clicked()), this, SLOT(uponelevel()));

	// list = new QListView();

	// QHBoxLayout *layoutH1 = new QHBoxLayout();
	// layoutH1->addWidget(buttonUpOneLevel);
	// layoutH1->addStretch();

	// QVBoxLayout *layoutMain = new QVBoxLayout();

	// layoutMain->addLayout(layoutH1);
	// layoutMain->addWidget(list);

	// setLayout(layoutMain);
}

void UplistView::uponelevel(const QModelIndex &index)
{
	this->model()->insertRow(0, this->currentIndex());
	// this->rowsInserted(this->currentIndex(), 0, 1);
	qDebug() << index;
	// QModelIndex i = list->rootIndex().parent();
	// list->setRootIndex(i);
}
