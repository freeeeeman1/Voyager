#include "mainwindow.h"
#include "StartWindow.h"
#include "Window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow *sWindow = new StartWindow();
    Window *window = new Window();
    sWindow->show();
    QObject::connect(sWindow, SIGNAL(hide()), sWindow, SLOT(hide()));
    //QObject::connect(sWindow, SIGNAL(hide()), window, SLOT(window->show()));

    //Window::setTable(sWindow->line->text().toUInt(), window);


    return a.exec();
}
