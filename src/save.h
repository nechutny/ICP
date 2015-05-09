/**
 * Structure for undo and save/load
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 */
#ifndef SAVE_H
#define SAVE_H

typedef struct {

	int blockType[11*11];
	int blockRotation[11*11];
	int blockSymbol[11*11];

	int freeBlockType;
	int freeBlockRotation;
	int freeBlockSymbol;

	int player_on_turn;
	int posunul;
	int symbols;
	int size;

	int playerPosX[4];
	int playerPosY[4];
	int playerScore[4];
	int playerSymbol[4];
	int playerColor[4];

} saveT;

#endif
