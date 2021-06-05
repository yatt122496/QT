#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "source/inc/table.h"
#include <QMainWindow>
#include <QtWidgets/qaction.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();

private:
	Table *table;
	QAction *cutAction;
	QAction *copyAction;
	QAction *pasteAction;
	QAction *deleteAction;
};

#endif
