#include <QtGui>
#include "source/inc/stringview.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QInputDialog>

StringView::StringView(QMainWindow *parent)
		: QMainWindow(parent)
{
	setWindowTitle("stringlistmodel");
	createActions();
	createMenus();
	setupModel();
	setupView();
}

void StringView::setupModel()
{
	QStringList strlist;
	strlist << "one" << "two" << "three" << "four";
	model = new StringListModel(strlist, this);
}

void StringView::setupView()
{
	list = new QListView();
	list->setModel(model);
	setCentralWidget(list);
}

void StringView::soltOpenFile()
{
	name = QFileDialog::getOpenFileName(this, tr("open file dialog"), ".", "strip files(*.txt)");
	if (!name.isEmpty())
		openFile(name);
}

void StringView::soltSaveFile()
{
	if (name.isEmpty())
		return;
	QFile file(name);
	if (!file.open(QFile::WriteOnly))
		return;
	QTextStream in(&file);
	for (int i = 0; i < model->rowCount(); ++i) {
		QModelIndex index = model->index(i);
		QString str = model->data(index, Qt::DisplayRole).toString();
		in<<str<<",";
	}
}

void StringView::openFile(QString path)
{
	if (!path.isEmpty()) {
		QFile file(path);
		if (file.open(QFile::ReadOnly | QFile::Text)) {
			QTextStream out(&file);
			QString str;
			model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());
			int pos = 0;
			str = out.readLine();
			if (!str.isEmpty()) {
				QStringList pieces = str.split(",", QString::SkipEmptyParts);
				QString ss;
				foreach (ss, pieces) {
					model->insertRows(pos, 1, QModelIndex());
					model->setData(model->index(pos), ss);
					pos++;
				}
			}
			file.close();
		}
	}
}

void StringView::soltInsertRows()
{
	bool ok;
	QModelIndex index = list->currentIndex();
	int rows = QInputDialog::getInt(this, "Insert Row Number", tr("Please input number."),
								1, 1, 10, 1, &ok);
	if (ok) {
		model->insertRows(index.row(), rows, QModelIndex());
	}
}

void StringView::soltRemoveRows()
{
	QModelIndex index = list->currentIndex();
	model->removeRows(index.row(), 1, QModelIndex());
}

void StringView::createActions()
{
	actionOpen = new QAction(tr("Open"), this);
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(soltOpenFile()));
	actionSave = new QAction(tr("Save"), this);
	connect(actionSave, SIGNAL(triggered()), this, SLOT(soltSaveFile()));
	actionInsert = new QAction(tr("Insert"), this);
	connect(actionInsert, SIGNAL(triggered()), this, SLOT(soltInsertRows()));
	actionRemove = new QAction(tr("Remove"), this);
	connect(actionRemove, SIGNAL(triggered()), this, SLOT(soltRemoveRows()));
}

void StringView::createMenus()
{
	menuOpen = menuBar()->addMenu("Open");
	menuOpen->addAction(actionOpen);
	menuSave = menuBar()->addMenu("Save");
	menuSave->addAction(actionSave);
	menuInsert = menuBar()->addMenu("Insert");
	menuInsert->addAction(actionInsert);
	menuRemove = menuBar()->addMenu("Remove");
	menuRemove->addAction(actionRemove);
}
