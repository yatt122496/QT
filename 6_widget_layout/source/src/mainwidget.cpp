#include "source/inc/mainwidget.h"
#include <QtGui>
#include <QGridLayout>

MainWidget::MainWidget(QWidget *parent)
			:QWidget(parent)
{
	stack = new QStackedWidget();
	stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
	baseInfo = new BaseInfo();
	moreInfo = new MoreInfo();
	stack->addWidget(baseInfo);
	stack->addWidget(moreInfo);

	pushButtonOk = new QPushButton("确定");
	pushButtonCancel = new QPushButton("取消");
	pushButtonApply = new QPushButton("应用");

	QHBoxLayout *layoutBtn = new QHBoxLayout();

	layoutBtn->addStretch();
	layoutBtn->addWidget(pushButtonOk);
	layoutBtn->addWidget(pushButtonCancel);
	layoutBtn->addWidget(pushButtonApply);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(stack);
	mainLayout->addLayout(layoutBtn);

	connect(pushButtonCancel, SIGNAL(clicked()), qApp, SLOT(quit()));
}
