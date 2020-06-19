#include "mainwindow.h"
#include "StartWindow.h"
#include "Window.h"
#include <QApplication>
#include "algorithmmethodbrunchandbound.h"

unsigned short int size;
std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow *sWindow = new StartWindow();
    sWindow->show();
    QObject::connect(sWindow, SIGNAL(hide()), sWindow, SLOT(hide()));
    //QObject::connect(sWindow, SIGNAL(hide()), window, SLOT(window->show()));

    //Window::setTable(sWindow->line->text().toUInt(), window);
    //runProgram();

    return a.exec();
}
