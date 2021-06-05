#ifndef UPLISTVIEW_H
#define UPLISTVIEW_H

#include <QListView>
#include <QPushButton>
#include <QWidget>

class UplistView : public QListView
{
	Q_OBJECT
public:
	UplistView(QWidget *parent = 0);
	QListView *list;

private slots:
	void uponelevel(const QModelIndex &);

private:
	QPushButton *buttonUpOneLevel;
};
#endif
