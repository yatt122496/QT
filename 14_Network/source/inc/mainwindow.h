#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include "source/inc/myftpmanager.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow();

private slots:
	void FtpUpLoad();
	void FtpDownLoad();
	void updateUpLoad(qint64, qint64);
	void updateDownLoad(qint64, qint64);

private:
	QPushButton *buttonUpLoad;
	QProgressBar *progressBarUpLoad;
	QPushButton *buttonDownLoad;
	QProgressBar *progressBarDownLoad;
	MyFtpManager *manager;
};
#endif
