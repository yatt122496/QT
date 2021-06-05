#ifndef STACKDLG_H
#define STACKDLG_H

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QComboBox>
#include <QStackedWidget>

class StackDlg : public QDialog
{
	Q_OBJECT
public:
	StackDlg(QWidget *parent = 0, Qt::WindowFlags fl = 0);

private:
	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	QTextEdit *textEdit1;
	QTextEdit *textEdit2;
	QTextEdit *textEdit3;
	QComboBox *comboBoxList;
	QStackedWidget *stackLabel;
	QStackedWidget *stackText;
};

#endif
