#include "source/inc/mainwindow.h"
#include "source/inc/stringview.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>

#define SWITCH_MainWindow			1
#define SWITCH_StringView			0
#define SWITCH_Ticker				0

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication app(argc, argv);

	// a.setFont(font);
#if SWITCH_MainWindow
	MainWindow mainWindow;
	mainWindow.show();
#endif
#if SWITCH_StringView
	StringView stringView;
	stringView.show();
#endif
#if SWITCH_Ticker
	Ticker ticker;
	ticker.show();
#endif

    return app.exec();
}
