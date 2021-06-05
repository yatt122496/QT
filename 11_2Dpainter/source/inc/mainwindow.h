#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include "source/inc/paintarea.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);

private:
	PaintArea *paintArea;

	QLabel *labelShape;
	QComboBox *comboBoxShape;

	QLabel *labelPenColor;
	QFrame *framePenColor;
	QPushButton *pushButtonPenColor;

	QLabel *labelPenWidth;
	QSpinBox *spinBoxPenWidth;

	QLabel *labelPenStyle;
	QComboBox *comboBoxPenStyle;

	QLabel *labelPenCap;
	QComboBox * comboBoxPenCap;

	QLabel *labelPenJoin;
	QComboBox *comboBoxPenJoin;

	QLabel *labelFill;
	QComboBox *comboBoxFill;

	QLabel *labelBrushColor;
	QFrame *frameBrushColor;
	QPushButton *pushButtonBrushColor;

	QLabel *labelBrushStyle;
	QComboBox *comboBoxBrushStyle;

	QPushButton *pushButtonSaveImage;
	QPushButton *pushButtonTranslate;
	QPushButton *pushButtonScale;
	QPushButton *pushButtonShear;
	QPushButton *pushButtonRotate;

	QGridLayout *layoutSetting;

protected slots:
	void ShowShape(int);
	void ShowPenColor();
	void ShowPenWidth(int);
	void ShowPenStyle(int);
	void ShowPenCap(int);
	void ShowPenJoin(int);
	void ShowFill();
	void ShowBrushColor();
	void ShowBrush(int);
};
#endif
