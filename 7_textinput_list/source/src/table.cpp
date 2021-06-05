#include "source/inc/table.h"
#include <QtGui>
#include <QGridLayout>
#include <QApplication>
#include <QMessageBox>

Table::Table(QWidget *parent)
		:QTableWidget(parent)
{
	setItemPrototype(new Cell());
	setSelectionMode(ContiguousSelection);
	clear();
}

QTableWidgetSelectionRange Table::selectedRange()
{
	QList<QTableWidgetSelectionRange> ranges = selectedRanges();
	if (ranges.isEmpty())
		return QTableWidgetSelectionRange();
	return ranges.first();
}

void Table::clear()
{
	setRowCount(0);
	setColumnCount(0);
	setRowCount(RowCount);
	setColumnCount(ColumnCount);

	for (int i = 0; i < ColumnCount; i++) {
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setText(QString(QChar('A' + i)));
		setHorizontalHeaderItem(i, item);
	}
}

void Table::copy()
{
	QTableWidgetSelectionRange range = selectedRange();
	QString str;

	for (int i = 0; i < range.rowCount(); i++) {
		if (i > 0)
			str += "\0";
		for (int j = 0; j < range.columnCount(); j++) {
			if (j > 0) {
				str += "\t";
			}
			str+=contentText(range.topRow() + i, range.leftColumn() + j);
		}

	}
	QApplication::clipboard()->setText(str);
}

void Table::cut()
{
	copy();
	del();
}

void Table::paste()
{
	QTableWidgetSelectionRange range = selectedRange();
	QString str = QApplication::clipboard()->text();
	QStringList rows = str.split('\n');
	int numRows = rows.count();
	int numColumns = rows.first().count('\t') + 1;
	if ((range.rowCount() * range.columnCount() != 1) &&
			((range.rowCount() != numRows) || (range.columnCount() != numColumns))) {
		QMessageBox::information(this, "Tabel", "The information cannot be pasted"
				" because the copy and paste areas aren't the same size");
		return;
	}
	for (int i = 0; i < numColumns; i++) {
		QStringList columns = rows[i].split('\t');
		for (int j = 0; j < numColumns; ++j) {
			int row = range.topRow() + i;
			int column = range.leftColumn() + j;
			if (row < RowCount && column < ColumnCount)
				setContentText(row, column, columns[j]);
		}
	}
}

void Table::del()
{
	QList<QTableWidgetItem *> item = selectedItems();
	if (!item.isEmpty()) {
		foreach (QTableWidgetItem *item, item)
		delete item;
	}
}

Cell *Table::cell(int row, int column)
{
	return static_cast<Cell *>(item(row, column));
}

void Table::setContentText(int row, int column, QString &text)
{
	Cell *c = cell(row, column);
	if (!c) {
		c = new Cell;
		setItem(row, column, c);
	}
	c->setcontentText(text);
}

QString Table::contentText(int row, int column)
{
	Cell *c = cell(row, column);
	if (c) {
		return c->contentText();
	} else {
		return "";
	}
}
