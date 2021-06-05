#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>

class Text_Input : public QMainWindow
{
	Q_OBJECT
public:
	Text_Input(QWidget *parent = 0);

private:
	QLabel *labelReceiver;
	QLineEdit *lineEditReceiver;
	QLabel *labelTheme;
	QLineEdit *lineEditTheme;
	QLabel *labelContent;
	QTextEdit *textEditContent;
	QFontComboBox *fontComboBox;
	QComboBox *comboBoxSize;

	QToolButton *boldBtn;
	QToolButton *italicBtn;
	QToolButton *underlineBtn;

	QTextCharFormat *format;

public slots:
	void SetTextFont(QString);
	void SetTextSize(QString);
	void SetBold();
	void SetItalic();
	void SetUnderline();
	void ShowCurrentFormatChanged(const QTextCharFormat &font);
};

#endif
