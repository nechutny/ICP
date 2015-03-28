/**
 * Player
 *
 * @author	Stanislav Nechutný - xnechu01
 */

#include <stdbool.h>
#include "types.h"
#include "player.h"
#include "map.h"


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
	 return true;
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

