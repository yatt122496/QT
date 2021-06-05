#include "source/inc/mainwindow.h"
#include <QtGui>
#include <QGridLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QMdiSubWindow>

MainWindow::MainWindow()
{
	mdiArea = new QMdiArea();
	mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(mdiArea);
	connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow *)), this, SLOT(updataMenus()));
	windowMapper = new QSignalMapper(this);
	connect(windowMapper, SIGNAL(mapped(QWidget *)), this, SLOT(setActiveSubWindow(QWidget *)));
	createActions();
	createMenus();
	createToolbars();
	updataMenus();
	setWindowTitle("MDI");
	statusBar()->showMessage("Ready");
	setMinimumSize(600, 400);
	setMaximumSize(800, 480);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	mdiArea->closeAllSubWindows();
	if (mdiArea->currentSubWindow()) {
		event->ignore();
	} else {
		event->accept();
	}
}

void MainWindow::newFile()
{
	MdiChild *child = createMdiChild();
	child->newFile();
	child->show();
}

void MainWindow::open()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty()) {
		QMdiSubWindow *exiting = findMdiChild(QDir(fileName).dirName());
		if (exiting) {
			mdiArea->setActiveSubWindow(exiting);
			return;
		}
		MdiChild *child = createMdiChild();
		if (child->loadFile(fileName)) {
			statusBar()->showMessage("File loaded", 2000);
			child->show();
		} else {
			child->close();
		}
	}
}

void MainWindow::save()
{
	if (activeMdiChild() && activeMdiChild()->save())
		statusBar()->showMessage("File saved", 2000);
}

void MainWindow::saveAs()
{
	if (activeMdiChild() && activeMdiChild()->saveAs())
		statusBar()->showMessage("File saved", 2000);
}

void MainWindow::cut()
{
	if (activeMdiChild())
		activeMdiChild()->cut();
}

void MainWindow::copy()
{
	if (activeMdiChild())
		activeMdiChild()->copy();
}

void MainWindow::paste()
{
	if (activeMdiChild())
		activeMdiChild()->paste();
}

void MainWindow::about()
{
	QMessageBox::about(this, "About MDI",
				tr("The <b>MDI</b> example demonstrates how to write multiple "
						"document interface applications using Qt."));
}

void MainWindow::updataMenus()
{
	bool hasMdiChild = (activeMdiChild() != 0);
	saveAct->setEnabled(hasMdiChild);
	saveAsAct->setEnabled(hasMdiChild);
	pasteAct->setEnabled(hasMdiChild);
	closeAct->setEnabled(hasMdiChild);
	closeAllAct->setEnabled(hasMdiChild);
	tileAct->setEnabled(hasMdiChild);
	cascadeAct->setEnabled(hasMdiChild);
	nextAct->setEnabled(hasMdiChild);
	separatorAct->setEnabled(hasMdiChild);
	bool hasSelection = (activeMdiChild() && activeMdiChild()->textCursor().hasSelection());
	cutAct->setEnabled(hasSelection);
	copyAct->setEnabled(hasSelection);
}

void MainWindow::updateWindowMenu()
{
	windowMenu->clear();
	windowMenu->addAction(closeAct);
	windowMenu->addAction(closeAllAct);
	windowMenu->addSeparator();
	windowMenu->addAction(tileAct);
	windowMenu->addAction(cascadeAct);
	windowMenu->addSeparator();
	windowMenu->addAction(nextAct);
	windowMenu->addAction(separatorAct);

	QList<QMdiSubWindow *>windows = mdiArea->subWindowList();
	separatorAct->setVisible(!windows.isEmpty());

	for (int i = 0; i < windows.size(); ++i) {
		MdiChild *child = (MdiChild *)(windows.at(i)->widget());
		QString text;
		if (i < 9) {
			text = tr("&%1 %2").arg(i + 1).arg(child->curFile);
		} else {
			text = tr("%1 %2").arg(i + 1).arg(child->curFile);
		}
		QAction *action = windowMenu->addAction(text);
		action->setCheckable(true);
		action->setCheckable(child == activeMdiChild());
		connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
		windowMapper->setMapping(action, windows.at(i));
	}
}

MdiChild *MainWindow::createMdiChild()
{
	MdiChild *child = new MdiChild();
	mdiArea->addSubWindow(child);
	connect(child, SIGNAL(copyAvailable(bool)), cutAct, SLOT(setEnabled(bool)));
	connect(child, SIGNAL(copyAvailable(bool)), copyAct, SLOT(setEnabled(bool)));
	return child;
}

