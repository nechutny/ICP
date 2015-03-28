#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize((24 + 24 + 24 + (64*VELIKOST) + 24 + 24 + 32 + 64 + 32 ),(8 + 24 + 8 + (64*VELIKOST) + 8 + 24 + 8 + 16));

    for(int i = 0; i<VELIKOST; i++)
        for(int j=0; j<VELIKOST; j++)
        {
        // Create the button, make "this" the parent
           m_button[i][j] = new QPushButton("My Button", this);
           // set size and location of the button
           m_button[i][j]->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*j), 24 + 24 + 24 + (50*i)),
                                        QSize(48, 48)));
           m_button[i][j]->setMinimumHeight(i);
           m_button[i][j]->setMinimumWidth(j);

           // Connect button signal to appropriate slot
           connect(m_button[i][j], SIGNAL(released()), this, SLOT(handleButton()));

        }
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
