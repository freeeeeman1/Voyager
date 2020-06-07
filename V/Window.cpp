#include "Window.h"
#include "algorithm"
#include <iostream>
#include <limits>
#include <tuple>
#include <set>
#include <vector>

Window::Window(QWidget *parent) : QDialog(parent) {

    table = new QTableWidget;
    ok = new QPushButton("Запуск Алгоритма");
    layoutH = new QHBoxLayout;
    layoutV = new QVBoxLayout;
    text = new QTextBrowser;



    layoutH->addWidget(table);
    layoutH->addWidget(text);

    layoutV->addLayout(layoutH);
    layoutV->addWidget(ok);

    connect(ok, SIGNAL(clicked()), this, SLOT(okClicked()));

    setLayout(layoutV);
    setWindowTitle("Коммиовяжер");
}

static void setTable(unsigned size, Window *window) {
    window->table->setRowCount(size);
    window->table->setColumnCount(size);
}

void Window::okClicked() {
    Alghoritm::main();
}


