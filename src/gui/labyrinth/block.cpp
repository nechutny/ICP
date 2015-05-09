/**
 * Block
 *
 * @author	Stanislav Nechutný - xnechu01
 */

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "player.h"
#include "block.h"

/**
 * Block constructor, perform allocations
 */
Block::Block()
{
	_type = TYPE_L;
	_rotation = 0;
	_symbol = 0;
	_players = (Player**)malloc(sizeof(Player*)*4);
	_players[0] = NULL;
	_players[1] = NULL;
	_players[2] = NULL;
	_players[3] = NULL;
}


/**
 * Block destructor - deallocate memory
 */
Block::~Block()
{
	free(_players);
}


/**
 * Get block rotation
 *
 * @return	int	Number 0-3, radians in positive direction of rotation
 */
int Block::getRotation()
{
	return _rotation;
}

/**
 * Set block rotation
 *
 * @param	int	rot	Number 0-3, radians in positive direction of rotation
 */
void Block::setRotation(int rot)
{
	_rotation = rot;
}

/**
 * Get block type
 *
 * @return	block_type	TYPE_L, TYPE_T, TYPE_I
 */
block_type Block::getType()
{
	return _type;
}

/**
 * Get symbol from block
 *
 * @return	int	0 for no symbol, or symbol ID
 */
int Block::getSymbol()
{
	return _symbol;
}

/**
 * Get array of players on block
 *
 * @return	Player**	Pointer to array
 */
Player** Block::getPlayers()
{
	return _players;
}

/**
 * Set array of players on block
 *
 * @param	Player**	players	Pointer to array
 */
void Block::setPlayers(Player** players)
{
	_players = players;
}

/**
 * Inform players about move
 *
 * @param	int	x	X positon
 * @param	int	y	Y position
 */
void Block::informMoved(int x, int y)
{
	if(isOccupied())
	{
		for(int i = 0; i < 4; i++)
		{
			if(_players[i] != NULL)
			{
				_players[i]->setPosition(x,y);
			}
		}
	}
}

/**
 * Check, if is any players standing on this block
 *
 * @return	bool	True for player, false = empty
 */
bool Block::isOccupied()
{
	return (_players[0] != NULL || _players[1] != NULL || _players[2] != NULL || _players[3] != NULL);
}

/**
 * Rotate block left
 */
void Block::rotateLeft()
{
	printf("a: %d\n", _rotation);
	_rotation = (_rotation+1)%4;
	printf("a: %d\n", _rotation);
}

/**
 * Rotate block right
 */
void Block::rotateRight()
{
	printf("b: %d\n", _rotation);
	_rotation = (_rotation+3)%4;
	printf("b: %d\n", _rotation);
}

/**
 * Place player on block
 *
 * @param	Player*	player	Player to be added
 */
void Block::addPlayer(Player* player)
{
	_players[player->getColor()] = player;
}

/**
 * Remove player from block
 *
 * @param	int	playerId	Playerd id
 */
void Block::removePlayer(int playerId)
{
	_players[playerId] = NULL;
}


/**
 * Set block type
 *
 * @param	block_type	type	Block type (TYPE_L, TYPE_T, TYPE_I)
 */
void Block::setType(block_type type)
{
	_type = type;
}

/**
 * Set block symbol
 *
 * @param	int	symbol	Symbol ID, or 0 for nothing
 */
void Block::setSymbol(int symbol)
{
	_symbol = symbol;
}

bool Block::toDirection(int direction)
{
	int rotation = getRotation();

	switch(getType())
	{
		case TYPE_L:
			return ( direction == rotation || direction == (rotation+1)%4);
		case TYPE_I:
			return ((direction+1)%2 == rotation%2);

		case TYPE_T:
			return ((rotation+1)%4 != direction);
	}

	return false;
}
bool Block::fromDirection(int direction)
{
	return toDirection(direction);
}

std::string Block::toChar()
{
	switch(getType())
	{
		case TYPE_L:
			switch(getRotation())
			{
				case 0:
					return "╚";
				case 1:
					return "╝";
				case 2:
					return "╗";
				case 3:
					return "╔";
			}
		case TYPE_I:
			switch(getRotation()%2)
			{
				case 0:
					return "║";
				case 1:
					return "═";
			}
		case TYPE_T:
			switch(getRotation())
			{
				case 0:
					return "╦";
				case 1:
					return "╠";
				case 2:
					return "╩";
				case 3:
					return "╣";
			}
	}

	return " ";
}

