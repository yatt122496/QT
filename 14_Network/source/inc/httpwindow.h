#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QDialog>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QProgressDialog>
#include <QPushButton>
#include <QtNetWork>
#include <QHttpPart>

QT_BEGIN_NAMESPACE
// class QHttpResponseHeader;
class QAuthenticator;
QT_END_NAMESPACE

class HttpWindow : public QDialog
{
	Q_OBJECT
public:
	HttpWindow(QWidget *parent = 0);

private slots:
	void downloadFile();
	void cancelDownload();
	void httpRequestFinished(int, bool);
	void readResponseHeader(const QHttpResponseHeader &);
	void updateDataReadProgress(int, int);
	void enableDownloadButton();

private:
	QLabel *statusLabel;
	QLabel *urlLabel;
	QLineEdit *urlLineEdit;
	QProgressDialog *progressDialog;
	QPushButton *downloadButton;
	QHttp *http;
	QFile *file;
	int httpGetId;
	bool httpRequestAborted;
};

#endif
