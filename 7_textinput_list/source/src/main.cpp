#include "source/inc/combobox.h"
#include "source/inc/text_edit.h"
#include "source/inc/tablewidget.h"
#include "source/inc/mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QSplitter>

#define SWITCH_ComboBox		0
#define SWITCH_Text_Input	0
#define SWITCH_TableWidget	0
#define SWITCH_MainWindow	1

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_ComboBox
	ComboBox comboBox;
	comboBox.show();
#endif
#if SWITCH_Text_Input
	Text_Input text_Input;
	text_Input.show();
#endif
#if SWITCH_TableWidget
	TableWidget tableWidget;
	tableWidget.show();
#endif
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif

    return a.exec();
}
