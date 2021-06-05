#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include "source/inc/cell.h"

class Table : public QTableWidget
{
	Q_OBJECT
public:
	Table(QWidget *parent = 0);

private:
	QString contentText(int, int);
	void setContentText(int, int, QString &);
	void clear();
	enum {RowCount = 999, ColumnCount = 26};
	Cell *cell(int, int);
	QTableWidgetSelectionRange selectedRange();

public slots:
	void cut();
	void copy();
	void paste();
	void del();
};

#endif
