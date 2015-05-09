#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "player.h"
#include "map.h"
#include "block.h"
#include <QLabel>

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
    void changeBlock(QPushButton *button,Block* kamen);
    void changeIcon(QPushButton *button,const char* path);
    void changeCard();

private:
    Ui::MainWindow *ui;
    Map* mapa;
    Player* hraci[4];
    int hrac;
    int pocet_hracu;
    bool posunuto;

private slots:
    void handleButton();
    void handleHShift();
    void handleVShift();
    void handleRotateR();
    void handleRotateL();

    void prekresli();
    void spust();

public:
    QPushButton *m_button[VELIKOST][VELIKOST];
    QPushButton *h_button[VELIKOST/2][2];
    QPushButton *v_button[VELIKOST/2][2];

    void createField();

};

#endif // MAINWINDOW_H
