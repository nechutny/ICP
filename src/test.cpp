/**
 * Test
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 *
 */

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
	Player* pls[4];

	pls[0] = pl1;
	pls[1] = pls[2] = pls[3] = NULL;
	int on_turn = 0;
	bool posunul = false;


	std::cout << "\n Move player one block right (from 0,0 to 2,2)\n";
	if(pl1->move(2,2))
	{
		std::cout << "Success\n";
	}
	else
	{
		std::cout << "Fail\n";
	}

	std::cout << "\n\nSave map\n";
	mapa->save((Player**)pls, on_turn,  posunul, false);

	std::cout << "Shift map 2 times\n";
	mapa->shift(3, 1);
	mapa->shift(3, 1);
	renderMap(mapa);

	std::cout << "Restore map\n";
	mapa->load((Player**)pls, &on_turn,  &posunul, false);
	renderMap(mapa);

	delete pl1;

	delete mapa;
}
