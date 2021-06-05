#include "source/inc/mainwindow.h"
#include <QtGui>
#include <QGridLayout>

MainWindow::MainWindow()
{
	manager = new MyFtpManager(this);
	manager->setHost("127.0.0.1");
	manager->setPort(21);
	// manager->setUserName("zhangsan");
	// manager->setPassword("123465");

	buttonUpLoad = new QPushButton("上传");
	connect(buttonUpLoad, SIGNAL(clicked()), this, SLOT(FtpUpLoad()));
	progressBarUpLoad = new QProgressBar();
	progressBarUpLoad->setMinimum(0);

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(buttonUpLoad);
	layoutH1->addWidget(progressBarUpLoad);
	layoutH1->addStretch();

	buttonDownLoad = new QPushButton("下载");
	connect(buttonDownLoad, SIGNAL(clicked()), this, SLOT(FtpDownLoad()));
	progressBarDownLoad = new QProgressBar();
	progressBarDownLoad->setMinimum(0);

	QHBoxLayout *layoutH2 = new QHBoxLayout();
	layoutH2->addWidget(buttonDownLoad);
	layoutH2->addWidget(progressBarDownLoad);
	layoutH2->addStretch();

	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->addLayout(layoutH1);
	layoutMain->addLayout(layoutH2);

	setLayout(layoutMain);

	setMinimumSize(600, 400);
	setMaximumSize(800, 480);
}

void MainWindow::FtpUpLoad()
{
    QDir dir(":Resource/images");

    QStringList filter;
    filter << "*.jpg" << "*.bmp" << "*.png";
    QList<QFileInfo> list = QList<QFileInfo>(dir.entryInfoList(filter));

    foreach (QFileInfo info, list)
    {
        QNetworkReply *pReply = manager->put(info.filePath(), QString("/images/%1").arg(info.fileName()));
        connect(pReply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(updateUpLoad(qint64,qint64)));
    }
}

void MainWindow::FtpDownLoad()
{
    QNetworkReply *pReply = manager->get("/images/Qt.png", "./DSCF21061.jpg");
    connect(pReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(updateDownLoad(qint64,qint64)));
}

void MainWindow::updateUpLoad(qint64 bytesSent, qint64 bytesTotal)
{
	progressBarUpLoad->setMaximum(bytesTotal);
	progressBarUpLoad->setValue(bytesSent);
}

void MainWindow::updateDownLoad(qint64 bytesReceived, qint64 bytesTotal)
{
	progressBarDownLoad->setMaximum(bytesTotal);
	progressBarDownLoad->setValue(bytesReceived);
}
