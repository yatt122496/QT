#include "source/inc/baseinfo.h"
#include <QtGui>
#include <QGridLayout>

BaseInfo::BaseInfo(QWidget *parent)
		:QDialog(parent)
{
	labelID = new QLabel("账号：");
	lineEditID = new QLineEdit("123456789");

	QVBoxLayout *layoutV2 = new QVBoxLayout();
	layoutV2->addWidget(labelID);
	layoutV2->addWidget(lineEditID);

	labelNickName = new QLabel("昵称：");
	lineEditNickName = new QLineEdit("蓝色天空");

	QVBoxLayout *layoutV3 = new QVBoxLayout();
	layoutV3->addWidget(labelNickName);
	layoutV3->addWidget(lineEditNickName);

	labelSignature = new QLabel("个性签名：");
	textEditSignature = new QTextEdit();

	QVBoxLayout *layoutV4 = new QVBoxLayout();
	layoutV4->addWidget(labelSignature);
	layoutV4->addWidget(textEditSignature);

	labelSex = new QLabel("性别：");
	comboBoxSex = new QComboBox();
	comboBoxSex->insertItem(0, "男");
	comboBoxSex->insertItem(1, "女");

	QVBoxLayout *layoutV5 = new QVBoxLayout();
	layoutV5->addWidget(labelSex);
	layoutV5->addWidget(comboBoxSex);

	labelBirthday = new QLabel("生日：");
	comboBoxYear = new QComboBox();
	comboBoxYear->insertItem(0, "1994年");
	comboBoxYear->insertItem(1, "1995年");
	comboBoxYear->insertItem(2, "1996年");
	comboBoxYear->insertItem(3, "1997年");
	comboBoxYear->insertItem(4, "1998年");
	comboBoxYear->insertItem(5, "1999年");
	comboBoxYear->insertItem(6, "2000年");
	comboBoxYear->insertItem(7, "2001年");
	comboBoxYear->insertItem(8, "2002年");
	comboBoxYear->insertItem(9, "2003年");

	comboBoxMonth = new QComboBox();
	comboBoxMonth->insertItem(0, "1""月");
	comboBoxMonth->insertItem(1, "2""月");
	comboBoxMonth->insertItem(2, "3""月");
	comboBoxMonth->insertItem(3, "4""月");
	comboBoxMonth->insertItem(4, "5""月");
	comboBoxMonth->insertItem(5, "6""月");
	comboBoxMonth->insertItem(6, "7""月");
	comboBoxMonth->insertItem(7, "8""月");
	comboBoxMonth->insertItem(8, "9""月");
	comboBoxMonth->insertItem(9, "10""月");
	comboBoxMonth->insertItem(10, "11""月");
	comboBoxMonth->insertItem(11, "12""月");

	comboBoxDay = new QComboBox();
	comboBoxDay->insertItem(0, "1日");
	comboBoxDay->insertItem(1, "2日");
	comboBoxDay->insertItem(2, "3日");
	comboBoxDay->insertItem(3, "4日");
	comboBoxDay->insertItem(4, "5日");
	comboBoxDay->insertItem(5, "6日");
	comboBoxDay->insertItem(6, "7日");
	comboBoxDay->insertItem(7, "8日");
	comboBoxDay->insertItem(8, "9日");
	comboBoxDay->insertItem(9, "10日");
	comboBoxDay->insertItem(10, "11日");
	comboBoxDay->insertItem(11, "12日");
	comboBoxDay->insertItem(12, "13日");
	comboBoxDay->insertItem(13, "14日");
	comboBoxDay->insertItem(14, "15日");
	comboBoxDay->insertItem(15, "16日");
	comboBoxDay->insertItem(16, "17日");
	comboBoxDay->insertItem(17, "18日");
	comboBoxDay->insertItem(18, "19日");
	comboBoxDay->insertItem(19, "20日");
	comboBoxDay->insertItem(20, "21日");
	comboBoxDay->insertItem(21, "22日");
	comboBoxDay->insertItem(22, "23日");
	comboBoxDay->insertItem(23, "24日");
	comboBoxDay->insertItem(24, "25日");
	comboBoxDay->insertItem(25, "26日");
	comboBoxDay->insertItem(26, "27日");
	comboBoxDay->insertItem(27, "28日");
	comboBoxDay->insertItem(28, "29日");
	comboBoxDay->insertItem(29, "30日");
	comboBoxDay->insertItem(30, "31日");

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(comboBoxYear);
	layoutH1->addWidget(comboBoxMonth);
	layoutH1->addWidget(comboBoxDay);

	QVBoxLayout *layoutV6 = new QVBoxLayout();
	layoutV6->addWidget(labelBirthday);
	layoutV6->addLayout(layoutH1);

	labelAge = new QLabel("年龄：");
	comboBoxAge = new QComboBox();
	QStringList listAge;
	listAge<<"20"<<"21"<<"22"<<"23"<<"24"<<"25";
	comboBoxAge->addItems(listAge);

	QVBoxLayout *layoutV7 = new QVBoxLayout();
	layoutV7->addWidget(labelAge);
	layoutV7->addWidget(comboBoxAge);

	labelZodiac = new QLabel("生肖：");
	comboBoxZodiac = new QComboBox();
	QStringList listZodiac;
	listZodiac<<"鼠"<<"牛"<<"虎"<<"兔"<<"龙"<<"蛇"<<"马"<<"羊"<<"猴"<<"鸡"<<"狗"<<"猪";
	comboBoxZodiac->addItems(listZodiac);

	QVBoxLayout *layoutV8 = new QVBoxLayout();
	layoutV8->addWidget(labelZodiac);
	layoutV8->addWidget(comboBoxZodiac);

	labelConstellation = new QLabel("星座：");
	comboBoxConstellation = new QComboBox();
	QStringList listConstellation;
	listConstellation<<"水瓶座"<<"双鱼座"<<"白羊座"<<"金牛座"<<"双子座"<<"巨蟹座"<<"狮子座"
			<<"处女座"<<"天平座"<<"天蝎座"<<"射手座"<<"摩羯座";
	comboBoxConstellation->addItems(listConstellation);

	QVBoxLayout *layoutV9 = new QVBoxLayout();
	layoutV9->addWidget(labelConstellation);
	layoutV9->addWidget(comboBoxConstellation);

	labelBlood = new QLabel("血型：");
	comboBoxBlood = new QComboBox();
	QStringList listBlood;
	listBlood<<"A型"<<"B型"<<"AB型"<<"O型"<<"其他";
	comboBoxBlood->addItems(listBlood);

	QVBoxLayout *layoutV10 = new QVBoxLayout();
	layoutV10->addWidget(labelBlood);
	layoutV10->addWidget(comboBoxBlood);

	QHBoxLayout *layoutH2 = new QHBoxLayout();
	layoutH2->addLayout(layoutV3);
	layoutH2->addLayout(layoutV2);

	QGridLayout *layoutG1 = new QGridLayout();
	layoutG1->addLayout(layoutV5, 0, 0);
	layoutG1->addLayout(layoutV6, 0, 1, 1, 3);
	layoutG1->addLayout(layoutV7, 1, 0);
	layoutG1->addLayout(layoutV8, 1, 1);
	layoutG1->addLayout(layoutV9, 1, 2);
	layoutG1->addLayout(layoutV10, 1, 3);

	pushButtonOk = new QPushButton("确定");
	pushButtonCancel = new QPushButton("取消");

	QHBoxLayout *layoutH3 = new QHBoxLayout();
	layoutH3->addStretch();
	layoutH3->addWidget(pushButtonOk);
	layoutH3->addWidget(pushButtonCancel);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(layoutH2);
	mainLayout->addLayout(layoutV4);
	mainLayout->addLayout(layoutG1);
	mainLayout->addLayout(layoutH3);
	setLayout(mainLayout);
}
