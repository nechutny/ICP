#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i<5; i++)
        for(int j=0; j<5; j++)
        {
        // Create the button, make "this" the parent
           m_button[i][j] = new QPushButton("My Button", this);
           // set size and location of the button
           m_button[i][j]->setGeometry(QRect(QPoint((50*j)+20, (50*i)+20),
                                        QSize(48, 48)));

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
    button->setText("Example");
}
