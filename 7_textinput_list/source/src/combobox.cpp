#include "source/inc/combobox.h"
#include <QtGui>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>

ComboBox::ComboBox()
{
	QComboBox *comboBoxMain = new QComboBox();
	setWindowTitle("QComboBox");
	resize(300, 200);
	comboBoxMain->setEditable(true);
	comboBoxMain->insertItem(0, QIcon(":/Resource/images/new.png"), "New");
	comboBoxMain->insertItem(1, QIcon(":/Resource/images/open.png"), "Open");
	comboBoxMain->insertItem(2, QIcon(":/Resource/images/close.png"), "Close");
	comboBoxMain->insertItem(3, QIcon(":/Resource/images/help.png"), "Help");

	QLabel *label = new QLabel("QComboBox");

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(comboBoxMain);
	layout->addWidget(label);

	connect(comboBoxMain, SIGNAL(activated(const QString &)), label, SLOT(setText(const QString &)));

	setLayout(layout);
}
