#include "source/inc/mdichild.h"
#include <QtGui>
#include <QGridLayout>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>

MdiChild::MdiChild()
{
	setAttribute(Qt::WA_DeleteOnClose);
	isUntitled = true;
}

void MdiChild::newFile()
{
	static int sequenceNumber = 1;

	isUntitled = true;
	curFile = tr("document%1.txt").arg(sequenceNumber++);
	setWindowTitle(curFile + "[*]");

	connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
}

bool MdiChild::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("MDI"), tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
		return false;
	}
	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	curFile = QDir(fileName).dirName();
	while (!in.atEnd()) {
        QString line = in.readLine();
        append(line);
    }
	QApplication::restoreOverrideCursor();
	setCurrentFile();

	connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
	return true;
}

bool MdiChild::save()
{
	if (isUntitled) {
		return saveAs();
	} else {
		return saveFile(curFile);
	}
}

bool MdiChild::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), curFile);
	if (fileName.isEmpty())
		return false;
	return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("MDI"), tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
		return false;
	}
	QTextStream out(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	out<<toPlainText();
	QApplication::restoreOverrideCursor();
	setCurrentFile();

	return true;
}

void MdiChild::closeEvent(QCloseEvent *event)
{
	if (maybeSave()) {
		event->accept();
	} else {
		event->ignore();
	}
}

void MdiChild::documentWasModified()
{
	setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
	if (document()->isModified()) {
		QMessageBox::StandardButton ret;
		ret = QMessageBox::warning(this, tr("MDI"), tr("'%1' has been modified.\n"
						"Do you want to save your changes?").arg(curFile),
						QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		if (ret == QMessageBox::Save)
			return save();
		else if (ret == QMessageBox::Cancel)
			return false;
	}
	return true;
}

void MdiChild::setCurrentFile()
{
	isUntitled = false;
	document()->setModified(false);
	setWindowModified(false);
	setWindowTitle(curFile + "[*]");
}
