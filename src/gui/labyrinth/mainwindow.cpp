#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "player.cpp"
#include "map.cpp"
#include "block.cpp"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	hraci[0] = NULL;
	hraci[1] = NULL;
	hraci[2] = NULL;
	hraci[3] = NULL;
	mapa = new Map;

    //mapa->generate(7, 12);


	hrac = 0;
	posunuto = false;
	createField();

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::handleButton()
{//button->minimumHeight(),button->minimumWidth()

	QPushButton *button = (QPushButton *)sender(); //do button si ulozim ten objekt, ktery zavolal slot
	if(hraci[hrac]->move(button->minimumHeight(),button->minimumWidth()))
	{
		prekresli();
		hrac = (hrac+1)%pocet_hracu; //potreba upravit pro neplny pocet hracu !!!!!!!!!!!!!!!
		posunuto = false;
	}
	else
	{
		printf("Hrac %d nemuze jet na %d %d\n",hrac,button->minimumHeight(),button->minimumWidth());
	}
}

void MainWindow::handleHShift()
{
	if(posunuto)
		return;

	QPushButton *button = (QPushButton *)sender();

	mapa->shift(button->minimumWidth(),((button->minimumHeight()) * 2)+1);
	posunuto = true;
	prekresli();
}

void MainWindow::handleVShift()
{
	if(posunuto)
		return;
	QPushButton *button = (QPushButton *)sender();

	mapa->shift(button->minimumWidth(),((button->minimumHeight()) * 2)+1);
	posunuto = true;
	prekresli();
}

void MainWindow::handleRotateR()
{
	//printf("%d\n",mapa->getFreeBlock()->getRotation());
	mapa->getFreeBlock()->rotateRight();
	prekresli();
	//printf("otoceni");
	//printf("%d\n\n",mapa->getFreeBlock()->getRotation());
}

void MainWindow::handleRotateL()
{
	mapa->getFreeBlock()->rotateLeft();
	prekresli();
}

