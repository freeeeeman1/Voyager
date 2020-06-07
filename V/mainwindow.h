#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTableWidget* table;
    QPushButton* ok;
    QHBoxLayout* layoutH;
    QVBoxLayout* layoutV;
    QTextBrowser* text;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
