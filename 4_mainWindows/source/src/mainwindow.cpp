#include "source/inc/mainwindow.h"
#include <QtGui>
#include <QPlainTextEdit>
#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QDockWidget>
#include <QListWidget>
#include <QSettings>
#include <QFile>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow()
{
    textEdit = new QPlainTextEdit;
	setCentralWidget(textEdit);
	setWindowIcon(QPixmap(":Resource/images/kie.jpeg"));
	// setWindowIconText(tr("cMake 窗体测试"));

	createActions();
	createMenus();
	createToolBars();
	createStatusBars();
	createDockWindows();

	readSettings();

	connect(textEdit->document(), SIGNAL(contentsChanged()),
				this, SLOT(documentWasModified()));

	setCurrentFile("");
	setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (maybeSave()) {
		writeSettings();
		event->accept();
	} else {
		event->ignore();
	}
}

void MainWindow::createActions()
{
//new file action
	newAct = new QAction(QIcon(":Resource/images/new.png"), tr("&新建"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("新建一个文本"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
//open file action
	openAct = new QAction(QIcon(":Resource/images/open.png"), tr("&打开..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("打开已经存在的文件"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
//save file action
	saveAct = new QAction(QIcon(":Resource/images/save.png"), tr("&保存"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("保存文本到磁盘"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
//save as action
	saveAsAct = new QAction(tr("另存为..."), this);
	saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
	saveAsAct->setStatusTip(tr("保存文本为另外一个名字"));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));
//exit action
	exitAct = new QAction(tr("&退出"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("退出窗口"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
//cut action
	cutAct = new QAction(QIcon(":Resource/images/cut.png"), tr("剪&切"), this);
	// cutAct = new QAction(QIcon(":/images/kie.jpeg"), tr("剪&切"), this);
	cutAct->setShortcuts(QKeySequence::Cut);
	cutAct->setStatusTip(tr("剪切当前文本选择的区域"));
	connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));
//copy action
	copyAct = new QAction(QIcon(":Resource/images/copy.png"), tr("&复制"), this);
	copyAct->setShortcuts(QKeySequence::Copy);
	copyAct->setStatusTip(tr("复制当前文本选择的区域"));
	connect(copyAct, SIGNAL(triggered()), textEdit , SLOT(copy()));
//paste action
	pasteAct = new QAction(QIcon(":Resource/images/paste.png"), tr("&粘贴"), this);
	pasteAct->setShortcuts(QKeySequence::Paste);
	pasteAct->setStatusTip(tr("粘贴文本到当前选择的区域"));
	connect(pasteAct, SIGNAL(triggered()), textEdit , SLOT(paste()));
//about action
	aboutAct = new QAction(tr("&关于"), this);
	aboutAct->setStatusTip(tr("有关信息"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

//设置剪切和粘贴的bool值
	cutAct->setEnabled(false);
	copyAct->setEnabled(false);
//建立信号与槽的联接，使能剪切和复制动作
	connect(textEdit, SIGNAL(copyAvailable(bool)),
				cutAct, SLOT(setEnabled(bool)));
	connect(textEdit, SIGNAL(copyAvailable(bool)),
				copyAct, SLOT(setEnabled(bool)));
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&文件"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);

	editMenu = menuBar()->addMenu(tr("&编辑"));
	editMenu->addAction(cutAct);
	editMenu->addAction(copyAct);
	editMenu->addAction(pasteAct);

	viewMenu = menuBar()->addMenu(tr("&视图"));

	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&帮助"));
	helpMenu->addAction(aboutAct);
}

void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("文件"));
	fileToolBar->addAction(newAct);
	fileToolBar->addAction(openAct);
	fileToolBar->addAction(saveAct);

	editToolBar = addToolBar(tr("编辑"));
	editToolBar->addAction(cutAct);
	editToolBar->addAction(copyAct);
	editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBars()
{
	statusBar()->showMessage(tr("准备"));
}

bool MainWindow::maybeSave()
{
	if (textEdit->document()->isModified()) {
		QMessageBox::StandardButton ret;
		ret = QMessageBox::warning(this, tr("Application"),
							tr("The document has been modified.\n"
								"Do you want to save your changes?"),
							QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		if (ret == QMessageBox::Save)
			return save();
		else if (ret == QMessageBox::Cancel)
			return false;
	}
	return true;
}

void MainWindow::newFile()
{
	if (maybeSave()) {
		textEdit->clear();
		setCurrentFile("");
	}
}

void MainWindow::open()
{
	if (maybeSave()) {
		QString fileName = QFileDialog::getOpenFileName(this);
		if (!fileName.isEmpty()) {
			loadFile(fileName);
		}
	}
}

bool MainWindow::save()
{
	if (curFile.isEmpty()) {
		return saveAs();
	} else {
		return saveFile(curFile);
	}
}

bool MainWindow::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this);
	if (fileName.isEmpty())
		return false;

	return saveFile(fileName);
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About Application"),
						tr("The <b>Application</b> example demonstrates how to "
							"write modern GUI applicatoins using Qt, with a menu bar, "
							"toolbars,and a status bar."));
}

void MainWindow::createDockWindows()
{
	QDockWidget *dock = new QDockWidget(tr("Customers"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	customerList = new QListWidget(dock);
	customerList->addItems(QStringList()
				<< "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
				<< "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
				<< "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
				<< "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
				<< "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
				<< "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
	dock->setWidget(customerList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());

	dock = new QDockWidget(tr("Paragraphs"), this);
	paragraphsList = new QListWidget(dock);
	paragraphsList->addItems(QStringList()
				<< "Thank you for your payment which we have received today."
				<< "Your order has been dispatched and should be with you "
					"within 28 days."
				<< "We have dispatched those items that were in stock. The "
					"rest of your order will be dispatched once all the "
					"remaining items have arrived at our warehouse. No "
					"additional shipping charges will be made."
				<< "You made a small overpayment (less than $5) which we "
					"will keep on account for you, or return at your request."
				<< "You made a small underpayment (less than $1), but we have "
					"sent your order anyway. We'll add this underpayment to "
					"your next bill."
				<< "Unfortunately you did not send enough money. Please remit "
					"an additional $. Your order will be dispatched as soon as "
					"the complete amount has been received."
				<< "You made an overpayment (more than $5). Do you wish to "
					"buy more items, or should we return the excess to you?");
	dock->setWidget(paragraphsList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());
}

void MainWindow::readSettings()
{
	//恢复
	QSettings settings("Software Inc.", "mainWindows_cmake");
	settings.beginGroup("mainWindow");
	// this->customerList->restoreGeometry(settings.value("customerList-geometry").toByteArray());
	this->restoreGeometry(settings.value("mainWindow-geometry").toByteArray());
	// this->restoreState(settings.value("mainWindow-state").toByteArray());
	settings.endGroup();
	// QFile file(":Resource/settings/setting.ini");
	// if (file.open(QIODevice::ReadOnly)) {
	// 	QByteArray ba;
	// 	QDataStream in(&file);
	// 	in >> ba;
	// 	file.close();
	// 	this->restoreState(ba);
	// }
}

void MainWindow::writeSettings()
{
	//保存
	QSettings settings("Software Inc.", "mainWindows_cmake");
	settings.beginGroup("mainWindow");
	settings.setValue("mainWindow-geometry", this->saveGeometry());
	// settings.setValue("mainWindow-state", this->saveState());

	// settings.setValue("customerList-geometry", this->customerList->saveGeometry());
	settings.endGroup();

	// QFile file(":Resource/settings/setting.ini");
	// if (file.open(QIODevice::WriteOnly)) {
	// 	QDataStream out(&file);
	// 	// QByteArray ba = this->saveState();
	// 	// ba<<out;
	// 	out << this->saveState();
	// 	file.close();
	// }
}

void MainWindow::setCurrentFile(QString const &)
{

}

void MainWindow::loadFile(QString const &)
{

}

bool MainWindow::saveFile(QString const &)
{

}

void MainWindow::documentWasModified()
{

}
