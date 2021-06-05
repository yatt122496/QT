#include "source/inc/mainwindow.h"
#include "source/inc/tabwidget.h"
#include "source/inc/analogclock.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>

#define SWITCH_TabWidget 0
#define SWITCH_AnalogClock 0
#define SWITCH_MainWindow 1

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_TabWidget
	TabWidget tabWidget;
	tabWidget.show();
#endif
#if SWITCH_AnalogClock
	AnalogClock analogClock;
	analogClock.show();
#endif
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif

    return a.exec();
}
