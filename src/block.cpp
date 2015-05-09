/**
 * Block
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
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
 * @return	Number 0-3, radians in positive direction of rotation
 */
int Block::getRotation()
{
	return _rotation;
}


/**
 * Set block rotation
 *
 * @param	rot	Number 0-3, radians in positive direction of rotation
 */
void Block::setRotation(int rot)
{
	_rotation = rot;
}


/**
 * Get block type
 *
 * @return	TYPE_L, TYPE_T, TYPE_I
 */
block_type Block::getType()
{
	return _type;
}


/**
 * Get symbol from block
 *
 * @return	0 for no symbol, or symbol ID
 */
int Block::getSymbol()
{
	return _symbol;
}


/**
 * Get array of players on block
 *
 * @return	Pointer to array
 */
Player** Block::getPlayers()
{
	return _players;
}


/**
 * Set array of players on block
 *
 * @param	players	Pointer to array
 */
void Block::setPlayers(Player** players)
{
	_players = players;
}


/**
 * Remove all players from this block
 */
void Block::resetPlayers()
{
	_players[0] = _players[1] = _players[2] = _players[3] = NULL;
}


/**
 * Inform players about move
 *
 * @param	x	X positon
 * @param	y	Y position
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
 * @return	True for player, false = empty
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
	_rotation = (_rotation+1)%4;
}


/**
 * Rotate block right
 */
void Block::rotateRight()
{
	_rotation = (_rotation+3)%4;
}


/**
 * Place player on block
 *
 * @param	player	Player to be added
 */
void Block::addPlayer(Player* player)
{
	_players[player->getColor()] = player;
}


/**
 * Remove player from block
 *
 * @param	playerId	Playerd id
 */
void Block::removePlayer(int playerId)
{
	_players[playerId] = NULL;
}


/**
 * Set block type
 *
 * @param	type	Block type (TYPE_L, TYPE_T, TYPE_I)
 */
void Block::setType(block_type type)
{
	_type = type;
}


/**
 * Set block symbol
 *
 * @param	symbol	Symbol ID, or 0 for nothing
 */
void Block::setSymbol(int symbol)
{
	_symbol = symbol;
}


/**
 * Check if is possible to go from block to given direction
 *
 * @param	direction	Direction to go
 *
 * @return	TRUE for success, FALSE for failure
 */
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


/**
 * Check if is possible to go to block from given direction
 *
 * @param	direction	Direction to go
 *
 * @return	TRUE for success, FALSE for failure
 */
bool Block::fromDirection(int direction)
{
	return toDirection(direction);
}


/**
 * Function returning UTF-8 encoded character for CLI drwaing
 *
 * @return	Character to display
 */
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

