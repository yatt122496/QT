#include "source/inc/mainwindow.h"
#include <QtGui>
#include <QGridLayout>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
		: QWidget(parent)
{
	paintArea = new PaintArea();

	labelShape = new QLabel("形状：");
	comboBoxShape = new QComboBox();
	comboBoxShape->addItem("Line", PaintArea::Line);
	comboBoxShape->addItem("Rectangle", PaintArea::Rectangle);
	comboBoxShape->addItem("RoundRect", PaintArea::RoundRect);
	comboBoxShape->addItem("Ellipse", PaintArea::Ellipse);
	comboBoxShape->addItem("Polygon", PaintArea::Polygon);
	comboBoxShape->addItem("Polyline", PaintArea::Polyline);
	comboBoxShape->addItem("Points", PaintArea::Points);
	comboBoxShape->addItem("Arc", PaintArea::Arc);
	comboBoxShape->addItem("Path", PaintArea::Path);
	comboBoxShape->addItem("Text", PaintArea::Text);
	comboBoxShape->addItem("Pixmap", PaintArea::Pixmap);
	connect(comboBoxShape, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));

	labelPenColor = new QLabel("画笔颜色：");
	framePenColor = new QFrame();
	framePenColor->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	framePenColor->setAutoFillBackground(true);
	framePenColor->setPalette(QPalette(Qt::blue));
	pushButtonPenColor = new QPushButton("更改");
	connect(pushButtonPenColor, SIGNAL(clicked()), this, SLOT(ShowPenColor()));

	labelPenWidth = new QLabel("画笔宽度：");
	spinBoxPenWidth = new QSpinBox();
	spinBoxPenWidth->setRange(0, 20);
	connect(spinBoxPenWidth, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));

	labelPenStyle = new QLabel("画笔风格：");
	comboBoxPenStyle = new QComboBox();
	comboBoxPenStyle->addItem("SolidLine", (int)Qt::SolidLine);
	comboBoxPenStyle->addItem("DashLine", (int)Qt::DashLine);
	comboBoxPenStyle->addItem("DotLine", (int)Qt::DotLine);
	comboBoxPenStyle->addItem("DashDotLine", (int)Qt::DashDotLine);
	comboBoxPenStyle->addItem("DashDotDotLine", (int)Qt::DashDotDotLine);
	comboBoxPenStyle->addItem("CustomDashLine", (int)Qt::CustomDashLine);
	connect(comboBoxPenStyle, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));

	labelPenCap = new QLabel("画笔顶帽：");
	comboBoxPenCap = new QComboBox();
	comboBoxPenCap->addItem("SquareCap", (int)Qt::SquareCap);
	comboBoxPenCap->addItem("FlatCap", (int)Qt::FlatCap);
	comboBoxPenCap->addItem("RoundCap", (int)Qt::RoundCap);
	connect(comboBoxPenCap, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));

	labelPenJoin = new QLabel("画笔连接点：");
	comboBoxPenJoin = new QComboBox();
	comboBoxPenJoin->addItem("BevelJoin", (int)Qt::BevelJoin);
	comboBoxPenJoin->addItem("MiterJoin", (int)Qt::MiterJoin);
	comboBoxPenJoin->addItem("RoundJoin", (int)Qt::RoundJoin);
	connect(comboBoxPenJoin, SIGNAL(activated(int)), this, SLOT(ShowPenJoin(int)));

	labelFill = new QLabel("填充模式：");
	comboBoxFill = new QComboBox();
	comboBoxFill->addItem("OddEvenFill", (int)Qt::OddEvenFill);
	comboBoxFill->addItem("WindingFill", (int)Qt::WindingFill);
	connect(comboBoxFill, SIGNAL(activated(int)), this, SLOT(ShowFill()));

	labelBrushColor = new QLabel("画刷颜色：");
	frameBrushColor = new QFrame();
	frameBrushColor->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	frameBrushColor->setAutoFillBackground(true);
	frameBrushColor->setPalette(QPalette(Qt::green));
	pushButtonBrushColor = new QPushButton("更改");
	connect(pushButtonBrushColor, SIGNAL(clicked()), this, SLOT(ShowBrushColor()));

	labelBrushStyle = new QLabel("画刷风格：");
	comboBoxBrushStyle = new QComboBox();
	comboBoxBrushStyle->addItem("SolidPattern", (int)Qt::SolidPattern);
	comboBoxBrushStyle->addItem("Dense1Pattern", (int)Qt::Dense1Pattern);
	comboBoxBrushStyle->addItem("Dense2Pattern", (int)Qt::Dense2Pattern);
	comboBoxBrushStyle->addItem("Dense3Pattern", (int)Qt::Dense3Pattern);
	comboBoxBrushStyle->addItem("Dense4Pattern", (int)Qt::Dense4Pattern);
	comboBoxBrushStyle->addItem("Dense5Pattern", (int)Qt::Dense5Pattern);
	comboBoxBrushStyle->addItem("Dense6Pattern", (int)Qt::Dense6Pattern);
	comboBoxBrushStyle->addItem("Dense7Pattern", (int)Qt::Dense7Pattern);
	comboBoxBrushStyle->addItem("HorPattern", (int)Qt::HorPattern);
	comboBoxBrushStyle->addItem("VerPattern", (int)Qt::VerPattern);
	comboBoxBrushStyle->addItem("CrossPattern", (int)Qt::CrossPattern);
	comboBoxBrushStyle->addItem("BDiagPattern", (int)Qt::BDiagPattern);
	comboBoxBrushStyle->addItem("FDiagPattern", (int)Qt::FDiagPattern);
	comboBoxBrushStyle->addItem("DiagCrossPattern", (int)Qt::DiagCrossPattern);
	comboBoxBrushStyle->addItem("LinearGradientPattern", (int)Qt::LinearGradientPattern);
	comboBoxBrushStyle->addItem("ConicalGradientPattern", (int)Qt::ConicalGradientPattern);
	comboBoxBrushStyle->addItem("RadialGradientPattern", (int)Qt::RadialGradientPattern);
	comboBoxBrushStyle->addItem("TexturePattern", (int)Qt::TexturePattern);
	connect(comboBoxBrushStyle, SIGNAL(activated(int)), this, SLOT(ShowBrush(int)));

	pushButtonSaveImage = new QPushButton("Save Image");
	connect(pushButtonSaveImage, SIGNAL(clicked()), paintArea, SLOT(saveImage()));

	pushButtonTranslate = new QPushButton("平移变换");
	connect(pushButtonTranslate, SIGNAL(clicked()), paintArea, SLOT(translateImage()));
	pushButtonScale = new QPushButton("比例变换");
	connect(pushButtonScale, SIGNAL(clicked()), paintArea, SLOT(scaleImage()));
	pushButtonShear = new QPushButton("扭曲变换");
	connect(pushButtonShear, SIGNAL(clicked()), paintArea, SLOT(shearImage()));
	pushButtonRotate = new QPushButton("旋转变换");
	connect(pushButtonRotate, SIGNAL(clicked()), paintArea, SLOT(rotateImage()));

	layoutSetting = new QGridLayout();
	layoutSetting->addWidget(labelShape, 0, 0);
	layoutSetting->addWidget(comboBoxShape, 0, 1);
	layoutSetting->addWidget(labelPenColor, 0, 2);
	layoutSetting->addWidget(framePenColor, 0, 3);
	layoutSetting->addWidget(pushButtonPenColor, 0, 4);
	layoutSetting->addWidget(labelPenWidth, 1, 0);
	layoutSetting->addWidget(spinBoxPenWidth, 1, 1);
	layoutSetting->addWidget(labelPenStyle, 1, 2);
	layoutSetting->addWidget(comboBoxPenStyle, 1, 3);
	layoutSetting->addWidget(labelPenCap, 2, 0);
	layoutSetting->addWidget(comboBoxPenCap, 2, 1);
	layoutSetting->addWidget(labelPenJoin, 2, 2);
	layoutSetting->addWidget(comboBoxPenJoin, 2, 3);
	layoutSetting->addWidget(labelFill, 3, 0);
	layoutSetting->addWidget(comboBoxFill, 3, 1);
	layoutSetting->addWidget(labelBrushColor, 3, 2);
	layoutSetting->addWidget(frameBrushColor, 3, 3);
	layoutSetting->addWidget(pushButtonBrushColor, 3, 4);
	layoutSetting->addWidget(labelBrushStyle, 4, 0);
	layoutSetting->addWidget(comboBoxBrushStyle, 4, 1);
	layoutSetting->addWidget(pushButtonSaveImage, 4, 4);
	layoutSetting->addWidget(pushButtonTranslate, 0, 5);
	layoutSetting->addWidget(pushButtonScale, 1, 5);
	layoutSetting->addWidget(pushButtonShear, 2, 5);
	layoutSetting->addWidget(pushButtonRotate, 3, 5);

	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->addLayout(layoutSetting);
	layoutMain->addWidget(paintArea);
	setLayout(layoutMain);

	ShowShape(comboBoxShape->currentIndex());

	spinBoxPenWidth->setValue(14);
	ShowPenWidth(14);
	setMaximumSize(800, 480);
}

