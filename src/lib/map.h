/**
 * Map
 *
 * @author	Stanislav Nechutný - xnechu01
 */
#ifndef MAP_H
#define MAP_H

#include "block.h"

class Map
{
	protected:
		Block* _freeBlock;
		Block** _map;
		int size;
		// TODO: onTurn[]

	public:
		/**
		 * Save map to file for future load
		 */
		void save();

		/**
		 * Generate map
		 *
		 * @param	int	N	Size of map (odd number 5-11)
		 */
		void generate(int N);


		/**
		 * Get map size
		 *
		 * @return	int	Map size
		 */
		int getSize();

		/**
		 * Get map in 2 dimensional array
		 *
		 * @return	Block**	Pointer to 2D array of blocks
		 */
		Block** getMap();

		/**
		 * Shift map
		 *
		 * @param	int	direction	0 ... right, 1 ... up, 2 ... left, 3 ... down
		 * @param	int	columnRow	Index of collumn, or row to be shifted
		 */
		void shift(int direction, int columnRow);

		/**
		 * Get free block
		 *
		 * @return	Block*	Free block, which can be used for shifting
		 */
		Block* getFreeBlock();

		/**
		 * Get number of required symbols for win
		 *
		 * @return	int	Count
		 */
		int getMaxSymbolsCount();
};
#endif
