/**
 * Player
 *
 * @author	Stanislav Nechutný - xnechu01
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "types.h"

class Player;

#include "map.h"

class Player
{
	protected:
		color _color;
		int _score;
		int _position_x;
		int _position_y;
		int _symbol;
		int _id;
		Map* _map;

	public:
		/**
		 * Get player color
		 *
		 * @return color	Player color
		 */
		color getColor();

		/**
		 * Move player to new positon
		 *
		 * @param	int	x	X coordinate of new position
		 * @param	int	y	Y coordinate of new position
		 *
		 * @return	bool	True for succes, False if is turn impossible
		 */
		 bool move(int x, int y);

		/**
		 * Get ID of currently needed symbol
		 *
		 * @return	int	ID of symbol, or 0 for nothing
		 */
		int getSymbol();

		/**
		 * Get player score
		 *
		 * @return	int	Player score
		 */
		int getScore();

		/**
		 * Get player position (X/Y)
		 *
		 * @return	int Position
		 */
		int getPositionX();
		int getPositionY();

		/**
		 * Does player win game?
		 *
		 * @return	bool	Win
		 */
		bool win();

		/**
		 * Set player color
		 *
		 * @param	color	playerColor	Player color
		 */
		void setColor(color playerColor);


		/**
		 * Get player ID
		 *
		 * @return	int	ID of player
		 */
		int getId();

		/**
		 * Set player ID
		 *
		 * @param	int	id	User id
		 */
		void setId(int id);

		/**
		 * Inject pointer to map
		 *
		 * @param	Map*	map	Map pointer
		 */
		void injectMap(Map* map);
};
#endif
