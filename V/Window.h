#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QToolBar>
#include <QMessageBox>

class Window : public QDialog{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    QTableWidget* table;
    QPushButton* ok;
    QPushButton* info;
    QHBoxLayout* layoutH;
    QVBoxLayout* layoutV;
    QTextBrowser* text;
    QToolBar* bar;
    int** array;
    static void setTable(unsigned size, Window *window);

private slots:
    void okClicked();
    void infoClicked();
};

#endif // WINDOW_H
