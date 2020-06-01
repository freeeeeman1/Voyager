#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include <QAbstractButton>
#include <QPushButton>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    //Dialog dialog;
    //w.close();
    //dialog.show();
    return a.exec();
}
