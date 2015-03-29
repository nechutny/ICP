#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#define VELIKOST 11

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void handleButton();
    void handleHShift();
    void handleVShift();
    void handleRotateR();
    void handleRotateL();
    void askIP();

public:
    QPushButton *m_button[VELIKOST][VELIKOST];
    QPushButton *h_button[VELIKOST/2][1];
    QPushButton *v_button[VELIKOST/2][1];

    void changeIcon(QPushButton *button,const char* path);
    void createField();
};

#endif // MAINWINDOW_H
