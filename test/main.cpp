#include "mainwindow.h"
#include "mydialog.h"
#include "builtindialog.h"
#include "messagebox.h"
#include <QTextCodec>

#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
//    MainWindow w;
//    MyDialog w;
    // BuiltInDialog w;
    MessageBoxw w;
    w.show();
    return a.exec();
}
