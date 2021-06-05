#include "source/inc/text_edit.h"
#include <QtGui>
#include <QGridLayout>

Text_Input::Text_Input(QWidget *parent)
		:QMainWindow(parent)
{
	setWindowTitle("文本输入示例");
	labelReceiver = new QLabel("收件人：");
	lineEditReceiver = new QLineEdit();
	labelTheme = new QLabel("主  题：");
	lineEditTheme = new QLineEdit();
	labelContent = new QLabel("内  容：");
	textEditContent = new QTextEdit();

	fontComboBox = new QFontComboBox();
	fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

	comboBoxSize = new QComboBox();
	QFontDatabase db;
	foreach (int size, db.standardSizes())
		comboBoxSize->addItem(QString::number(size));

	boldBtn = new QToolButton();
	boldBtn->setIcon(QIcon(":/Resources/images/open.png"));
	boldBtn->setCheckable(true);
	italicBtn = new QToolButton();
	italicBtn->setIcon(QIcon(":/Resources/images/close.png"));
	italicBtn->setCheckable(true);
	underlineBtn = new QToolButton();
	underlineBtn->setIcon(QIcon(":/Resources/images/new.png"));
	underlineBtn->setCheckable(true);

	QHBoxLayout *layoutH1 = new QHBoxLayout();
	layoutH1->addWidget(fontComboBox);
	layoutH1->addWidget(comboBoxSize);
	layoutH1->addWidget(boldBtn);
	layoutH1->addWidget(italicBtn);
	layoutH1->addWidget(underlineBtn);
	layoutH1->addStretch();

	QGridLayout *layoutG1 = new QGridLayout();
	layoutG1->addWidget(labelReceiver, 0, 0);
	layoutG1->addWidget(lineEditReceiver, 0, 1);
	layoutG1->addWidget(labelTheme, 1, 0);
	layoutG1->addWidget(lineEditTheme, 1, 1);
	layoutG1->addWidget(labelContent, 2, 0);
	layoutG1->addLayout(layoutH1, 2, 1);
	layoutG1->addWidget(textEditContent, 3, 1, 4, 1);

	QWidget *centralWidget = new QWidget();
	centralWidget->setLayout(layoutG1);
	setCentralWidget(centralWidget);

	connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(SetTextFont(QString)));
	connect(comboBoxSize, SIGNAL(activated(QString)), this, SLOT(SetTextSize(QString)));
	connect(boldBtn, SIGNAL(clicked()), this, SLOT(SetBold()));
	connect(italicBtn, SIGNAL(clicked()), this, SLOT(SetItalic()));
	connect(underlineBtn, SIGNAL(clicked()), this, SLOT(SetUnderline()));
	connect(textEditContent, SIGNAL(currentCharFormatChanged(const QTextCharFormat)),
				this, SLOT(ShowCurrentFormatChanged(const QTextCharFormat)));

	format = new QTextCharFormat();
	SetTextFont("宋体");
	SetTextSize("14");
	textEditContent->setText("基于嵌入式Linux的Qt图形程序实战开发");

	setMaximumSize(800, 480);
}

void Text_Input::SetTextFont(QString fontStr)
{
	// qDebug() << fontStr;
	format->setFontFamily(fontStr);
	QTextCursor cursor = textEditContent->textCursor();
	// if (cursor.hasSelection())
	textEditContent->mergeCurrentCharFormat(*format);
}

void Text_Input::SetTextSize(QString value)
{
	format->setFontPointSize(value.toInt());
	textEditContent->mergeCurrentCharFormat(*format);
}

void Text_Input::SetBold()
{
	// qDebug() << format->fontFamily();
	format->setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
	textEditContent->mergeCurrentCharFormat(*format);
}

void Text_Input::SetItalic()
{
	format->setFontItalic(italicBtn->isChecked());
	textEditContent->mergeCurrentCharFormat(*format);
}

void Text_Input::SetUnderline()
{
	format->setFontUnderline(underlineBtn->isChecked());
	textEditContent->mergeCurrentCharFormat(*format);
}

void Text_Input::ShowCurrentFormatChanged(const QTextCharFormat &font)
{
	// qDebug() << font.fontFamily();
	fontComboBox->setCurrentIndex(fontComboBox->findText(font.fontFamily()));
	comboBoxSize->setCurrentIndex(comboBoxSize->findText(QString::number(font.fontPointSize())));
	boldBtn->setChecked(font.font().bold());
	italicBtn->setChecked(font.font().italic());
	underlineBtn->setChecked(font.font().underline());
}
