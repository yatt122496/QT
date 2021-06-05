#include "source/inc/mainwindow.h"
#include "source/inc/builtindialog.h"
#include "source/inc/messagebox.h"
#include "source/inc/mydialog.h"

#include <QApplication>
#include <QTextCodec>

#define SWITCH_BuiltInDialog	0
#define SWITCH_MessageBoxw		0
#define SWITCH_MyDialog			0
#define SWITCH_MainWindow		1

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);

#if SWITCH_BuiltInDialog
	BuiltInDialog builtInDialog;
	builtInDialog.show();
#endif
#if SWITCH_MessageBoxw
	MessageBoxw messageBoxw;
	messageBoxw.show();
#endif
#if SWITCH_MyDialog
	MyDialog myDialog;
	myDialog.show();
#endif
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif

    return a.exec();
}
