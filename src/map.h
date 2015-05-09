/**
 * Map
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
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
		/**
		 * Free allocated memory
		 */
		~Map();

		/**
		 * Save current state for load/unbo
		 *
		 * @param	Player**	players	Pinter to array of players for read their state (position, score, color etc.)
		 * @param	int		onTurn	Number of player on turn
		 * @param	bool		posunul	Did player shift card in this turn?
		 * @param	bool		toFile	Save to file for future load, or just into stack for undo
		 */
		void save(Player** players, int onTurn, bool posunul, bool toFile);


		/**
		 * Load previous state from file/undo buffer
		 *
		 * @param	Player**	players		Pinter to array of players for setting their state (position, score, color etc.)
		 * @param	int*		onTurn		Number of player on turn
		 * @param	bool*		posunul		Did player shift card in this turn?
		 * @param	bool		fromFile	Load from file or just from stack for undo
		 *
		 * @return	saveT*	Pointer to loaded structure with data, or NULL if fail
		 */
		saveT* load(Player** players, int* onTurn, bool* posunul, bool fromFile);

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

		/**
		 * Get number of symbols (12/24)
		 *
		 * @return	int	Number of symbols on map
		 */
		int getSymbols();

		/**
		 * Get number of players on map
		 *
		 * @return	int	Number of players on map
		 */
		int getPlayers();

		/**
		 * Increase counter of players on map
		 */
		void incPlayer();

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
