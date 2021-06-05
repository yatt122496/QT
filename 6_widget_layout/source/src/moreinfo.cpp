#include "source/inc/moreinfo.h"
#include <QtGui>
#include <QGridLayout>

MoreInfo::MoreInfo(QWidget *parent)
		:QDialog(parent)
{
	labelLimits = new QLabel("请选择以下联系资料显示范围：");
	comboBoxLimits = new QComboBox();
	comboBoxLimits->insertItem(0, "完全公开");
	comboBoxLimits->insertItem(1, "仅好友可见");
	comboBoxLimits->insertItem(2, "仅自己可见");

	labelCellphone = new QLabel("手机：");
	lineEditCellphone = new QLineEdit();

	labelTelephone = new QLabel("电话：");
	lineEditTelephone = new QLineEdit();

	labelPostBox = new QLabel("邮箱：");
	lineEditPostBox = new QLineEdit();

	QGridLayout *layoutG1 = new QGridLayout();
	layoutG1->addWidget(labelLimits, 0, 0);
	layoutG1->addWidget(labelCellphone, 0, 1);
	layoutG1->addWidget(comboBoxLimits, 1, 0);
	layoutG1->addWidget(lineEditCellphone, 1, 1);
	layoutG1->addWidget(labelTelephone, 2, 0);
	layoutG1->addWidget(labelPostBox, 2, 1);
	layoutG1->addWidget(lineEditTelephone, 3, 0);
	layoutG1->addWidget(lineEditPostBox, 3, 1);

	labelLanguage = new QLabel("语言：");
	comboBoxLanguage1 = new QComboBox();
	comboBoxLanguage1->insertItem(0, "中文简体");
	comboBoxLanguage1->insertItem(1, "中文繁体");
	comboBoxLanguage2 = new QComboBox();
	comboBoxLanguage2->insertItem(0, "中文简体");
	comboBoxLanguage2->insertItem(1, "中文繁体");
	comboBoxLanguage3 = new QComboBox();
	comboBoxLanguage3->insertItem(0, "中文简体");
	comboBoxLanguage3->insertItem(1, "中文繁体");

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(comboBoxLanguage1);
	layoutH1->addWidget(comboBoxLanguage2);
	layoutH1->addWidget(comboBoxLanguage3);
	QVBoxLayout *layoutV1 = new QVBoxLayout();
	layoutV1->addWidget(labelLanguage);
	layoutV1->addLayout(layoutH1);

	labelVocation = new QLabel("职业：");
	comboBoxVocation = new QComboBox();
	comboBoxVocation->insertItem(0, "学生");
	comboBoxVocation->insertItem(1, "计算机/互联网/IT");
	comboBoxVocation->insertItem(2, "其他");

	labelSchool = new QLabel("毕业院校：");
	lineEditSchool = new QLineEdit();

	QGridLayout *layoutG2 = new QGridLayout();
	layoutG2->addWidget(labelVocation, 0, 0);
	layoutG2->addWidget(labelSchool, 0, 1);
	layoutG2->addWidget(comboBoxVocation, 1, 0);
	layoutG2->addWidget(lineEditSchool, 1, 1);

	labelHomePage = new QLabel("个人主页：");
	lineEditHomePage = new QLineEdit();

	QVBoxLayout *layoutV2 = new QVBoxLayout();
	layoutV2->addWidget(labelHomePage);
	layoutV2->addWidget(lineEditHomePage);

	labelState = new QLabel("个人说明：");
	textEditState = new QTextEdit();

	QVBoxLayout *layoutV3 = new QVBoxLayout();
	layoutV3->addWidget(labelState);
	layoutV3->addWidget(textEditState);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(layoutG1);
	mainLayout->addLayout(layoutV1);
	mainLayout->addLayout(layoutG2);
	mainLayout->addLayout(layoutV2);
	mainLayout->addLayout(layoutV3);
	setLayout(mainLayout);
}
