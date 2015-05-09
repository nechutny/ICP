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
		/**
		 * Player constructor
		 *
		 * @param	col		Player color
		 * @param	map		Pointer to map
		 * @param	notPlaceOnStart	True for not placing player on start position
		 */
		Player(color col, Map* map, bool notPlaceOnStart);

		/**
		 * Get player color
		 *
		 * @return Player color
		 */
		color getColor();

		/**
		 * Move player to new positon
		 *
		 * @param	x	X coordinate of new position
		 * @param	y	Y coordinate of new position
		 *
		 * @return	True for succes, False if is turn impossible
		 */
		 bool move(int x, int y);

		/**
		 * Get ID of currently needed symbol
		 *
		 * @return	ID of symbol, or 0 for nothing
		 */
		int getSymbol();

		/**
		 * Set searching symbol for player
		 *
		 * @param	symbol	ID of symbol to find
		 */
		void setSymbol(int symbol);

		/**
		 * Get player score
		 *
		 * @return	Player score
		 */
		int getScore();

		/**
		 * Set player's score
		 *
		 * @param	score	Score to be set
		 */
		void setScore(int score);

		/**
		 * Get player position X
		 *
		 * @return	Position
		 */
		int getPositionX();

		/**
		 * Get player position X
		 *
		 * @return	Position
		 */
		int getPositionY();

		/**
		 * Set player position
		 *
		 * @param	x	Position X
		 * @param	y	Position Y
		 */
		void setPosition(int x, int y);

		/**
		 * Does player win game?
		 *
		 * @return	Win
		 */
		bool win();

		/**
		 * Set player color
		 *
		 * @param	playerColor	Player color
		 */
		void setColor(color playerColor);


		/**
		 * Get player ID
		 *
		 * @return	ID of player
		 */
		int getId();

		/**
		 * Set player ID
		 *
		 * @param	id	User id
		 */
		void setId(int id);

		/**
		 * Inject pointer to map
		 *
		 * @param	map	Map pointer
		 */
		void injectMap(Map* map);
};
#endif
