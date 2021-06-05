#include "source/inc/du_test.h"
#include <QFile>

qint64 du_test(const QString &path)
{
	QDir dir(path);
	qint64 size = 0;
	foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) {
		size += fileInfo.size();
	}
	foreach (QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
		size += du_test(path + QDir::separator() + subDir);
	}
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
	qDebug()<<curSize<<uint<<"\t"<<qPrintable(path);
	return size;
}
