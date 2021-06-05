#include "source/inc/tablewidget.h"
#include <QtGui>
#include <QGridLayout>
#include <QComboBox>

TableWidget::TableWidget()
{
	setWindowTitle("表格示例");
	tableWidget = new QTableWidget(3, 4);
	tableWidget->resize(350, 200);

	QStringList header;
	header<<"姓名"<<"照片"<<"年龄"<<"性别";
	tableWidget->setHorizontalHeaderLabels(header);

	tableWidget->setItem(0, 0, new QTableWidgetItem("张强"));
	tableWidget->setItem(1, 0, new QTableWidgetItem("王永"));
	tableWidget->setItem(2, 0, new QTableWidgetItem("李丽"));

	tableWidget->setItem(0, 1, new QTableWidgetItem(QIcon(":Resource/images/add.png"), ""));
	tableWidget->setItem(1, 1, new QTableWidgetItem(QIcon(":Resource/images/open.png"), ""));
	tableWidget->setItem(2, 1, new QTableWidgetItem(QIcon(":Resource/images/close.png"), ""));

	tableWidget->setItem(0, 2, new QTableWidgetItem("11"));
	tableWidget->setItem(1, 2, new QTableWidgetItem("22"));
	tableWidget->setItem(2, 2, new QTableWidgetItem("33"));

	QComboBox *comboBox = new QComboBox();
	comboBox->addItem("男");
	comboBox->addItem("女");
	QComboBox *comboBox1 = new QComboBox();
	comboBox1->addItem("男");
	comboBox1->addItem("女");
	QComboBox *comboBox2 = new QComboBox();
	comboBox2->addItem("男");
	comboBox2->addItem("女");

	tableWidget->setCellWidget(0, 3, comboBox);
	tableWidget->setCellWidget(1, 3, comboBox1);
	tableWidget->setCellWidget(2, 3, comboBox2);

	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

	pushButtonAddRow = new QPushButton("添加行");
	pushButtonRemoveRow = new QPushButton("删除行");
	pushButtonAddColumn = new QPushButton("添加列");
	pushButtonRemoveColumn = new QPushButton("删除列");

	QVBoxLayout *layoutV1 = new QVBoxLayout();
	layoutV1->addWidget(pushButtonAddRow);
	layoutV1->addWidget(pushButtonRemoveRow);
	layoutV1->addWidget(pushButtonAddColumn);
	layoutV1->addWidget(pushButtonRemoveColumn);
	layoutV1->addStretch();

	QHBoxLayout *layoutMain = new QHBoxLayout();
	layoutMain->addWidget(tableWidget);
	layoutMain->addLayout(layoutV1);

	setLayout(layoutMain);

	connect(pushButtonAddRow, SIGNAL(clicked()), this, SLOT(slotAddRow()));
	connect(pushButtonRemoveRow, SIGNAL(clicked()), this, SLOT(slotRemoveRow()));
	connect(pushButtonAddColumn, SIGNAL(clicked()), this, SLOT(slotAddColumn()));
	connect(pushButtonRemoveColumn, SIGNAL(clicked()), this, SLOT(slotRemoveColumn()));

	setMinimumSize(550, 300);
	setMaximumSize(800, 480);
}

void TableWidget::slotAddRow()
{
	int num = tableWidget->rowCount();
	tableWidget->insertRow(num);
}

void TableWidget::slotRemoveRow()
{
	int num = tableWidget->rowCount();
	tableWidget->removeRow(num - 1);
}

void TableWidget::slotAddColumn()
{
	int num = tableWidget->columnCount();
	tableWidget->insertColumn(num);
}

void TableWidget::slotRemoveColumn()
{
	int num = tableWidget->columnCount();
	tableWidget->removeColumn(num - 1);
}
