#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createField();



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

void MainWindow::handleRotateR()
{

}

void MainWindow::handleRotateL()
{

}

void MainWindow::askIP() //obslouzeni polozky hra - nova sitova
{

}

/**
 * Function for changing image on button
 * @param button button I want to change
 * @param path is path to image that will be on the button
 */
void MainWindow::changeIcon(QPushButton *button, const char* path)
{

    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setIconSize(pixmap.rect().size());
}

/**
 * Function for creating field - buttons for shift,
 * map buttons, score board and right panel with
 * symbol and free map piece with rotate buttons
 */
void MainWindow::createField()
{
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
           m_button[i][j]->setText("");

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

    ui->label->setGeometry(QRect(QPoint(35, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(51, 17)));
    ui->label_2->setGeometry(QRect(QPoint(125, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(51, 17)));
    ui->label_3->setGeometry(QRect(QPoint(205, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(58, 17)));
    ui->label_4->setGeometry(QRect(QPoint(305, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(51, 17)));

    ui->scoreGreen->setGeometry(QRect(QPoint(90, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(25, 17)));
    ui->scoreYellow->setGeometry(QRect(QPoint(170, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(25, 17)));
    ui->scoreRed->setGeometry(QRect(QPoint(270, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(25, 17)));
    ui->scoreBlue->setGeometry(QRect(QPoint(356, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(25, 17)));

    //ui->scoreBlue->setText(QVariant(24).toString()); //převádění intu na řetězec pro label
    ui->card->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32,20), QSize(64, 128)));
    ui->card->setPixmap( QPixmap( "resources/card.png" ));

    ui->rotateR->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20), QSize(48, 24)));
    connect(ui->rotateR, SIGNAL(released()), this, SLOT(handleRotateR()));
    changeIcon(ui->rotateR, "resources/rotateR.png");

    ui->rotateL->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20 + 24 + 4 + 48 + 4), QSize(48, 24)));
    connect(ui->rotateR, SIGNAL(released()), this, SLOT(handleRotateL()));
    changeIcon(ui->rotateL, "resources/rotateL.png");

    ui->square->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20 + 24 + 4), QSize(48, 48)));
    ui->square->setPixmap( QPixmap( "resources/square.png"));

    connect(ui->actionNov_s_ov, SIGNAL(triggered()), this, SLOT(askIP()));  //melo by fungovat jako obslouzeni polozky menu hra - nova sitova
}
