#include "source/inc/httpwindow.h"
#include <QNetworkRequest>
#include <QtGui>

HttpWindow::HttpWindow(QWidget *parent)
		: QDialog(parent)
{
	urlLineEdit = new QLineEdit("http://");
	urlLabel = new QLabel(tr("&URL:"));
	urlLabel->setBuddy(urlLineEdit);

	statusLabel = new QLabel(tr("请输入需要下载的网址。"));
	downloadButton = new QPushButton(tr("下载"));
	downloadButton->setDefault(true);

	progressDialog = new QProgressDialog(this);
	http = new QHttp(this);

	connect(urlLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableDownloadButton()));
	connect(http, SIGNAL(requestFinished(int, bool)), this, SLOT(httpRequestFinished(int, bool)));
	connect(http, SIGNAL(dateReadProgress(int, int)), this, SLOT(updateDataReadProgress(int, int)));
	connect(http, SIGNAL(reponseHeaderReceived(const QHttpResponseHeader &)), this,
				SLOT(readResponseHeader(const QHttpResponseHeader &)));

	connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));
	connect(downloadButton, SIGNAL(clicked()), this, SLOT(downloadFile()));

	

}
