#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include <QImage>
#include <QPushButton>

class ImageWidget : public QWidget
{
	Q_OBJECT
public:
	ImageWidget();
	QImage img;

protected:
	void paintEvent(QPaintEvent *);

private:
	QPushButton *pushButtonOpen;

public slots:
	void openImage();
};
#endif
