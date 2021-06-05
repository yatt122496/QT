#ifndef STRINGVIEW_H
#define STRINGVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include <QMenuBar>
#include "source/inc/stringmodel.h"

class StringView : public QMainWindow
{
	Q_OBJECT
public:
	StringView(QMainWindow *parent = 0);
	void createActions();
	void createMenus();
	void setupModel();
	void setupView();
	void openFile(QString);

public slots:
	void soltOpenFile();
	void soltSaveFile();
	void soltInsertRows();
	void soltRemoveRows();

private:
	QListView *list;
	StringListModel *model;
	QString name;
	QAction *actionOpen;
	QAction *actionSave;
	QAction *actionInsert;
	QAction *actionRemove;

	QMenu *menuOpen;
	QMenu *menuSave;
	QMenu *menuInsert;
	QMenu *menuRemove;
};
#endif
