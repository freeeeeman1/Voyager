#include "StartWindow.h"
#include "Window.h"
#include "Delegate.h"
#include <QRegExpValidator>
#include <QHeaderView>

StartWindow::StartWindow(QWidget *parent) : QDialog(parent)
{
    line = new QLineEdit;
    label = new QLabel("Введите количество городов <= 15");
    QWidget* window = new QWidget;
    layoutH = new QHBoxLayout;
    layoutV = new QVBoxLayout;
    okButton = new QPushButton("OK");

    window->setMinimumHeight(600);
    window->setMinimumWidth(720);

    okButton->setDefault(true);
    okButton->setEnabled(false);

    line->setValidator(new QRegExpValidator(QRegExp("[1-9]|[1][0-5]"), line));

    layoutH->addWidget(line);
    layoutH->addWidget(okButton);

    layoutV->addWidget(label);
    layoutV->addLayout(layoutH);

    connect(line, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));

    setLayout(layoutV);
    setWindowTitle("Коммивояжер");
}

void StartWindow::TextChanged(QString str) {
    okButton->setEnabled(!str.isEmpty());
}

int getSize(StartWindow *window) {
    return window->line->text().toUInt();
}

void StartWindow::okClicked() {
    Window *window = new Window;
    window->resize(1250,528);
    unsigned size = line->text().toUInt();
    emit hide();
    window->table->setRowCount(size);
    window->table->setColumnCount(size);
    QTableWidgetItem *item = new QTableWidgetItem('-');
    window->table->setItemDelegate(new Delegate);
    int w = window->table->verticalHeader()->width() + 4;
    int h = window->table->horizontalHeader()->height() + 4;
    for (int i = 0; i < window->table->columnCount(); i++) {
        w += window->table->columnWidth(i);
    }
    for (int i = 0; i < window->table->verticalHeader()->width(); i++) {
        h += window->table->rowHeight(i);
    }
    window->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    window->table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0, j = 0; i < window->table->columnCount(); i++, j++) {
            window->table->setItem(i, j, new QTableWidgetItem(QString("Inf")));
    }
    window->table->resize(w, h);
    window->show();
}
