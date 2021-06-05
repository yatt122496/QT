#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QtGui>
#include <QMainWindow>

class QLabel;
class QCheckBox;
class TabWidget : public QMainWindow
{
	Q_OBJECT
public:
	TabWidget();
private:
	QLabel *pathLabel;
	QLabel *pathValueLabel;
	QLabel *sizeLabel;
	QLabel *sizeValueLabel;
	QLabel *lastReadLabel;
	QLabel *lastReadValueLabel;
	QLabel *lastModLabel;
	QLabel *lastModValueLabel;
	QCheckBox *readable;
	QCheckBox *writable;
	QCheckBox *executable;
	QLabel *ownerLabel;
	QLabel *ownerValueLabel;
	QLabel *groupLabel;
	QLabel *groupValueLabel;
	QString path;
	QTabWidget *tabWidget;
public slots:
	void getAttribute();
	void getGeneralAttribute(const QFileInfo &fileInfo);
	void getPermissionsAttribute(const QFileInfo &fileInfo);
};

#endif
