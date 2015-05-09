/**
 * Map
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "save.h"


/**
 * Save current state for load/unbo
 *
 * @param	players	Pinter to array of players for read their state (position, score, color etc.)
 * @param	onTurn	Number of player on turn
 * @param	posunul	Did player shift card in this turn?
 * @param	toFile	Save to file for future load, or just into stack for undo
 */
void Map::save(Player** players, int onTurn, bool posunul, bool toFile)
{
	saveT* sav = (saveT*)calloc(sizeof(saveT),1);

	sav->freeBlockType = _freeBlock->getType();
	sav->freeBlockRotation = _freeBlock->getRotation();
	sav->freeBlockSymbol = _freeBlock->getSymbol();
	int off = 0;
	for(int i = 0; i < getSize(); i++)
	{
		for(int j = 0; j < getSize(); j++)
		{
			off = offset(i,j);
			sav->blockType[off] = _map[off]->getType();
			sav->blockSymbol[off] = _map[off]->getSymbol();
			sav->blockRotation[off] = _map[off]->getRotation();
		}
	}

	sav->player_on_turn = onTurn;
	sav->posunul = posunul;
	sav->size = _size;
	sav->symbols = _symbols;

	for(int i = 0; i < 4; i++)
	{
		if(players[i] == NULL)
		{
			sav->playerPosX[i] = 0;
			sav->playerPosY[i] = 0;
			sav->playerScore[i] = 0;
			sav->playerSymbol[i] = 0;
			sav->playerColor[i] = 0;
		}
		else
		{
			sav->playerPosX[i] = players[i]->getPositionX();
			sav->playerPosY[i] = players[i]->getPositionY();
			sav->playerScore[i] = players[i]->getScore();
			sav->playerSymbol[i] = players[i]->getSymbol();
			sav->playerColor[i] = players[i]->getColor();
		}
	}

	if(toFile)
	{
		FILE* fp = fopen("save.dat","w");
		fwrite(sav, 1, sizeof(saveT), fp);
		fclose(fp);
	}
	else
	{
		_save->push(sav);
	}

}


/**
 * Load previous state from file/undo buffer
 *
 * @param	players		Pinter to array of players for setting their state (position, score, color etc.)
 * @param	onTurn		Number of player on turn
 * @param	posunul		Did player shift card in this turn?
 * @param	fromFile	Load from file or just from stack for undo
 *
 * @return	Pointer to loaded structure with data, or NULL if fail
 */
saveT* Map::load(Player** players, int* onTurn, bool* posunul, bool fromFile)
{
	saveT* sav;

	if(fromFile)
	{ // read from file
		sav = (saveT*)calloc(sizeof(saveT),1);
		FILE* fp = fopen("save.dat","r");
		int foo = fread(sav, 1, sizeof(saveT), fp);
		printf("%d\n", foo);
		fclose(fp);
	}
	else
	{
		if(_save->size() == 0)
		{
			printf("Jiz nejde vratit\n");
			return NULL;
		}
		sav = _save->top();
		_save->pop();
	}


	_freeBlock->setType((block_type)sav->freeBlockType);
	_freeBlock->setRotation(sav->freeBlockRotation);
	_freeBlock->setSymbol(sav->freeBlockSymbol);
	_size = sav->size;
	_symbols = sav->symbols;

	int off = 0;
	for(int i = 0; i < getSize(); i++)
	{ // restore blocks
		for(int j = 0; j < getSize(); j++)
		{
			off = offset(i,j);
			_map[off]->setType((block_type)sav->blockType[off]);
			_map[off]->setSymbol(sav->blockSymbol[off]);
			_map[off]->setRotation(sav->blockRotation[off]);
			_map[off]->resetPlayers();
		}
	}

	*onTurn = sav->player_on_turn;
	*posunul = sav->posunul;

	for(int i = 0; i < 4; i++)
	{ // restore players
		printf("Obnovit %d (%d) na [%d,%d]\n", sav->playerSymbol[i], sav->playerColor[i], sav->playerPosX[i], sav->playerPosY[i]);
		if(sav->playerSymbol[i] != 0)
		{
			if(fromFile)
			{
				players[i] = new Player((color)sav->playerColor[i], this, true);
			}
			players[i]->setPosition(sav->playerPosX[i], sav->playerPosY[i]);
			players[i]->setScore(sav->playerScore[i]);
			players[i]->setSymbol(sav->playerSymbol[i]);
			players[i]->setColor((color)sav->playerColor[i]);

			_map[ offset(sav->playerPosX[i], sav->playerPosY[i]) ]->addPlayer(players[i]);
		}

	}

	return sav;
}


