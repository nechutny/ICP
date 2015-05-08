#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "player.h"
#include "map.h"
#include "block.h"
#include <QLabel>

#define VELIKOST 5

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeBlock(QPushButton *button,Block* kamen);
    void changeIcon(QPushButton *button,const char* path);

private:
    Ui::MainWindow *ui;
    Map* mapa;
    Player* hraci[4];
    int hrac;
    bool posunuto;

private slots:
    void handleButton();
    void handleHShift();
    void handleVShift();
    void handleRotateR();
    void handleRotateL();
    void createField();
    void prekresli();

public:
    QPushButton *m_button[VELIKOST][VELIKOST];
    QPushButton *h_button[VELIKOST/2][1];
    QPushButton *v_button[VELIKOST/2][1];

};

#endif // MAINWINDOW_H
