#ifndef MYFTPMANAGER_H
#define MYFTPMANAGER_H

#include <QUrl>
#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class MyFtpManager : public QObject
{
    Q_OBJECT
public:
    explicit MyFtpManager(QObject *parent = 0);

    QNetworkReply *put(const QString &localPath, const QString &uploadPath);
    QNetworkReply *get(const QString &downloadPath, const QString &localPath);

    inline void setPort(int port) { url.setPort(port); }
    inline void setHost(const QString &host) { url.setHost(host); }
    inline void setPath(const QString &path) { url.setPath(path); }
    inline void setUserName(const QString &userName) { url.setUserName(userName); }
    inline void setPassword(const QString &password) { url.setPassword(password); }

public slots:
    void uploadFinished();
    void downloadFinished();
    void error(QNetworkReply::NetworkError error);

private:
    QUrl url;
    QString path;
    QNetworkAccessManager manager;
};

#endif // MYFTPMANAGER_H