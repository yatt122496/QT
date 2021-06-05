#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QtGui>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QToolButton>
#include <QDockWidget>

class Dock : public QDialog
{
	Q_OBJECT
public:
	Dock();
	QLabel *styleLabel;
	QComboBox *styleComboBox;
	QLabel *widthLabel;
	QSpinBox *widthSpinBox;
	QLabel *colorLabel;
	QToolButton *colorBtn;
	QToolButton *clearBtn;
	QDockWidget *dock;
};
#endif
