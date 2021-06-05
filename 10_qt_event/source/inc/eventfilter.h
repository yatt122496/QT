#ifndef EVENT_FILTER_H
#define EVENT_FILTER_H

#include <QDialog>
#include <QEvent>
#include <QLabel>
#include <QImage>

class EventFilter : public QDialog
{
	Q_OBJECT
public:
	EventFilter(QWidget *parent = 0, Qt::WindowFlags f = 0);

public slots:
	bool eventFilter(QObject *, QEvent *);

private:
	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	QLabel *labelState;

	QImage image1;
	QImage image2;
	QImage image3;
};

#endif
