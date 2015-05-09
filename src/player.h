/**
 * Player
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "types.h"
#include <stack>

class Player;

#include "map.h"
#include "block.h"

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
		/** Player constructor
		 *
		 * @param	color	col		Player color
		 * @param	Map*	map		Pointer to map
		 * @param	bool	notPlaceOnStart	True for not placing player on start position
		 */
		Player(color col, Map* map, bool notPlaceOnStart);

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
		 * Set searching symbol for player
		 *
		 * @param	int	symbol	ID of symbol to find
		 */
		void setSymbol(int symbol);

		/**
		 * Get player score
		 *
		 * @return	int	Player score
		 */
		int getScore();

		/**
		 * Set player's score
		 *
		 * @param	int	score	Score to be set
		 */
		void setScore(int score);

		/**
		 * Get player position X
		 *
		 * @return	int Position
		 */
		int getPositionX();

		/**
		 * Get player position X
		 *
		 * @return	int Position
		 */
		int getPositionY();

		/**
		 * Set player position
		 *
		 * @param	int	x	Position X
		 * @param	int	y	Position Y
		 */
		void setPosition(int x, int y);

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
