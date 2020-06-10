#include "mainwindow.h"
#include "StartWindow.h"
#include "Window.h"
#include <QApplication>
#include "algorithmmethodbrunchandbound.h"

std::pair<std::pair<unsigned short, unsigned short>, unsigned int>** matrix;
unsigned short smatrix;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow *sWindow = new StartWindow();
    sWindow->show();
    QObject::connect(sWindow, SIGNAL(hide()), sWindow, SLOT(hide()));

    return a.exec();
}