void MainWindow::ShowShape(int value)
{
	PaintArea::Shape shape = PaintArea::Shape(comboBoxShape->itemData(value, Qt::UserRole).toInt());
	paintArea->setShape(shape);
}

void MainWindow::ShowPenColor()
{
	QColor color = QColorDialog::getColor(Qt::blue);
	if (!color.isValid())
		return;
	framePenColor->setPalette(QPalette(color));
	int value = spinBoxPenWidth->value();

	Qt::PenStyle style = Qt::PenStyle(comboBoxPenStyle->currentData().toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(comboBoxPenCap->currentData().toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(comboBoxPenJoin->currentData().toInt());

	paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWindow::ShowPenWidth(int value)
{
	QColor color = framePenColor->palette().color(QPalette::Window);

	Qt::PenStyle style = Qt::PenStyle(comboBoxPenStyle->currentData().toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(comboBoxPenCap->currentData().toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(comboBoxPenJoin->currentData().toInt());

	paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWindow::ShowPenStyle(int styleValue)
{
	QColor color = framePenColor->palette().color(QPalette::Window);

	int value = spinBoxPenWidth->value();

	Qt::PenStyle style = Qt::PenStyle(comboBoxPenStyle->itemData(styleValue).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(comboBoxPenCap->currentData().toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(comboBoxPenJoin->currentData().toInt());

	paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWindow::ShowPenCap(int capValue)
{
	QColor color = framePenColor->palette().color(QPalette::Window);

	int value = spinBoxPenWidth->value();

	Qt::PenStyle style = Qt::PenStyle(comboBoxPenStyle->currentData().toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(comboBoxPenCap->itemData(capValue).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(comboBoxPenJoin->currentData().toInt());

	paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWindow::ShowPenJoin(int joinValue)
{
	QColor color = framePenColor->palette().color(QPalette::Window);

	int value = spinBoxPenWidth->value();

	Qt::PenStyle style = Qt::PenStyle(comboBoxPenStyle->currentData().toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(comboBoxPenCap->currentData().toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(comboBoxPenJoin->itemData(joinValue).toInt());

	paintArea->setPen(QPen(color, value, style, cap, join));
}

void MainWindow::ShowFill()
{
	Qt::FillRule fill = Qt::FillRule(comboBoxFill->currentData().toInt());
	paintArea->setFillRule(fill);
}

void MainWindow::ShowBrushColor()
{
	QColor color = QColorDialog::getColor(Qt::blue);
	if (!color.isValid())
		return;
	frameBrushColor->setPalette(QPalette(color));
	ShowBrush(comboBoxBrushStyle->currentIndex());
}

void MainWindow::ShowBrush(int value)
{
	QColor color = frameBrushColor->palette().color(QPalette::Window);
	Qt::BrushStyle style = Qt::BrushStyle(comboBoxBrushStyle->itemData(value).toInt());

	if (style == Qt::LinearGradientPattern) {
		QLinearGradient linearGradient(0, 0, 400, 400);
		linearGradient.setColorAt(0.0, Qt::white);
		linearGradient.setColorAt(0.2, color);
		linearGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(linearGradient);
	} else if (style == Qt::RadialGradientPattern) {
		QRadialGradient radialGradient(200, 200, 150, 150, 100);
		radialGradient.setColorAt(0.0, Qt::white);
		radialGradient.setColorAt(0.2, color);
		radialGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(radialGradient);
	} else if (style == Qt::ConicalGradientPattern) {
		QConicalGradient conicalGradient(200, 200, 30);
		conicalGradient.setColorAt(0.0, Qt::white);
		conicalGradient.setColorAt(0.2, color);
		conicalGradient.setColorAt(1.0, Qt::black);
		paintArea->setBrush(conicalGradient);
	} else if (style == Qt::TexturePattern) {
		paintArea->setBrush(QBrush(QPixmap(":Resource/images/logo.png")));
	} else {
		paintArea->setBrush(QBrush(color, style));
	}
}
