#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMenuBar>
#include <QGroupBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>

class Dialog : public QDialog
{
	Q_OBJECT
public:
	Dialog();
private:
	void createMenu();
	void createHorizontalGroupBox();
	void createGridGroupBox();
	enum { NumGridRows = 3, NumButtons = 4 };
	QMenuBar *menuBar;
	QGroupBox *horizontalGroupBox;
	QGroupBox *gridGroupBox;
	QTextEdit *smallEditor;
	QTextEdit *bigEditor;
	QLabel *labels[NumGridRows];
	QLineEdit *lineEdits[NumGridRows];
	QPushButton *buttons[NumButtons];
	QDialogButtonBox *buttonBox;
	QMenu *fileMenu;
	QAction *exitAction;
};
#endif
