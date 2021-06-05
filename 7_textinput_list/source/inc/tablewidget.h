#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>

class TableWidget : public QDialog
{
	Q_OBJECT
public:
	TableWidget();

private:
	QTableWidget *tableWidget;
	QPushButton *pushButtonAddRow;
	QPushButton *pushButtonRemoveRow;
	QPushButton *pushButtonAddColumn;
	QPushButton *pushButtonRemoveColumn;

private slots:
	void slotAddRow();
	void slotRemoveRow();
	void slotAddColumn();
	void slotRemoveColumn();
};

#endif
