#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"


void Map::save()
{
	// TODO
}

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


void Map::generate(int N, int symbols)
{
	_last_direction = 0;
	_last_column = 0;

	srand (time(NULL));

	_map = (Block**)malloc( sizeof(Block*) *N*N );

	_size = N;

	Block *tmp = new Block;
	tmp->setType(TYPE_L);
	tmp->setRotation(3);
	_map[ offset(0,0) ] = tmp;


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

	for(int  i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if((i == 0 && j%2 ==0) || (j == 0 && i%2 ==0) || (j == N-1 && i%2 ==0) || (i == N-1 && j%2 ==0))
			{

			}
			else
			{
				printf("map %d %d\n",i,j);
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

	_freeBlock = new Block;
	_freeBlock->setType((block_type)type);
	_freeBlock->setRotation((type+rand1) % 4 );

	while(true)
	{
		rand1 = rand()%_size;
		rand2 = rand()%_size;
		if((rand1 == 0 && rand2 == 0) || (rand1 == (unsigned)_size-1 && rand2 == 0)  || (rand2 == (unsigned)_size-1 && rand1 == 0) || (rand1 == (unsigned)_size-1 && rand2 == (unsigned)_size-1))
		{
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


int Map::getSize()
{
	return _size;
}


Block** Map::getMap()
{
	return _map;
}


bool Map::shift(int direction, int columnRow)
{
	Block* tmp;

	if(_last_direction == ((direction+2)%4) && _last_column == columnRow)
	{
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


Block* Map::getFreeBlock()
{
	return _freeBlock;
}

int Map::getMaxSymbolsCount()
{
	return 42;
}

int Map::offset(int x, int y)
{
	if(x >= _size || y >= _size)
	{
		std::cerr << "Bad coords [" << x << ", " << y << "]\n";
		return -1;
	}

	return x*_size + y;
}
