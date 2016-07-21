#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sudoku.h"

struct _sudokuGrid {
	value grid[GRID_SIZE];
	int free_count; 
};


SudokuGrid makeSudokuGrid() {

	SudokuGrid game = malloc(sizeof(struct _sudokuGrid));
	assert(game != NULL);
	return game;
}

void destroySudokuGrid(SudokuGrid *game){
	free(*game);
	*game = NULL;
}


static int isLegalInRow(SudokuGrid game, cell aCell, value aValue) {
	int result = TRUE;
	int i = 0;
	cell start_row_index = (aCell/NUM_VALUES) * NUM_VALUES;
	while (i < NUM_VALUES && result) {
		cell currentCell = start_row_index + i;
		if (currentCell != aCell && game->grid[currentCell] == aValue) {
			result = FALSE;
		}
		i++;
	}
	return result;
}

static int isLegalInColumn(SudokuGrid game, cell aCell, value aValue) {
	int result = TRUE;
	int i = 0;
	cell start_col_index = aCell % NUM_VALUES;
	while (i < NUM_VALUES && result) {
		cell currentCell = start_col_index + i*NUM_VALUES;
		if (currentCell != aCell && game->grid[currentCell] == aValue) {
			result = FALSE;
		}
		i++;
	}
	return result;
}

static int isLegalInBlock(SudokuGrid game, cell aCell, value aValue) {



	/*
		// 00 //  // 01 //  // 02 //

		00 01 02  03 04 05  06 07 08
	00	09 10 11  12 13 14  15 16 17
		18 19 20  21 22 23  24 25 26

		27 28 29  30 31 32  33 34 35
	01	36 37 38  39 40 41  42 43 44
		45 46 47  48 49 50  51 52 53

		54 55 56  57 58 59  60 61 62
	02	63 64 65  66 67 68  69 70 71
		72 73 74  75 76 77  78 79 80

	//*/

	int result = TRUE;

	int block_column = (aCell/BLOCK_SIZE) % BLOCK_SIZE;
	int block_row    = (aCell/(BLOCK_SIZE * NUM_VALUES));

	cell start_block_index = block_column * BLOCK_SIZE + 
	                         block_row    * (BLOCK_SIZE * NUM_VALUES);

	int x, y ;
	y = 0;
	while(y < BLOCK_SIZE && result) {
		x = 0;
		while(x < BLOCK_SIZE && result) {
			cell currentCell = start_block_index + x + y * NUM_VALUES;
			if (currentCell != aCell && game->grid[currentCell] == aValue) {
				result = FALSE;
			}
			x++;
		}
		y++;
	}
	return result;
}

int isLegal(SudokuGrid game, cell aCell, value aValue) {

	// is not in the block
	// is not in the row
	// is not in the column

	return isLegalInRow(game, aCell, aValue) &&
	       isLegalInColumn(game, aCell, aValue) &&
	       isLegalInBlock(game, aCell, aValue);
}

int hasSolution(SudokuGrid game) {
	int solved;
	if (isFull(game)){
		solved = TRUE;
	}
	else {
		solved = FALSE;
		value trialValue = MIN_VALUE;
		cell candidateCell = getFreeCell(game);

		while(!solved && trialValue <= MAX_VALUE) {
			if(isLegal(game, candidateCell, trialValue)) {
				
				setCell(game, candidateCell, trialValue);

				if (hasSolution(game)) {
					solved = TRUE;
				}
				else {
					clearCell(game, candidateCell);
				}
			}
			trialValue++;
		}
	}
	return solved;
}

void readGame(SudokuGrid game){
	game->free_count = 0;
	int i = 0;
	char c;
	while(i < GRID_SIZE){

		scanf("%c", &c);
		if((c >= MIN_VALUE && c <= MAX_VALUE) || c == BLANK){//No escaneo la mierda
			game->grid[i] = c;
			if (c == BLANK) {
				game->free_count++;
			}

			i++;
		}
	}
}

void showGame(SudokuGrid game){
	int i = 0;
	while(i < GRID_SIZE){
		printf("%c", game->grid[i]);
		printf(" ");
		if((i+1) % BLOCK_SIZE == 0){
			printf(" ");
		}
		if((i+1) % NUM_VALUES  == 0){
			printf("\n");
		}
		if((i+1) % (NUM_VALUES * BLOCK_SIZE) == 0){
			printf("\n");
		}
		i++;
	}
}

int isFull(SudokuGrid game) {
	return game->free_count == 0;
}

cell getFreeCell(SudokuGrid game) {
	int i = 0;
	int cell = -1;
	while(i < GRID_SIZE && cell == -1){
		if(game->grid[i] == BLANK){
			cell =  i;
		}
		i++;
	}
	return cell;
}

void setCell(SudokuGrid game, cell aCell, value aValue){
	game->grid[aCell] = aValue;
	game->free_count--;
}

value getCell(SudokuGrid game, cell aCell){ 
	return game->grid[aCell];
}

void clearCell(SudokuGrid game, cell aCell){
	game->grid[aCell] = BLANK;
	game->free_count++;
}

int getNumberFreeCell(SudokuGrid game){ 
	return game->free_count;
}