/**
 * Free allocated memory
 */
Map::~Map()
{
	for(int  i = 0; i < _size; i++)
	{
		for(int j = 0; j < _size; j++)
		{
			delete _map[ offset(i, j) ];
		}
	}

	delete _freeBlock;

	free(_map);
}


/**
 * Get number of symbols (12/24)
 *
 * @return	Number of symbols on map
 */
int Map::getSymbols()
{
	return _symbols;
}


/**
 * Get number of players on map
 *
 * @return	Number of players on map
 */
int Map::getPlayers()
{
	return _players;
}


/**
 * Increase counter of players on map
 */
void Map::incPlayer()
{
	_players++;
}


/**
 * Generate map
 *
 * @param	N	Size of map (odd number 5-11)
 * @param	symbols	Number of symbols
 */
void Map::generate(int N, int symbols)
{
	_save = new std::stack<saveT*>;

	_last_direction = 0;
	_last_column = 0;
	_symbols = symbols;
	_players = 0;

	srand (time(NULL));

	_map = (Block**)malloc( sizeof(Block*) *N*N );

	_size = N;

	Block *tmp = new Block;
	tmp->setType(TYPE_L);
	tmp->setRotation(3);
	_map[ offset(0,0) ] = tmp;

	// Corners
	tmp = new Block;
	tmp->setType(TYPE_L);
	tmp->setRotation(2);
	_map[ offset(0,N-1) ] = tmp;

	tmp = new Block;
	tmp->setType(TYPE_L);
	tmp->setRotation(1);
	_map[ offset(N-1,N-1) ] = tmp;

	tmp = new Block;
	tmp->setType(TYPE_L);
	tmp->setRotation(0);
	_map[ offset(N-1,0) ] = tmp;

	// Borders (odd)
	for(int i = 2; i < N-1; i += 2)
	{
		tmp = new Block;
		tmp->setType(TYPE_T);
		tmp->setRotation(0);
		_map[ offset(0,i) ] = tmp;
	}

	for(int i = 2; i < N-1; i += 2)
	{
		tmp = new Block;
		tmp->setType(TYPE_T);
		tmp->setRotation(1);
		_map[ offset(i,0) ] = tmp;
	}

	for(int i = 2; i < N-1; i += 2)
	{
		tmp = new Block;
		tmp->setType(TYPE_T);
		tmp->setRotation(3);
		_map[ offset(i,N-1) ] = tmp;
	}

	for(int i = 2; i < N-1; i += 2)
	{
		tmp = new Block;
		tmp->setType(TYPE_T);
		tmp->setRotation(2);
		_map[ offset(N-1, i) ] = tmp;
	}

	unsigned rand1 = rand(), rand2 = rand();
	unsigned type = 1;

	// Remaining empty blocks
	for(int  i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if((i == 0 && j%2 ==0) || (j == 0 && i%2 ==0) || (j == N-1 && i%2 ==0) || (i == N-1 && j%2 ==0))
			{

			}
			else
			{
				//printf("map %d %d\n",i,j);
				rand1 = rand();
				rand2 = rand();

				type = (i*rand1+j*rand2)%4;

				if(type == 3)
				{
					type = 1;
				}

				tmp = new Block;
				tmp->setType((block_type)type);
				tmp->setRotation((type+rand1*j) % 4 );
				_map[ offset(i, j) ] = tmp;
			}
		}
	}

	// Free block for shifting
	_freeBlock = new Block;
	_freeBlock->setType((block_type)type);
	_freeBlock->setRotation((type+rand1) % 4 );

	// Add symbols
	while(true)
	{
		rand1 = rand()%_size;
		rand2 = rand()%_size;
		if((rand1 == 0 && rand2 == 0) || (rand1 == (unsigned)_size-1 && rand2 == 0)  || (rand2 == (unsigned)_size-1 && rand1 == 0) || (rand1 == (unsigned)_size-1 && rand2 == (unsigned)_size-1))
		{ // Don't place symbols on corners
		}
		else
		{
			if(_map[ offset(rand1, rand2) ]->getSymbol() == 0)
			{
				_map[ offset(rand1, rand2) ]->setSymbol(symbols);
				symbols--;
				if(symbols == 0)
				{
					break;
				}
			}
		}
	}
}


