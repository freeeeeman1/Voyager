#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "Window.h"
#include <QPushButton>

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    StartWindow(QWidget* parent=nullptr);
    int getSize(StartWindow* sWindow);
    QLineEdit *line;
    QLabel *label;
    QPushButton *okButton;
    QHBoxLayout* layoutH;
    QVBoxLayout* layoutV;

private slots:
    void okClicked();
    void TextChanged(QString str);
signals:
    void setTable(unsigned size);
    void hide();
};

#endif // STARTWINDOW_H
