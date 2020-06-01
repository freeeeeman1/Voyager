#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::on_pushButton_clicked()
{

}
