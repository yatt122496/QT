#include "source/inc/tabwidget.h"
#include <QLabel>
#include <QCheckBox>
#include <QTabWidget>
#include <QtWidgets/QMenuBar>
#include <QToolBar>
#include <QGridLayout>
#include <QGroupBox>
#include <QFileDialog>

TabWidget::TabWidget()
{
	QToolBar *openBar = addToolBar("打开");
	QAction *attribute = new QAction(QIcon(":Resource/images/open.png"), "文件属性", this);
	connect(attribute, SIGNAL(triggered()), this, SLOT(getAttribute()));
	openBar->addAction(attribute);

	pathLabel = new QLabel("路径");
	pathValueLabel = new QLabel();
	pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	sizeLabel = new QLabel("大小");
	sizeValueLabel = new QLabel();
	sizeValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	lastReadLabel = new QLabel("最后读取时间");
	lastReadValueLabel = new QLabel();
	lastReadValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	lastModLabel = new QLabel("最后修改时间");
	lastModValueLabel = new QLabel();
	lastModValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	QVBoxLayout *generalLayout = new QVBoxLayout;
	generalLayout->addWidget(pathLabel);
	generalLayout->addWidget(pathValueLabel);
	generalLayout->addWidget(sizeLabel);
	generalLayout->addWidget(sizeValueLabel);
	generalLayout->addWidget(lastReadLabel);
	generalLayout->addWidget(lastReadValueLabel);
	generalLayout->addWidget(lastModLabel);
	generalLayout->addWidget(lastModValueLabel);
	generalLayout->addStretch(1);

	QWidget *generalTab = new QWidget;
	generalTab->setLayout(generalLayout);

	QGroupBox *permissionsGroup = new QGroupBox("权限");
	readable = new QCheckBox("读");
	writable = new QCheckBox("写");
	executable = new QCheckBox("执行");

	QGroupBox *ownerGroup = new QGroupBox("文件所属");
	ownerLabel = new QLabel("所有者");
	ownerValueLabel = new QLabel();
	ownerValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	groupLabel = new QLabel("组");
	groupValueLabel = new QLabel();
	groupValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	QVBoxLayout *permissionsGroupLayout = new QVBoxLayout;
	permissionsGroupLayout->addWidget(readable);
	permissionsGroupLayout->addWidget(writable);
	permissionsGroupLayout->addWidget(executable);
	permissionsGroup->setLayout(permissionsGroupLayout);

	QVBoxLayout *ownerLayout = new QVBoxLayout;
	ownerLayout->addWidget(ownerLabel);
	ownerLayout->addWidget(ownerValueLabel);
	ownerLayout->addWidget(groupLabel);
	ownerLayout->addWidget(groupValueLabel);
	ownerGroup->setLayout(ownerLayout);

	QVBoxLayout *permissionsLayout = new QVBoxLayout;
	permissionsLayout->addWidget(permissionsGroup);
	permissionsLayout->addWidget(ownerGroup);
	permissionsLayout->addStretch(1);

	QWidget *permissionsTab = new QWidget();
	permissionsTab->setLayout(permissionsLayout);

	tabWidget = new QTabWidget;
	tabWidget->addTab(generalTab, "常规");
	tabWidget->addTab(permissionsTab, "权限");
	tabWidget->setTabPosition(QTabWidget::South);

	setCentralWidget(tabWidget);
	setWindowTitle(tr("Tab Widget"));
}

void TabWidget::getAttribute()
{
	path = QFileDialog::getOpenFileName(this, "Open File", ".", "C++ Files(*.cpp)");
	QFileInfo fileInfo(path);
	getGeneralAttribute(path);
	getPermissionsAttribute(path);
}

void TabWidget::getGeneralAttribute(const QFileInfo &fileInfo)
{
	pathValueLabel->setText(fileInfo.absoluteFilePath());
	qlonglong size = fileInfo.size();
	sizeValueLabel->setText(tr("%1 Byte").arg(size));
	lastReadValueLabel->setText(fileInfo.lastRead().toString());
	lastModValueLabel->setText(fileInfo.lastModified().toString());
}

void TabWidget::getPermissionsAttribute(const QFileInfo &fileInfo)
{
	if (fileInfo.isReadable())
		readable->setChecked(true);

	if (fileInfo.isWritable())
		writable->setChecked(true);

	if (fileInfo.isExecutable())
		executable->setChecked(true);

	ownerValueLabel->setText(fileInfo.owner());
	groupValueLabel->setText(fileInfo.group());
}