void MainWindow::createActions()
{
	newAct = new QAction(QIcon(":Resource/images/new.png"), tr("&New"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("Create a new file"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

	openAct = new QAction(QIcon(":Resource/images/open.png"), tr("&Open..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open an exiting file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

	saveAct = new QAction(QIcon(":Resource/images/save.png"), tr("&Save"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the document to disk"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAct = new QAction(QIcon(":Resource/images/saveAs.png"), tr("&SaveAs"), this);
	saveAsAct->setShortcuts(QKeySequence::SaveAs);
	saveAsAct->setStatusTip(tr("Save the document under a new name"));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

	cutAct = new QAction(QIcon(":Resource/images/cut.png"), tr("&Cut"), this);
	cutAct->setShortcuts(QKeySequence::Cut);
	cutAct->setStatusTip(tr("Cut select contents to another position"));
	connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

	copyAct = new QAction(QIcon(":Resource/images/copy.png"), tr("&Copy"), this);
	copyAct->setShortcuts(QKeySequence::Copy);
	copyAct->setStatusTip(tr("Copy select contents"));
	connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

	pasteAct = new QAction(QIcon(":Resource/images/paste.png"), tr("&Paste"), this);
	pasteAct->setShortcuts(QKeySequence::Paste);
	pasteAct->setStatusTip(tr("Paste clip contents to current position"));
	connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

	aboutAct = new QAction(QIcon(":Resource/images/About.png"), tr("&About"), this);
	aboutAct->setStatusTip(tr("About the MDI"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	exitAct = new QAction(QIcon(":Resource/images/exit.png"), tr("&Exit"), this);
	exitAct->setStatusTip(tr("Exit"));

	aboutQtAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&aboutQt"), this);
	aboutQtAct->setStatusTip(tr("aboutQt"));

	closeAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&closeAct"), this);
	closeAct->setStatusTip(tr("closeAct"));
	connect(closeAct, SIGNAL(triggered()), mdiArea, SLOT(closeActiveSubWindow()));

	closeAllAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&closeAllAct"), this);
	closeAllAct->setStatusTip(tr("closeAllAct"));
	connect(closeAllAct, SIGNAL(triggered()), mdiArea, SLOT(closeAllSubWindows()));

	tileAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&tileAct"), this);
	tileAct->setStatusTip(tr("tileAct"));
	connect(tileAct, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));

	cascadeAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&cascadeAct"), this);
	cascadeAct->setStatusTip(tr("cascadeAct"));
	connect(cascadeAct, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));

	nextAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&nextAct"), this);
	nextAct->setStatusTip(tr("nextAct"));
	connect(nextAct, SIGNAL(triggered()), mdiArea, SLOT(activateNextSubWindow()));

	previousAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&previousAct"), this);
	previousAct->setStatusTip(tr("previousAct"));
	connect(previousAct, SIGNAL(triggered()), mdiArea, SLOT(activatePreviousSubWindow()));

	separatorAct = new QAction(QIcon(":Resource/images/Qt.png"), tr("&separatorAct"), this);
	separatorAct->setStatusTip(tr("separatorAct"));
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();

	QAction *action = fileMenu->addAction(tr("Switch layout direction"));
	connect(action, SIGNAL(triggered()), this, SLOT(switchLayoutDirection()));
	fileMenu->addAction(exitAct);

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAct);
	editMenu->addAction(copyAct);
	editMenu->addAction(pasteAct);

	windowMenu = menuBar()->addMenu(tr("&Window"));
	updateWindowMenu();
	connect(windowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));
	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
	helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolbars()
{
	fileToolBar = addToolBar(tr("File"));
	fileToolBar->addAction(newAct);
	fileToolBar->addAction(openAct);
	fileToolBar->addAction(saveAct);

	editToolBar = addToolBar(tr("Edit"));
	editToolBar->addAction(cutAct);
	editToolBar->addAction(copyAct);
	editToolBar->addAction(pasteAct);
}

MdiChild *MainWindow::activeMdiChild()
{
	if (QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow())
		return (MdiChild *)(activeSubWindow->widget());
	return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
	foreach (QMdiSubWindow *window, mdiArea->subWindowList()) {
		MdiChild *mdiChild = (MdiChild *)(window->widget());
		// qDebug() << fileName << mdiChild->curFile;
		if (mdiChild->curFile == fileName)
			return window;
	}
	return 0;
}

void MainWindow::switchLayoutDirection()
{
	if (layoutDirection() == Qt::LeftToRight)
		qApp->setLayoutDirection(Qt::RightToLeft);
	else
		qApp->setLayoutDirection(Qt::LeftToRight);
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
	if (!window)
		return;
	mdiArea->setActiveSubWindow((QMdiSubWindow *)(window));
}
