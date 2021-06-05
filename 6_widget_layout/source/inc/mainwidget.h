#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QStackedWidget>
#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include "source/inc/baseinfo.h"
#include "source/inc/moreinfo.h"

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = 0);
	QStackedWidget *stack;

private:
	QPushButton *pushButtonOk;
	QPushButton *pushButtonCancel;
	QPushButton *pushButtonApply;
	BaseInfo *baseInfo;
	MoreInfo *moreInfo;
};
#endif
