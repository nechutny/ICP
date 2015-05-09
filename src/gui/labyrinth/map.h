/**
 * Map
 *
 * @author	Stanislav Nechutný - xnechu01
 */
#ifndef MAP_H
#define MAP_H

class Map;

#include "block.h"
#include "save.h"

class Map
{
	protected:
		Block* _freeBlock;
		Block** _map;
		int _size;
		int _symbols;
		int _players;
		int _last_direction;
		int _last_column;
		std::stack<saveT*>* _save;

	public:
		~Map();

		/**
		 * Save map to file for future load
		 */
		void save(Player** players, int onTurn, bool posunul);

		saveT* load(Player** players, int* onTurn, bool* posunul);

		/**
		 * Generate map
		 *
		 * @param	int	N	Size of map (odd number 5-11)
		 * @param	int	symbols	Number of symbols
		 */
		void generate(int N, int symbols);


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
		 *
		 * @return	bool	True for success, false for fail (reverse sihft)
		 */
		bool shift(int direction, int columnRow);

		/**
		 * Get free block
		 *
		 * @return	Block*	Free block, which can be used for shifting
		 */
		Block* getFreeBlock();

		int getSymbols();
		int getPlayers();
		void incPlayer();

		/**
		 * Get number of required symbols for win
		 *
		 * @return	int	Count
		 */
		int getMaxSymbolsCount();

		/**
		 * Calculate offset for block array
		 *
		 * @param	int	x	Row number from 0
		 * @param	int	y	Column number from 0
		 *
		 * @return	int	Offset, or -1 for out of range
		 */
		int offset(int x, int y);
};
#endif
