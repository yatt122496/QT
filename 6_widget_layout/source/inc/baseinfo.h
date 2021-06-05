#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>

class BaseInfo : public QDialog
{
	Q_OBJECT
public:
	BaseInfo(QWidget *parent = 0);

private:
	QLabel *labelID;
	QLineEdit *lineEditID;
	QLabel *labelNickName;
	QLineEdit *lineEditNickName;
	QLabel *labelSignature;
	QTextEdit *textEditSignature;
	QLabel *labelSex;
	QComboBox *comboBoxSex;
	QLabel *labelBirthday;
	QComboBox *comboBoxYear;
	QComboBox *comboBoxMonth;
	QComboBox *comboBoxDay;
	QLabel *labelAge;
	QComboBox *comboBoxAge;
	QLabel *labelZodiac;
	QComboBox *comboBoxZodiac;
	QLabel *labelConstellation;
	QComboBox *comboBoxConstellation;
	QLabel *labelBlood;
	QComboBox *comboBoxBlood;
	QPushButton *pushButtonOk;
	QPushButton *pushButtonCancel;
};
#endif
