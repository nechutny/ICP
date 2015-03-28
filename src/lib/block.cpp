/**
 * Block
 *
 * @author	Stanislav Nechutný - xnechu01
 */

#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "player.h"
#include "block.h"



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
	// TODO
	return NULL;
}

/**
 * Check, if is any players standing on this block
 *
 * @return	bool	True for player, false = empty
 */
bool Block::isOccupied()
{
	return true;
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

