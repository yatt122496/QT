#ifndef MOREINFO_H
#define MOREINFO_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>

class MoreInfo : public QDialog
{
	Q_OBJECT
public:
	MoreInfo(QWidget *parent = 0);

private:
	QLabel *labelLimits;
	QComboBox *comboBoxLimits;
	QLabel *labelCellphone;
	QLineEdit *lineEditCellphone;
	QLabel *labelTelephone;
	QLineEdit *lineEditTelephone;
	QLabel *labelPostBox;
	QLineEdit *lineEditPostBox;
	QLabel *labelLanguage;
	QComboBox *comboBoxLanguage1;
	QComboBox *comboBoxLanguage2;
	QComboBox *comboBoxLanguage3;
	QLabel *labelVocation;
	QComboBox *comboBoxVocation;
	QLabel *labelSchool;
	QLineEdit *lineEditSchool;
	QLabel *labelHomePage;
	QLineEdit *lineEditHomePage;
	QLabel *labelState;
	QTextEdit *textEditState;
};
#endif
