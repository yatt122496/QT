#include "source/inc/mdichild.h"
#include "source/inc/mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>

#define SWITCH_MdiChild				0
#define SWITCH_MainWindow			1
#define SWITCH_Painter				0
#define SWITCH_Ticker				0

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication app(argc, argv);

	// a.setFont(font);
#if SWITCH_MdiChild
	MdiChild mdiChild;
	mdiChild.show();
#endif
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif
#if SWITCH_Painter
	Painter painter;
	painter.show();
#endif
#if SWITCH_Ticker
	Ticker ticker;
	ticker.show();
#endif

    return app.exec();
}
