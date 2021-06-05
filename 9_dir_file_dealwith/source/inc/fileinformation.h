#ifndef FILEINFORMATION_H
#define FILEINFORMATION_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QCheckBox>

class FileInformation : public QDialog
{
	Q_OBJECT
public:
	FileInformation(QWidget *parent = 0, Qt::WindowFlags flags = 0);

private:
	QLabel *labelFileName;
	QLineEdit *lineEditFileName;
	QPushButton *pushButtonFile;
	QPlainTextEdit *plainTextEditFileInformation;

	QCheckBox *checkBoxIsDir;
	QCheckBox *checkBoxIsFile;
	QCheckBox *checkBoxIsSymLink;
	QCheckBox *checkBoxIsHidden;
	QCheckBox *checkBoxIsReadable;
	QCheckBox *checkBoxIsWritable;
	QCheckBox *checkBoxIsExecutable;

	QPushButton *pushButtonGet;
	void getFileInformation(QString file);

public slots:
	void slotFile();
	void slotGet();
};
#endif
