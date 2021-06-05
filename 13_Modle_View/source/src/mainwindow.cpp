#include "source/inc/mainwindow.h"
#include <QtGui>
#include <QGridLayout>

MainWindow::MainWindow()
{
	// QSplitter(Qt::Horizontal, 0);
	// setOpaqueResize(true);

	model = new QFileSystemModel();
	model->setRootPath("/");
	list = new QListView();
	tree = new QTreeView();
	table = new QTableView();
	uplist = new UplistView();

	tree->setModel(model);
	tree->setColumnWidth(0, 200);
	list->setModel(model);
	table->setModel(model);
	uplist->setModel(model);

	tree->setSelectionMode(QAbstractItemView::SingleSelection);
	list->setSelectionMode(QAbstractItemView::ExtendedSelection);
	table->setSelectionMode(QAbstractItemView::ExtendedSelection);
	uplist->setSelectionMode(QAbstractItemView::ExtendedSelection);

	connect(tree, SIGNAL(clicked(QModelIndex)), list, SLOT(setRootIndex(QModelIndex)));
	connect(tree, SIGNAL(clicked(QModelIndex)), table, SLOT(setRootIndex(QModelIndex)));
	connect(tree, SIGNAL(clicked(QModelIndex)), uplist, SLOT(setRootIndex(QModelIndex)));

	connect(list, SIGNAL(doubleClicked(QModelIndex)), tree, SLOT(setCurrentIndex(QModelIndex)));
	connect(list, SIGNAL(doubleClicked(QModelIndex)), list, SLOT(setRootIndex(QModelIndex)));
	connect(list, SIGNAL(doubleClicked(QModelIndex)), table, SLOT(setRootIndex(QModelIndex)));
	connect(list, SIGNAL(doubleClicked(QModelIndex)), uplist, SLOT(setRootIndex(QModelIndex)));
	connect(table, SIGNAL(doubleClicked(QModelIndex)), tree, SLOT(setCurrentIndex(QModelIndex)));
	connect(table, SIGNAL(doubleClicked(QModelIndex)), list, SLOT(setRootIndex(QModelIndex)));
	connect(table, SIGNAL(doubleClicked(QModelIndex)), table, SLOT(setRootIndex(QModelIndex)));
	connect(table, SIGNAL(doubleClicked(QModelIndex)), uplist, SLOT(setRootIndex(QModelIndex)));
	connect(uplist, SIGNAL(doubleClicked(QModelIndex)), tree, SLOT(setCurrentIndex(QModelIndex)));
	connect(uplist, SIGNAL(doubleClicked(QModelIndex)), list, SLOT(setRootIndex(QModelIndex)));
	connect(uplist, SIGNAL(doubleClicked(QModelIndex)), table, SLOT(setRootIndex(QModelIndex)));
	connect(uplist, SIGNAL(doubleClicked(QModelIndex)), uplist, SLOT(setRootIndex(QModelIndex)));

	pushbuttonUndo = new QPushButton(tr("上一级"));
	connect(pushbuttonUndo, SIGNAL(clicked(bool)), this, SLOT(undo()));
	setOrientation(Qt::Horizontal);
	addWidget(tree);
	QSplitter *spliter = new QSplitter(Qt::Vertical, this);
	// setOrientation(Qt::Vertical);
	spliter->addWidget(list);
	spliter->addWidget(table);
	spliter->addWidget(uplist);
	spliter->addWidget(pushbuttonUndo);

	setWindowTitle(tr("Model/View"));
	resize(800, 480);
	setMaximumSize(800, 480);

	connect(list, SIGNAL(activated(const QModelIndex &)), this, SLOT(message(const QModelIndex &)));
}

void MainWindow::undo()
{
	// QModelIndex i = list->currentIndex();
	QModelIndex k = list->rootIndex();
	QModelIndex j = k.parent();
	// qDebug() << i << k << j;
	tree->setCurrentIndex(j);
	list->setRootIndex(j);
	table->setRootIndex(j);
}

void MainWindow::message(const QModelIndex &indexe)
{
	// qDebug() << indexe;
}
