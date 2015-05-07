/**
 * Player
 *
 * @author	Stanislav Nechutný - xnechu01
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"
#include "map.h"


Player::Player(color col,  Map* map)
{
	_color = col;
	_score = 0;
	_position_x = (col%2 == 0) ? 0 : map->getSize()-1;
	_position_y = (col < 2) ? 0 : map->getSize()-1;
	_symbol = 0;
	_id = col;
	_map = map;

	Block** blocks = _map->getMap();

	blocks[ _map->offset(_position_x, _position_y) ]->addPlayer(this);
}


/**
 * Get player color
 *
 * @return color	Player color
 */
color Player::getColor()
{
	return _color;
}

/**
 * Move player to new positon
 *
 * @param	int	x	X coordinate of new position
 * @param	int	y	Y coordinate of new position
 *
 * @return	bool	True for succes, False if is turn impossible
 */
 bool Player::move(int x, int y)
 {
	 // TODO
	 //_position_x = x;
	 //_position_y = y;


	Block** blocks = _map->getMap();

	std::stack<int>* _open1 = new std::stack<int>;
	std::stack<int>* _open2 = new std::stack<int>;
	int* _close = (int*)calloc(_map->getSize()*_map->getSize(), sizeof(int));


	int pos_x = _position_x, pos_y = _position_y;

	_close[ _map->offset(pos_x, pos_y) ] = 1;

	do
	{
		printf("examine [%d,%d]\n", pos_x, pos_y);
		if(x == pos_x && y == pos_y)
		{
			printf("found [%d,%d]\n",pos_x,pos_y);
			delete _open1;
			delete _open2;
			free(_close);

			blocks[ _map->offset(_position_x, _position_y) ]->removePlayer(_id);
			blocks[ _map->offset(x, y) ]->addPlayer(this);

			return true;
		}

		Block* blk = blocks[ _map->offset(pos_x, pos_y) ];

		// Right
		printf("right\n");
		if(pos_y < _map->getSize()-2)
		{
			if(blk->toDirection(0) && blocks[ _map->offset(pos_x, pos_y+1)]->fromDirection(2) && _close[ _map->offset(pos_x, pos_y+1) ] == 0)
			{
				_open1->push(pos_x);
				_open2->push(pos_y+1);
				printf("pushing [%d,%d]\n", pos_x, pos_y+1);
				_close[ _map->offset(pos_x, pos_y+1) ] = 1;
			}
		}

		// Up
		printf("up\n");
		if(pos_x > 0)
		{
			if(blk->toDirection(1) && blocks[ _map->offset(pos_x-1, pos_y)]->fromDirection(3)  && _close[ _map->offset(pos_x-1, pos_y) ] == 0)
			{
				_open1->push(pos_x-1);
				_open2->push(pos_y);
				printf("pushing [%d,%d]\n", pos_x-1, pos_y);
				_close[ _map->offset(pos_x-1, pos_y) ] = 1;
			}
		}

		// Left
		printf("left\n");
		if(pos_y > 0)
		{
			if(blk->toDirection(2) && blocks[ _map->offset(pos_x, pos_y-1)]->fromDirection(0)  && _close[ _map->offset(pos_x, pos_y-1) ] == 0)
			{
				_open1->push(pos_x);
				_open2->push(pos_y-1);
				printf("pushing [%d,%d]\n", pos_x, pos_y-1);
				_close[ _map->offset(pos_x, pos_y-1) ] = 1;
			}
		}

		// Down
		printf("down\n");
		if(pos_x < _map->getSize()-2)
		{
			if(blk->toDirection(3) && blocks[ _map->offset(pos_x+1, pos_y)]->fromDirection(1)  && _close[ _map->offset(pos_x+1, pos_y) ] == 0)
			{
				_open1->push(pos_x+1);
				_open2->push(pos_y);
				printf("pushing [%d,%d]\n", pos_x+1, pos_y);
				_close[ _map->offset(pos_x+1, pos_y) ] = 1;
			}
		}

		if(_open1->size() == 0)
		{
			break;
		}

		pos_x = _open1->top();
		_open1->pop();
		pos_y = _open2->top();
		_open2->pop();
	} while(true);

	delete _open1;
	delete _open2;
	free(_close);
	return false;
 }

/**
 * Get ID of currently needed symbol
 *
 * @return	int	ID of symbol, or 0 for nothing
 */
int Player::getSymbol()
{
	return _symbol;
}

/**
 * Get player score
 *
 * @return	int	Player score
 */
int Player::getScore()
{
	return _score;
}

/**
 * Get player position (X/Y)
 *
 * @return	int Position
 */
int Player::getPositionX()
{
	return _position_x;
}

int Player::getPositionY()
{
	return _position_y;
}

/**
 * Does player win game?
 *
 * @return	bool	Win
 */
bool Player::win()
{
	// TODO
	return true;
}

/**
 * Set player color
 *
 * @param	color	playerColor	Player color
 */
void Player::setColor(color playerColor)
{
	_color = playerColor;
}


/**
 * Get player ID
 *
 * @return	int	ID of player
 */
int Player::getId()
{
	return _id;
}

/**
 * Set player ID
 *
 * @param	int	id	User id
 */
void Player::setId(int id)
{
	_id = id;
}

/**
 * Inject pointer to map
 *
 * @param	Map*	map	Map pointer
 */
void Player::injectMap(Map* map)
{
	_map = map;
}

