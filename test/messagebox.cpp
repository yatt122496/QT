#include "messagebox.h"
#include <QtGui>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QPushButton>
#include "ui_mainwindow.h"

MessageBoxw::MessageBoxw(QWidget *parent)
	:QDialog(parent)
{
    QString a = "aaa111";
	label = new QTextEdit;
    comboBoxMessage = new QComboBox();
	comboBoxMessage->insertItem(0, "询问消息框");
	comboBoxMessage->insertItem(1, "提示消息框");
	comboBoxMessage->insertItem(2, "警告消息框");
	comboBoxMessage->insertItem(3, "致命错误消息框");
	comboBoxMessage->insertItem(4, "关于消息框");
	comboBoxMessage->insertItem(5, "关于Qt消息框");
	comboBoxMessage->insertItem(6, "自定义消息框");

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setMargin(10);
	mainLayout->setSpacing(20);
	mainLayout->addWidget(label);
	mainLayout->addWidget(comboBoxMessage);
	setLayout(mainLayout);

    connect(comboBoxMessage, SIGNAL(activated(int)), this, SLOT(slotMessageBox(int)));

	setWindowTitle("消息框实例");
}

void MessageBoxw::slotMessageBox(int index)
{
	switch (index) {
	case 0:{
		Question();
		break;
	}
	case 1:{
		Information();
		break;
	}
	case 2:{
		Warning();
		break;
	}
	case 3:{
		/* code */
		Critical();
		break;
	}
	case 4:{
		/* code */
		About();
		break;
	}
	case 5:{
		/* code */
		AboutQt();
		break;
	}
	case 6:{
		/* code */
		Custom();
		break;
	}
	default:
		break;
	}
}

void MessageBoxw::Question()
{
	switch (QMessageBox::question(this, "询问消息框", "搜索到文档的末尾，要重新搜索吗？",
				QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok))
	{
	case QMessageBox::Ok:{
		label->setText("Question button/Ok");
		/* code */
		break;
	}
	case QMessageBox::Cancel: {
		label->setText("Question button/Cancel");
		break;
	}
	default:
		break;
	}
     return;
}

void MessageBoxw::Information()
{
	QMessageBox::information(this, "提示消息框", "这是一个提示消息框。");
     return;
}

void MessageBoxw::Warning()
{
	switch (QMessageBox::warning(this, "警告消息框", "保存文档吗？",
			QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save))
	{
	case QMessageBox::Save:
		label->setText("Warning button /Save");
		break;
	case QMessageBox::Discard:
		label->setText("Warning button /Discard");
		break;
	case QMessageBox::Cancel:
		label->setText("Warning button /Cancel");
		break;
	default:
		break;
	}
     return;
}

void MessageBoxw::Critical()
{
	QMessageBox::critical(this, "严重错误消息框", "告诉用户出现了错误。");
	label->setText("Critical MessageBox");
     return;
}

void MessageBoxw::About()
{
	QMessageBox::about(this, "关于消息框", "关于消息框实例。");
	label->setText("关于消息框");
     return;
}

void MessageBoxw::AboutQt()
{
	QMessageBox::aboutQt(this, "关于Qt消息框");
	label->setText("关于Qt消息框");
     return;
}

void MessageBoxw::Custom()
{
	QMessageBox customMsgBox;
	customMsgBox.setWindowTitle("自定义消息框");
	QPushButton *lockButton = customMsgBox.addButton(tr("Lock"), QMessageBox::ActionRole);
	QPushButton *unlockButton = customMsgBox.addButton(tr("Unlock"), QMessageBox::ActionRole);
	QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);
	// customMsgBox.setIconPixmap(QPixmap("./images/linuxredhat.png"));
	customMsgBox.setText("这是一个自定义消息框。");
	customMsgBox.exec();

	if (customMsgBox.clickedButton() == lockButton) {
		label->setText("Custom MessageBox/Lock");
	}
	if (customMsgBox.clickedButton() == unlockButton) {
		label->setText("Custom MessageBox/Unlock");
	}
	if (customMsgBox.clickedButton() == cancelButton) {
		label->setText("Custom MessageBox/Cancel");
	}

     return;
}
