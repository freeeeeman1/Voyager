#include "Window.h"
#include <iostream>
#include <limits>
#include <tuple>
#include <set>
#include <vector>
#include <QMessageBox>
#include "algorithmmethodbrunchandbound.h"

extern int size;
extern std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix;


Window::Window(QWidget *parent) : QDialog(parent) {

    table = new QTableWidget;
    ok = new QPushButton("Запуск Алгоритма");
    layoutH = new QHBoxLayout;
    layoutV = new QVBoxLayout;
    text = new QTextBrowser;
    info = new QPushButton("Info");
    QHBoxLayout* layoutH1 = new QHBoxLayout;

    layoutH->addWidget(table);
    layoutH->addWidget(text);

    layoutH1->addWidget(ok);
    layoutH1->addWidget(info);

    layoutV->addLayout(layoutH);
    layoutV->addLayout(layoutH1);

    connect(ok, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(info, SIGNAL(clicked()), this, SLOT(infoClicked()));
    setLayout(layoutV);
    setWindowTitle("Коммиовяжер");
}

void Window::okClicked() {
    matrix = new std::pair<std::pair<unsigned short,  unsigned short>, unsigned>*[this->table->columnCount()];
    for (int i = 0; i < this->table->columnCount(); i++)
        matrix[i] = new std::pair<std::pair<unsigned short,  unsigned short>, unsigned>[this->table->rowCount()];

    for (int i = 0; i < this->table->columnCount(); i++) {
        for (int j = 0; j < this->table->rowCount(); j++) {
            QTableWidgetItem *item = this->table->item(i, j);
            if (item != NULL) {
                matrix[i][j].second = item->text().toUInt();
                matrix[i][j].first.first = i;
                matrix[i][j].first.second = j;
            }
        }
    }
    runProgram(matrix, this->table->columnCount(), text);
}

void Window::infoClicked() {
    QMessageBox::information(this, "Разработчики проекта", "Проект разрабатывали студенты из группы ПИН-24\nКалина Виталий\nСмольяков Вадим\nОдинцов Егор");
}

