#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHeaderView"
#include "dialog.h"
#include "QMessageBox"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //QLineEdit* intEdit = new QLineEdit;
    //int size = (new Dialog(this))->on_pushButton_clicked();
    //ui->tableWidget->setRowCount((new Dialog(this))->on_pushButton_clicked());
    //ui->tableWidget->setColumnCount((new Dialog(this))->on_pushButton_clicked());
    //ui->tableWidget->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    unsigned size = ui->lineEdit->text().toUInt();
    if (size <= 0 || size > 15) {
        QMessageBox::warning(this, "Ошибка", "Вы ввели некорректное число");
        exit(-1);
    } else {
        hide();
        sw = new SecondWindow(this);
        sw->show();
        QTableWidget* table = new QTableWidget(sw);
        table->setRowCount(size);
        table->setColumnCount(size);
        table->resizeColumnsToContents();
        int w = 0;
        int h = 0;
        for (int i = 0; i < table->columnCount(); i++) {
            w += table->columnWidth(i);
        }
        w += table->verticalHeader()->width() + 4;
        for (int i = 0; i < table->verticalHeader()->width(); i++) {
            h += table->rowHeight(i);
        }
        h += table->horizontalHeader()->height() + 4;
        table->resize(w, h);
        table->show();
        //table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        // table->horizontalHeader()->resizeSections(QHeaderView::Stretch);
        // table->resizeColumnsToContents();

    }
}
