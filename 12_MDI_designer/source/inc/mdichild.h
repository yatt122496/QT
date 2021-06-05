#ifndef MDICHILD_H
#define MDICHILD_H

// #include <QWidget>
// #include <QPainter>
// #include <QLabel>
// #include <QComboBox>
// #include <QSpinBox>
// #include <QPushButton>
// #include <QGridLayout>
#include <QTextEdit>

class MdiChild : public QTextEdit
{
	Q_OBJECT
public:
	MdiChild();
	void newFile();
	bool loadFile(const QString &);
	bool save();
	bool saveAs();
	bool saveFile(const QString &);
	QString curFile;

protected:
	void closeEvent(QCloseEvent *);

private slots:
	void documentWasModified();

private:
	bool maybeSave();
	void setCurrentFile();
	bool isUntitled;
};
#endif
