#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>


class Window : public QDialog{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    QTableWidget* table;
    QPushButton* ok;
    QHBoxLayout* layoutH;
    QVBoxLayout* layoutV;
    QTextBrowser* text;
    static void setTable(unsigned size, Window *window);

};

#endif // WINDOW_H
