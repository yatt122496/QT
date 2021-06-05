#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
	Cell();
	void setData(int role, const QVariant &);
	QVariant data(int role);
	void setcontentText(QString &);
	QString contentText();

private:
	QVariant value();
	QVariant cachedValue;
};

#endif
