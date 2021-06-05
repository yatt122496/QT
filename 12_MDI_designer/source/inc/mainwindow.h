#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMenu>
#include <QtGui>
#include "source/inc/mdichild.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();

protected:
	void closeEvent(QCloseEvent *);

private slots:
	void newFile();
	void open();
	void save();
	void saveAs();
	void cut();
	void copy();
	void paste();
	void about();
	void updataMenus();
	void updateWindowMenu();
	MdiChild *createMdiChild();
	void switchLayoutDirection();
	void setActiveSubWindow(QWidget *);

private:
	void createActions();
	void createMenus();
	void createToolbars();
	MdiChild *activeMdiChild();
	QMdiSubWindow *findMdiChild(const QString &);

	QMdiArea *mdiArea;
	QSignalMapper *windowMapper;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *windowMenu;
	QMenu *helpMenu;
	QToolBar *fileToolBar;
	QToolBar *editToolBar;
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *exitAct;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	QAction *closeAct;
	QAction *closeAllAct;
	QAction *tileAct;
	QAction *cascadeAct;
	QAction *nextAct;
	QAction *previousAct;
	QAction *separatorAct;
	QAction *aboutAct;
	QAction *aboutQtAct;
};
#endif
