#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSplitter>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QFileSystemModel>
#include <QPushButton>
#include "source/inc/uplistview.h"

class MainWindow : public QSplitter
{
	Q_OBJECT
public:
	MainWindow();

private slots:
	void undo();
	void message(const QModelIndex &);

private:
	QListView *list;
	QTreeView *tree;
	QTableView *table;
	UplistView *uplist;
	QFileSystemModel *model;
	QPushButton *pushbuttonUndo;
};
#endif