void MainWindow::prekresli()
{
	// kameny[mapa->offset(i,j)]->getType();
	Block **kameny = mapa->getMap();
	for(int i = 0; i<mapa->getSize(); i++)
		for(int j=0; j<mapa->getSize(); j++)
		{
			this->changeBlock(m_button[i][j],kameny[mapa->offset(i,j)]);
		}
	this->changeBlock(ui->square,mapa->getFreeBlock());
	changeCard();

}

 void MainWindow::changeBlock(QPushButton *button,Block* kamen)
{
	int type = kamen->getType();
	QPixmap pixmap(type == 0 ? "resources/block-L.png" : type == 1 ? "resources/block-T.png" : "resources/block-I.png");
	char nazev[40] = "";

	if(kamen->getSymbol() != 0)
	{

		sprintf(nazev,"resources/symbol%d.png", kamen->getSymbol());
		QPixmap icon2(nazev);

		// paints a midget of icon2 onto icon1
		icon2 = icon2.scaled(QSize(28,28),Qt::KeepAspectRatio, Qt::SmoothTransformation);
		QPainter painter(&pixmap);
		painter.drawPixmap((pixmap.width()-icon2.width())/2,(pixmap.height()-icon2.height())/2,icon2);

	}

	if(kamen->isOccupied())
	{
		Player** players = kamen->getPlayers();
		for(int i = 0; i < 4; i++)
		{
			if(players[i] != NULL)
			{
				sprintf(nazev,"resources/player-%d.png", i+1);
				QPixmap icon2(nazev);

				// paints a midget of icon2 onto icon1
				icon2 = icon2.scaled(QSize(28,28),Qt::KeepAspectRatio, Qt::SmoothTransformation);
				QPainter painter(&pixmap);
				painter.drawPixmap((pixmap.width()-icon2.width())/2,(pixmap.height()-icon2.height())/2,icon2);
			}
		}
	}


	QTransform transform;
	QTransform trans = transform.rotate((kamen->getRotation()) * -90);
	QPixmap *transPixmap = new QPixmap(pixmap.transformed(trans));



	QIcon ButtonIcon(*transPixmap);
	button->setIcon(ButtonIcon);
	button->setIconSize(pixmap.rect().size());


}



 void MainWindow::changeCard()
{
	QPixmap transPixmap("resources/card.png");


	char nazev[40] = "";
	if(hraci[hrac] != NULL)
	{
		sprintf(nazev,"resources/symbol%d.png", hraci[hrac]->getSymbol());
		QPixmap icon2(nazev);

		// paints a midget of icon2 onto icon1
		icon2 = icon2.scaled(QSize(36,36),Qt::KeepAspectRatio, Qt::SmoothTransformation);
		QPainter painter(&transPixmap);
		painter.drawPixmap((transPixmap.width()-icon2.width())/2,(transPixmap.height()-icon2.height())/2,icon2);
	}

	QIcon ButtonIcon(transPixmap);
	ui->card->setIcon(ButtonIcon);
	ui->card->setIconSize(transPixmap.rect().size());


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

void MainWindow::spust()
{
	 mapa->generate(7, 12);

	pocet_hracu = 0;
	if(hraci[0] != NULL)
		delete hraci[0];

	if(hraci[1] != NULL)
		delete hraci[1];

	if(hraci[2] != NULL)
		delete hraci[2];

	if(hraci[3] != NULL)
		delete hraci[3];
	if (ui->checkBox->isChecked())
	{
		hraci[pocet_hracu] = new Player(COLOR_GREEN,mapa);
		pocet_hracu++;
	}

	if (ui->checkBox_2->isChecked())
	{
		hraci[pocet_hracu] = new Player(COLOR_YELLOW,mapa);
		pocet_hracu++;
	}
	if (ui->checkBox_3->isChecked())
	{
		hraci[pocet_hracu] = new Player(COLOR_RED,mapa);
		pocet_hracu++;
	}
	if (ui->checkBox_4->isChecked())
	{
		hraci[pocet_hracu] = new Player(COLOR_BLUE,mapa);
		pocet_hracu++;
	}

	if(pocet_hracu<2)
		ui->pushButton->setText("Málo hráčů");
	else
	{
		ui->checkBox->setVisible(false);
		ui->checkBox_2->setVisible(false);
		ui->checkBox_3->setVisible(false);
		ui->checkBox_4->setVisible(false);
		ui->label_5->setVisible(false);
		ui->label_6->setVisible(false);
		ui->spinBox->setVisible(false);
		ui->spinBox_2->setVisible(false);
		ui->pushButton->setVisible(false);
		prekresli();



        int i, j;

        for(i = 0; i < ui->spinBox->value(); i++)
            for(j = 0; j < ui->spinBox->value(); j++)
            {
                m_button[i][j]->setVisible(true);
            }



	}
}

/**
 * Function for creating field - buttons for shift,
 * map buttons, score board and right panel with
 * symbol and free map piece with rotate buttons
 */
void MainWindow::createField()
{
	int vyska = 8 + 24 + 8 + (50*VELIKOST) + 8 + 24 + 8 + 16 + 22;
	this->setFixedSize((24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 64 + 32 ),(vyska));

	for(int i = 0; i<VELIKOST; i++)
		for(int j=0; j<VELIKOST; j++)
		{
		// Create the button, make "this" the parent
		   m_button[i][j] = new QPushButton("My Button",this);
		   // set size and location of the button
		   m_button[i][j]->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*j), 8 + 24 + 8 + (50*i)), QSize(48, 48)));
		   m_button[i][j]->setMinimumHeight(i);
		   m_button[i][j]->setMinimumWidth(j);
		   m_button[i][j]->setText("");
           m_button[i][j]->setVisible(false);


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
        h_button[i][0]->setVisible(false);

		h_button[i][1] = new QPushButton("<", this);
		h_button[i][1]->setGeometry(QRect(QPoint(24 + 24 + 24 + 50*VELIKOST + 24, 8 + 24 + 8 + (2*50*i) + 50), QSize(24, 48)));
		h_button[i][1]->setMinimumHeight(i);
		h_button[i][1]->setMinimumWidth(2);
		connect(h_button[i][1], SIGNAL(released()), this, SLOT(handleHShift()));
        h_button[i][1]->setVisible(false);

		v_button[i][0] = new QPushButton("\\/", this);
		v_button[i][0]->setGeometry(QRect(QPoint(24 + 24 + 24 + (2*50*i) + 50, 8), QSize(48, 24)));
		v_button[i][0]->setMinimumHeight(i);
		v_button[i][0]->setMinimumWidth(3);
		connect(v_button[i][0], SIGNAL(released()), this, SLOT(handleVShift()));
        v_button[i][0]->setVisible(false);

		v_button[i][1] = new QPushButton("/\\", this);
		v_button[i][1]->setGeometry(QRect(QPoint(24 + 24 + 24 + (2*50*i) + 50, 8 + 24 + 8 + 50*VELIKOST + 8), QSize(48, 24)));
		v_button[i][1]->setMinimumHeight(i);
		v_button[i][1]->setMinimumWidth(1);
		connect(v_button[i][1], SIGNAL(released()), this, SLOT(handleVShift()));
        v_button[i][1]->setVisible(false);
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
    ui->card->setVisible(false);
	changeCard();

	ui->rotateR->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20), QSize(48, 24)));
	connect(ui->rotateR, SIGNAL(released()), this, SLOT(handleRotateR()));
	changeIcon(ui->rotateR, "resources/rotateR.png");
    ui->rotateR->setVisible(false);

	ui->rotateL->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20 + 24 + 4 + 48 + 4), QSize(48, 24)));
	connect(ui->rotateL, SIGNAL(released()), this, SLOT(handleRotateL()));
	changeIcon(ui->rotateL, "resources/rotateL.png");
    ui->rotateL->setVisible(false);

	ui->square->setGeometry(QRect(QPoint(24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8, 20 + 128 + 20 + 24 + 4), QSize(48, 48)));
	//ui->square->setPixmap( QPixmap( "resources/square.png"));
    ui->square->setVisible(false);

    ui->spinBox->setGeometry(QRect(QPoint((24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8)/2 + 30, (vyska - 76)/2 + 20), QSize(48, 24)));

    ui->label_5->setGeometry(QRect(QPoint((24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 32 + 8)/2+30, (vyska - 98)/2), QSize(48, 24)));

    ui->spinBox_2->setGeometry(QRect(QPoint((24 + 24 + 24 + (50*VELIKOST))/2 + 5, (vyska - 76)/2 + 20), QSize(48, 24)));

    ui->label_6->setGeometry(QRect(QPoint((24 + 24 + 24 + (50*VELIKOST))/2, (vyska - 98)/2), QSize(68, 24)));

    ui->pushButton->setGeometry(QRect(QPoint((24 + 24 + 24 + (50*VELIKOST) + 24 + 24 + 5)/2, (vyska - 50)/2 + 50), QSize(74, 24)));

	ui->checkBox->setGeometry(QRect(QPoint(13, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(20, 20)));
	ui->checkBox_2->setGeometry(QRect(QPoint(103, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(20, 20)));
	ui->checkBox_3->setGeometry(QRect(QPoint(186, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(20, 20)));
	ui->checkBox_4->setGeometry(QRect(QPoint(286, 8 + 24 + 8 + 50*VELIKOST + 8 + 24 + 8), QSize(20, 20)));

	connect(ui->pushButton, SIGNAL(released()), this, SLOT(spust()));

}
