#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QMainWindow>
#include <QMdiArea>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>

class WorkSpace : public QMainWindow
{
	Q_OBJECT
public:
	WorkSpace(QWidget *parent = 0);

private:
	void createToolBar();
	void createMenu();
	void createAction();
	QMdiArea *mdiArea;
	QAction *arrange;
	QAction *tile;
	QAction *cascade;
	QAction *nextAct;
	QAction *previousAct;
	QAction *closeActiveAct;
	QMenu *layoutMenu;
	QMenu *otherMenu;
	QToolBar *layoutBar;
	QToolBar *otherBar;
};
#endif