/**
 * Get map size
 *
 * @return	Map size
 */
int Map::getSize()
{
	return _size;
}


/**
 * Get map in 2 dimensional array
 *
 * @return	Pointer to 2D array of blocks
 */
Block** Map::getMap()
{
	return _map;
}


/**
 * Shift map
 *
 * @param	direction	0 ... right, 1 ... up, 2 ... left, 3 ... down
 * @param	columnRow	Index of collumn, or row to be shifted
 *
 * @return	True for success, false for fail (reverse sihft)
 */
bool Map::shift(int direction, int columnRow)
{
	Block* tmp;

	if(_last_direction == ((direction+2)%4) && _last_column == columnRow)
	{ // Shifting is revesring last done shift
		return false;
	}
	else
	{
		_last_direction = direction;
		_last_column = columnRow;
	}

	switch(direction)
	{
		// Right
		case 0:
			tmp = _map[ offset(columnRow, _size-1) ];
			for(int i = _size-2; i >= 0; i--)
			{
				_map[ offset(columnRow, i+1) ] = _map[ offset(columnRow, i) ];
				_map[ offset(columnRow, i+1) ]->informMoved(columnRow, i+1);
			}

			_map[ offset(columnRow, 0) ] = _freeBlock;

			if(tmp->isOccupied())
			{
				Player** pls = tmp->getPlayers();
				tmp->informMoved(columnRow, 0);
				tmp->setPlayers(_freeBlock->getPlayers());
				_freeBlock->setPlayers(pls);

			}

			_freeBlock = tmp;

			break;

		// Up
		case 1:
			tmp = _map[ offset(0, columnRow) ];
			for(int i = 1; i < _size; i++)
			{
				_map[ offset(i-1, columnRow) ] = _map[ offset(i, columnRow) ];
				_map[ offset(i-1, columnRow) ]->informMoved(i-1, columnRow);
			}

			_map[ offset(_size-1, columnRow) ] = _freeBlock;

			if(tmp->isOccupied())
			{
				Player** pls = tmp->getPlayers();
				tmp->informMoved(_size-1, columnRow);
				tmp->setPlayers(_freeBlock->getPlayers());
				_freeBlock->setPlayers(pls);
			}

			_freeBlock = tmp;

			break;

		// Left
		case 2:
			tmp = _map[ offset(columnRow, 0) ];
			for(int i = 1; i < _size; i++)
			{
				_map[ offset(columnRow, i-1) ] = _map[ offset(columnRow, i) ];
				_map[ offset(columnRow, i-1) ]->informMoved(columnRow, i-1);
			}

			_map[ offset(columnRow, _size-1) ] = _freeBlock;

			if(tmp->isOccupied())
			{
				Player** pls = tmp->getPlayers();
				tmp->informMoved(columnRow, _size-1);
				tmp->setPlayers(_freeBlock->getPlayers());
				_freeBlock->setPlayers(pls);
			}

			_freeBlock = tmp;

			break;
		// Down
		case 3:
			tmp = _map[ offset(_size-1, columnRow) ];
			for(int i = _size-2; i >= 0; i--)
			{
				_map[ offset(i+1, columnRow) ] = _map[ offset(i, columnRow) ];
				_map[ offset(i+1, columnRow) ]->informMoved(i+1, columnRow);
			}

			_map[ offset(0, columnRow) ] = _freeBlock;

			if(tmp->isOccupied())
			{
				Player** pls = tmp->getPlayers();
				tmp->informMoved(0, columnRow);
				tmp->setPlayers(_freeBlock->getPlayers());
				_freeBlock->setPlayers(pls);
			}

			_freeBlock = tmp;

			break;
	}

	return true;
}


/**
 * Get free block
 *
 * @return	Free block, which can be used for shifting
 */
Block* Map::getFreeBlock()
{
	return _freeBlock;
}


/**
 * Calculate offset for block array
 *
 * @param	x	Row number from 0
 * @param	y	Column number from 0
 *
 * @return	Offset, or -1 for out of range
 */
int Map::offset(int x, int y)
{
	if(x >= _size || y >= _size)
	{
		std::cerr << "Bad coords [" << x << ", " << y << "]\n";
		return -1;
	}

	return x*_size + y;
}
