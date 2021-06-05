#include "source/inc/fileinformation.h"
#include <QtGui>
#include <QGridLayout>
#include <QFileDialog>

FileInformation::FileInformation(QWidget *parent, Qt::WindowFlags f)
		: QDialog(parent)
{
	setWindowTitle(tr("File Information"));
	labelFileName = new QLabel(tr("File Name:"));
	lineEditFileName = new QLineEdit();

	pushButtonFile = new QPushButton("File", this);
	plainTextEditFileInformation = new QPlainTextEdit();
	plainTextEditFileInformation->setEnabled(false);

	checkBoxIsDir = new QCheckBox("Dir");
	checkBoxIsFile = new QCheckBox("File");
	checkBoxIsSymLink = new QCheckBox("SymLink");
	checkBoxIsHidden = new QCheckBox("Hidden");
	checkBoxIsReadable = new QCheckBox("Readable");
	checkBoxIsWritable = new QCheckBox("Writable");
	checkBoxIsExecutable = new QCheckBox("Executable");

	pushButtonGet = new QPushButton("Get", this);

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(labelFileName);
	layoutH1->addWidget(lineEditFileName);
	layoutH1->addWidget(pushButtonFile);

	QHBoxLayout *layoutH2 = new QHBoxLayout();
	layoutH2->addWidget(checkBoxIsDir);
	layoutH2->addWidget(checkBoxIsFile);
	layoutH2->addWidget(checkBoxIsSymLink);
	layoutH2->addWidget(checkBoxIsHidden);
	layoutH2->addWidget(checkBoxIsReadable);
	layoutH2->addWidget(checkBoxIsWritable);
	layoutH2->addWidget(checkBoxIsExecutable);

	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->addLayout(layoutH1);
	layoutMain->addWidget(plainTextEditFileInformation, 1, 0);
	layoutMain->addLayout(layoutH2);
	layoutMain->addWidget(pushButtonGet);

	setLayout(layoutMain);
	setMaximumSize(800, 480);

	connect(pushButtonFile, SIGNAL(clicked()), this, SLOT(slotFile()));
	connect(pushButtonGet, SIGNAL(clicked()), this, SLOT(slotGet()));
}

void FileInformation::slotFile()
{
	QString str = QFileDialog::getOpenFileName(this, tr("Open File Dialog"),
								tr("."), "files(*)");
	lineEditFileName->setText(str);
}

void FileInformation::slotGet()
{
	getFileInformation(lineEditFileName->text());
}

void FileInformation::getFileInformation(QString file)
{
	QFileInfo info(file);
	plainTextEditFileInformation->clear();
	qint64 size = info.size();
	char uint = 'B';
	qint64 curSize = size;
	if (curSize > 1024) {
		curSize /= 1024;
		uint = 'K';
		if (curSize > 1024) {
			curSize /= 1024;
			uint = 'M';
			if (curSize > 1024) {
				curSize /= 1024;
				uint = 'G';
			}
		}
	}
	QDateTime created = info.created();
	QDateTime lastModified = info.lastModified();
	QDateTime lastRead = info.lastRead();
	bool isDir = info.isDir();
	bool isFile = info.isFile();
	bool isSymLink = info.isSymLink();
	bool isHidden = info.isHidden();
	bool isReadable = info.isReadable();
	bool isWritable = info.isWritable();
	bool isExecutable = info.isExecutable();

	plainTextEditFileInformation->appendPlainText(QString(tr("size\t%1%2")).arg(curSize).arg(uint));
	plainTextEditFileInformation->appendPlainText(QString(tr("create\t%1")).arg(created.toString()));
	plainTextEditFileInformation->appendPlainText(QString(tr("lastModified\t%1")).arg(lastModified.toString()));
	plainTextEditFileInformation->appendPlainText(QString(tr("lastRead\t%1")).arg(lastRead.toString()));

	checkBoxIsDir->setCheckState(isDir ? Qt::Checked : Qt::Unchecked);
	checkBoxIsFile->setCheckState(isFile ? Qt::Checked : Qt:: Unchecked);
	checkBoxIsSymLink->setCheckState(isSymLink ? Qt::Checked : Qt:: Unchecked);
	checkBoxIsHidden->setCheckState(isHidden ? Qt::Checked : Qt:: Unchecked);
	checkBoxIsReadable->setCheckState(isReadable ? Qt::Checked : Qt:: Unchecked);
	checkBoxIsWritable->setCheckState(isWritable ? Qt::Checked : Qt:: Unchecked);
	checkBoxIsExecutable->setCheckState(isExecutable ? Qt::Checked : Qt:: Unchecked);
}
