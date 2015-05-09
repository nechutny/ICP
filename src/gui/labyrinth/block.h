/**
 * Block
 *
 * @author	Stanislav Nechutný - xnechu01
 */
#ifndef BLOCK_H
#define BLOCK_H

class Block;

#include <iostream>
#include <stdbool.h>
#include "types.h"
#include "player.h"


class Block
{
	private:
		block_type _type;
		int _rotation;
		int _symbol;
		Player** _players;

	public:
		/**
		 * Block constructor, perform allocations
		 */
		Block();

		/**
		 * Block destructor - deallocate memory
		 */
		~Block();

		/**
		 * Get block rotation
		 *
		 * @return	int	Number 0-3, radians in positive direction of rotation
		 */
		int getRotation();

		/**
		 * Set block rotation
		 *
		 * @param	int	rot	Number 0-3, radians in positive direction of rotation
		 */
		void setRotation(int rot);

		/**
		 * Get block type
		 *
		 * @return	block_type	L, T, I
		 */
		block_type getType();

		/**
		 * Get symbol from block
		 *
		 * @return	int	0 for no symbol, or symbol ID
		 */
		int getSymbol();

		/**
		 * Get array of players on block
		 *
		 * @return	void**	Pointer to array
		 */
		Player** getPlayers();


		/**
		 * Set array of players on block
		 *
		 * @param	Player**	players	Pointer to array
		 */
		void setPlayers(Player** players);

		/**
		 * Check, if is any players standing on this block
		 *
		 * @return	bool	True for player, false = empty
		 */
		bool isOccupied();

		/**
		 * Inform players about move
		 *
		 * @param	int	x	X positon
		 * @param	int	y	Y position
		 */
		void informMoved(int x, int y);

		/**
		 * Rotate block left
		 */
		void rotateLeft();

		/**
		 * Rotate block right
		 */
		void rotateRight();

		/**
		 * Place player on block
		 *
		 * @param	Player*	player	Player to be added
		 */
		void addPlayer(Player* player);

		/**
		 * Remove player from block
		 *
		 * @param	int	playerId	Playerd id
		 */
		void removePlayer(int playerId);


		/**
		 * Set block type
		 *
		 * @param	block_type	type	Block type (L, T, I)
		 */
		void setType(block_type type);

		/**
		 * Set block symbol
		 *
		 * @param	int	symbol	Symbol ID, or 0 for nothing
		 */
		void setSymbol(int symbol);

		bool toDirection(int direction);
		bool fromDirection(int direction);

		std::string toChar();
};
#endif
