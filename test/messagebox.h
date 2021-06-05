#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

class QLabel;
class QComboBox;
class QTextEdit;
class MessageBoxw:public QDialog
{
    Q_OBJECT
public:
    MessageBoxw(QWidget *parent=0);
    void Question();
    void Information();
    void Warning();
    void Critical();
    void About();
    void AboutQt();
    void Custom();

public slots:
    void slotMessageBox(int index);

private:
    QTextEdit *label;
    QComboBox *comboBoxMessage;
};
#endif // MESSAGEBOX_H
