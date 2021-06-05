#include "source/inc/mainwindow.h"
#include "source/inc/image.h"
#include "source/inc/painter.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>

#define SWITCH_MainWindow			0
#define SWITCH_ImageWidget			0
#define SWITCH_Painter				1
#define SWITCH_Ticker				0

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif
#if SWITCH_ImageWidget
	ImageWidget imageWidget;
	imageWidget.show();
#endif
#if SWITCH_Painter
	Painter painter;
	painter.show();
#endif
#if SWITCH_Ticker
	Ticker ticker;
	ticker.show();
#endif

    return a.exec();
}
