#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include <QWidget>
#include <QKeyEvent>

class KeyEvent : public QWidget
{
	Q_OBJECT
public:
	KeyEvent(QWidget *parent = 0);

protected:
	void drawPix();
	void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);

private:
	QPixmap *pix;
	QImage image;
	int startX;
	int startY;
	int width;
	int height;
	int step;
};

#endif
