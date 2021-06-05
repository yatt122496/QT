#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "source/inc/drawwidget.h"
#include "source/inc/Dockwidget.h"
// QT_BEGIN_NAMESPACE
// class QAction;
// class QMenu;
// class QPlainTextEdit;
// class QListWidget;
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
	~MainWindow();
	void createBtn();
	Dock *dock;
public slots:
	void ShowStyle();
	void ShowColor();
	void ShowWidth();
private:
	DrawWidget *drawWidget;
	QDockWidget *dockWidget;
};
#endif // MAINWINDOW_H
