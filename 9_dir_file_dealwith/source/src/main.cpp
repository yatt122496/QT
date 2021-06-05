#include "source/inc/du_test.h"
#include "source/inc/fileinformation.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QFile>
#include <QDate>

#define SWITCH_Du_test				0
#define SWITCH_FileInformation		1
#define SWITCH_Printf				0

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_Du_test
	QStringList args = a.arguments();
	QString path;
	if (args.count() > 1) {
		path = args[1];
	} else {
		path = QDir::currentPath();
	}
	qDebug() << path;
	du_test(path);
#endif
#if SWITCH_FileInformation
	FileInformation fileInformation;
	fileInformation.show();
#endif
#if SWITCH_Printf
	qDebug() <<QObject::tr("lkxgghs")<<qSetFieldWidth(10)<<right<<qSetPadChar('-')<<90;
	qDebug() <<qSetPadChar('*')<<qSetFieldWidth(10)<<left<<123<<right<<123;
	qDebug() <<qSetPadChar('-')<<qSetFieldWidth(2)<<123<<','<<hex<<123;
	qDebug() <<123<<','<<hex<<123;
	qDebug() <<showbase<<bin<<123;
	qDebug() <<forcepoint<<95.0;
	qDebug() <<95.0<<10;
	qDebug() <<scientific<<95.0;
	qDebug() <<fixed<<95.0;
	qDebug() <<forcesign<<123<<','<<45.6;
	qDebug() <<showbase<<uppercasebase<<hex<<123<<','<<scientific<<95.0;
	qDebug() <<qSetPadChar('*')<<left<<qSetFieldWidth(3)<<123;
#endif

    return a.exec();
}
