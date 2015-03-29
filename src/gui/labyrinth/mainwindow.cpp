#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize((24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 64 + 32 ),(8 + 24 + 8 + (50*VELIKOST) + 8 + 24 + 8 + 16 + 22));

    for(int i = 0; i<VELIKOST; i++)
        for(int j=0; j<VELIKOST; j++)
        {
        // Create the button, make "this" the parent
           m_button[i][j] = new QPushButton("My Button", this);
           // set size and location of the button
           m_button[i][j]->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*j), 8 + 24 + 8 + (50*i)), QSize(48, 48)));
           m_button[i][j]->setMinimumHeight(i);
           m_button[i][j]->setMinimumWidth(j);

           // Connect button signal to appropriate slot
           connect(m_button[i][j], SIGNAL(released()), this, SLOT(handleButton()));

        }


    for(int i = 0; i < (VELIKOST / 2); i++)
    {
        h_button[i][0] = new QPushButton(">", this);
        h_button[i][0]->setGeometry(QRect(QPoint(24, 8 + 24 + 8 + (2*50*i) + 50), QSize(24, 48)));
        h_button[i][0]->setMinimumHeight(i);
        h_button[i][0]->setMinimumWidth(0);
        connect(h_button[i][0], SIGNAL(released()), this, SLOT(handleHShift()));

        h_button[i][1] = new QPushButton("<", this);
        h_button[i][1]->setGeometry(QRect(QPoint(24 + 24 + 24 + 50*VELIKOST + 24, 8 + 24 + 8 + (2*50*i) + 50), QSize(24, 48)));
        h_button[i][1]->setMinimumHeight(i);
        h_button[i][1]->setMinimumWidth(1);
        connect(h_button[i][1], SIGNAL(released()), this, SLOT(handleHShift()));

        v_button[i][0] = new QPushButton("\\/", this);
        v_button[i][0]->setGeometry(QRect(QPoint(24 + 24 + 24 + (2*50*i) + 50, 8), QSize(48, 24)));
        v_button[i][0]->setMinimumHeight(0);
        v_button[i][0]->setMinimumWidth(i);
        connect(v_button[i][0], SIGNAL(released()), this, SLOT(handleVShift()));

        v_button[i][1] = new QPushButton("/\\", this);
        v_button[i][1]->setGeometry(QRect(QPoint(24 + 24 + 24 + (2*50*i) + 50, 8 + 24 + 8 + 50*VELIKOST + 8), QSize(48, 24)));
        v_button[i][0]->setMinimumHeight(1);
        v_button[i][1]->setMinimumWidth(i);
        connect(v_button[i][1], SIGNAL(released()), this, SLOT(handleVShift()));
    }

    //this->label_2->setHeight(8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8);
    //nemuzu se dostat k labelu a nevim proc!
    //QLabel *label = this->findChild<QLabel *>("label");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    QPushButton *button = (QPushButton *)sender(); //do button si ulozim ten objekt, ktery zavolal slot

    // change the text
    m_button[button->minimumHeight()][button->minimumWidth()]->setText("Exp");
}

void MainWindow::handleHShift()
{

}

void MainWindow::handleVShift()
{

}
