#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QMainWindow>
#include <QImage>
#include "source/inc/showwidget.h"
#include <QToolBar>

class Painter : public QMainWindow
{
	Q_OBJECT
public:
	Painter(QWidget *parent = 0);
	void paintEvent(QPaintEvent *);

private:
	QString fileName;
	QImage image;
	QString filename;
	ShowWidget *showWidget;
	QAction *actionOpenFile;
	QAction *actionPrintImage;
	QToolBar *toolBarTool;

public slots:
	void showOpenFile();
	void showPrintImage();
};
#endif
