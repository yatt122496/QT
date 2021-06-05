#include "source/inc/stackdlg.h"
#include <QtGui>
#include <QGridLayout>

StackDlg::StackDlg(QWidget *parent, Qt::WindowFlags fl)
		:QDialog(parent, fl)
{
	setWindowTitle(tr("栈窗体"));

	comboBoxList = new QComboBox(this);
	comboBoxList->insertItem(0, tr("窗口 1"));
	comboBoxList->insertItem(1, tr("窗口 2"));
	comboBoxList->insertItem(2, tr("窗口 3"));

	label1 = new QLabel(tr("这是窗口 1!"));
	label2 = new QLabel(tr("这是窗口 2!"));
	label3 = new QLabel(tr("这是窗口 3!"));

	textEdit1 = new QTextEdit(tr("第一个窗口。"));
	textEdit2 = new QTextEdit(tr("第二个窗口。"));
	textEdit3 = new QTextEdit(tr("第三个窗口。"));

	stackLabel = new QStackedWidget(this);
	stackLabel->addWidget(label1);
	stackLabel->addWidget(label2);
	stackLabel->addWidget(label3);

	stackText = new QStackedWidget(this);
	stackText->addWidget(textEdit1);
	stackText->addWidget(textEdit2);
	stackText->addWidget(textEdit3);

	QHBoxLayout *layoutH1 = new QHBoxLayout;
	layoutH1->addStretch();
	layoutH1->addWidget(comboBoxList);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	mainLayout->addLayout(layoutH1);
	mainLayout->addWidget(stackLabel);
	mainLayout->addWidget(stackText);
	mainLayout->setStretchFactor(comboBoxList, 1);
	mainLayout->setStretchFactor(stackLabel, 1);
	mainLayout->setStretchFactor(stackText, 3);

	connect(comboBoxList, SIGNAL(currentIndexChanged(int)), stackLabel, SLOT(setCurrentIndex(int)));
	connect(stackLabel, SIGNAL(currentChanged(int)), stackText, SLOT(setCurrentIndex(int)));
}
