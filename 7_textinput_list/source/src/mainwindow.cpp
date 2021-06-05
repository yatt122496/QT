#include "source/inc/mainwindow.h"
#include <QGridLayout>
#include <QtGui>

MainWindow::MainWindow()
{
	table = new Table();
	setCentralWidget(table);
	cutAction = new QAction(QIcon(":Resource/images/cut.png"), "Cut", this);
	cutAction->setStatusTip("Cut the current selection`s contents to the clipboard");
	connect(cutAction, SIGNAL(triggered()), table, SLOT(cut()));

	copyAction = new QAction("Copy", this);
	copyAction->setIcon(QIcon(":Resource/images/copy.png"));
	copyAction->setStatusTip("Copy the current selection`s contents to the clipboard");
	connect(copyAction, SIGNAL(triggered()), table, SLOT(copy()));

	pasteAction = new QAction("Paste", this);
	pasteAction->setIcon(QIcon(":Resource/images/paste.png"));
	pasteAction->setStatusTip("Paste the clipboard`s contents into the current selection");
	connect(pasteAction, SIGNAL(triggered()), table, SLOT(paste()));

	deleteAction = new QAction("Delete", this);
	deleteAction->setIcon(QIcon(":Resource/images/close.png"));
	deleteAction->setStatusTip("Delete the currentselection`s contents");
	connect(deleteAction, SIGNAL(triggered()), table, SLOT(del()));

	table->addAction(cutAction);
	table->addAction(copyAction);
	table->addAction(pasteAction);
	table->addAction(deleteAction);
	table->setContextMenuPolicy(Qt::ActionsContextMenu);

	setMinimumSize(600, 400);
	setMaximumSize(800, 480);
}
