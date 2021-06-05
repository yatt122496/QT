#include "source/inc/dialog.h"
#include "source/inc/stackdlg.h"
#include "source/inc/workspace.h"
#include "source/inc/mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QSplitter>

#define SWITCH_Dialog		0
#define SWITCH_StackDlg		0
#define SWITCH_WorkSpace	0
#define SWITCH_MainWindow	1

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_Dialog
	Dialog dialog;
	dialog.show();
#endif
#if SWITCH_StackDlg
	StackDlg stackDlg;
	stackDlg.show();
#endif
#if SWITCH_WorkSpace
	WorkSpace workSpace;
	workSpace.show();
#endif
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif

    return a.exec();
}
