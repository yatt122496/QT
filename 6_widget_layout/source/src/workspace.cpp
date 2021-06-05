#include "source/inc/workspace.h"
#include <QtGui>
#include <QGridLayout>
#include <QTextEdit>


WorkSpace::WorkSpace(QWidget *parent)
		:QMainWindow(parent)
{
	setWindowTitle(tr("工作空间"));
	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);

	createAction();
	createMenu();
	createToolBar();

	QMainWindow *window1 = new QMainWindow;
	window1->setWindowTitle(tr("窗口 1"));
	QTextEdit *edit1 = new QTextEdit;
	edit1->setText(tr("窗口 1"));
	edit1->setAlignment(Qt::AlignCenter);
	window1->setCentralWidget(edit1);

	QMainWindow *window2 = new QMainWindow;
	window2->setWindowTitle(tr("窗口 2"));
	QTextEdit *edit2 = new QTextEdit;
	edit2->setText(tr("窗口 2"));
	edit2->setAlignment(Qt::AlignCenter);
	window2->setCentralWidget(edit2);

	QMainWindow *window3 = new QMainWindow;
	window3->setWindowTitle(tr("窗口 3"));
	QTextEdit *edit3 = new QTextEdit;
	edit3->setText(tr("窗口 3"));
	edit3->setAlignment(Qt::AlignCenter);
	window3->setCentralWidget(edit3);

	QMainWindow *window4 = new QMainWindow;
	window4->setWindowTitle(tr("窗口 4"));
	QTextEdit *edit4 = new QTextEdit;
	edit4->setText(tr("窗口 4"));
	edit4->setAlignment(Qt::AlignCenter);
	window4->setCentralWidget(edit4);

	mdiArea->addSubWindow(window1);
	mdiArea->addSubWindow(window2);
	mdiArea->addSubWindow(window3);
	mdiArea->addSubWindow(window4);
}

void WorkSpace::createAction()
{
	// arrange = new QAction(QIcon(":Resource/images/open.png"), "排列图标", this);
	// connect(arrange, SIGNAL(triggered()), mdiArea, SLOT(ArrangeIconicWindows()));

	tile = new QAction(QIcon(":Resource/images/save.png"), "平铺", this);
	connect(tile, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));

	cascade = new QAction(QIcon(":Resource/images/close.png"), "层叠", this);
	connect(cascade, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));

	nextAct = new QAction(QIcon(":Resource/images/copy.png"), "下一个", this);
	connect(nextAct, SIGNAL(triggered()), mdiArea, SLOT(activateNextSubWindow()));

	previousAct = new QAction(QIcon(":Resource/images/paste.png"), "前一个", this);
	connect(previousAct, SIGNAL(triggered()), mdiArea, SLOT(activatePreviousSubWindow()));

	closeActiveAct = new QAction(QIcon(":Resource/images/close.png"), "关闭当前窗口", this);
	connect(closeActiveAct, SIGNAL(triggered()), mdiArea, SLOT(closeActiveSubWindow()));
}

void WorkSpace::createMenu()
{
	QMenuBar *menuBar = new QMenuBar(this);

	layoutMenu = new QMenu("布局");
	// layoutMenu->addAction(arrange);
	layoutMenu->addAction(tile);
	layoutMenu->addAction(cascade);
	menuBar->addMenu(layoutMenu);
	otherMenu = new QMenu("其他");
	otherMenu->addAction(nextAct);
	otherMenu->addAction(previousAct);
	otherMenu->addAction(closeActiveAct);
	menuBar->addMenu(otherMenu);

	setMenuBar(menuBar);
}

void WorkSpace::createToolBar()
{
	layoutBar = addToolBar(tr("布局"));
	// layoutBar->addAction(arrange);
	layoutBar->addAction(tile);
	layoutBar->addAction(cascade);

	otherBar = addToolBar("其他");
	otherBar->addAction(nextAct);
	otherBar->addAction(previousAct);
	otherBar->addAction(closeActiveAct);
}
