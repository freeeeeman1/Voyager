#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHeaderView"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(12);
    ui->tableWidget->setColumnCount(12);
    ui->tableWidget->resizeColumnsToContents();
    // for (int i = 0; )


}

MainWindow::~MainWindow()
{
    delete ui;
}

