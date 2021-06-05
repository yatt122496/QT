#ifndef TICKER_H
#define TICKER_H

#include <QWidget>
#include <QEvent>

class Ticker : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText)

public:
	Ticker(QWidget *parent = 0);
	void setText(const QString &newText);
	QString text() const { return myText; }
	QSize sizeHint() const;

protected:
	void paintEvent(QPaintEvent *);
	void timerEvent(QTimerEvent *);
	void showEvent(QShowEvent *);
	void hideEvent(QHideEvent *);

private:
	QString myText;
	int offset;
	int myTimerId;
};

#endif
