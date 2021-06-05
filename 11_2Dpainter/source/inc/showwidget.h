#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>

class ShowWidget : public QWidget
{
	Q_OBJECT
public:
	ShowWidget(QWidget *parent = 0);
	QImage image;
	QLabel *labelImage;
};
#endif
