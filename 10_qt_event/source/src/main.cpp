#include "source/inc/mouseevent.h"
#include "source/inc/keyevent.h"
#include "source/inc/eventfilter.h"
#include "source/inc/ticker.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>

#define SWITCH_MouseEvent			0
#define SWITCH_KeyEvent				0
#define SWITCH_EventFilter			0
#define SWITCH_Ticker				1

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	// QFont font("ZYSong18030", 12);
    QApplication a(argc, argv);

	// a.setFont(font);
#if SWITCH_MouseEvent
	MouseEvent mouseEvent;
	mouseEvent.show();
#endif
#if SWITCH_KeyEvent
	KeyEvent keyEvent;
	keyEvent.show();
#endif
#if SWITCH_EventFilter
	EventFilter eventFilter;
	eventFilter.show();
#endif
#if SWITCH_Ticker
	Ticker ticker;
	ticker.show();
#endif

    return a.exec();
}
