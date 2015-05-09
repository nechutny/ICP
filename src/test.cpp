#include <stdio.h>
#include "map.h"

void renderMap(Map* mapa)
{
	Block** blocks = mapa->getMap();

	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			std::cout << blocks[ mapa->offset(i, j) ]->toChar();
		}

		std::cout << "\n";
	}

	std::cout << "\nFree block: " << mapa->getFreeBlock()->toChar() << "\n\n";

}

int main(int argc, char* argv[])
{
	Map *mapa = new Map;

	mapa->generate(11, 24);

	renderMap(mapa);

	std::cout << "\n Shift 2. row to right\n";
	mapa->shift(0, 1);
	renderMap(mapa);

	std::cout << "\n Shift 2. column to up\n";
	mapa->shift(1, 1);
	renderMap(mapa);

	std::cout << "\n Shift 2. row to left\n";
	mapa->shift(2, 1);
	renderMap(mapa);

	std::cout << "\n Rotate free block right\n";
	mapa->getFreeBlock()->rotateRight();
	renderMap(mapa);

	std::cout << "\n Rotate free block right\n";
	mapa->getFreeBlock()->rotateRight();
	renderMap(mapa);

	std::cout << "\n Shift 2. column to down\n";
	mapa->shift(3, 1);
	renderMap(mapa);

	Player* pl1 = new Player(COLOR_RED, mapa, false);


	std::cout << "\n Move player one block right (from 0,0 to 2,2)\n";
	if(pl1->move(2,2))
	{
		std::cout << "Success\n";
	}
	else
	{
		std::cout << "Fail\n";
	}

	delete pl1;

	delete mapa;
}
