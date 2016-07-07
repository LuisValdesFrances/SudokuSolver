#include <stdio.h>

#include "sudoku.h"

int isLegal(sudokuGrid game, cell aCell, value aValue) {
	int legal = TRUE;
	int i = 0;
	int row = aCell / NUM_VALUES;
	int column = aCell % NUM_VALUES;
	int currentFirstCellInRow;
	int firsRowBlock;
	int lastRowBlock;
	printf("column: ");
	printf("%d\n", column);
	
	while(i < GRID_SIZE && legal){
		//Search at the row
		if(i / NUM_VALUES == row){
			if(game[i] == aValue){
				legal = FALSE;
			}
			/*
			printf("%c", game[i]);
			printf(", ");
			*/
		}
		//Search at the column
		currentFirstCellInRow = (i / NUM_VALUES) * (NUM_VALUES);
		if(i == (currentFirstCellInRow + column)){
			if(game[i] == aValue){
				legal = FALSE;
			}
			/*
			printf("%c", game[i]);
			printf(", ");
			*/
		}
		//Search at the block
		firsRowBlock = ((aCell)/BLOCK_SIZE) * BLOCK_SIZE;
		lastRowBlock = firsRowBlock + (BLOCK_SIZE-1);
		
		if(i >= firsRowBlock && i <= lastRowBlock){
			printf("%c", game[i]);
			printf(", ");
		}
		i++;
	}
	return legal;
}
/*
int hasSolution(sudokuGrid game) {
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
*/
int hasSolution(sudokuGrid game) {
	return FALSE;
}

void readGame(sudokuGrid game){
	int i = 0;
	char c;
	while(i < GRID_SIZE){

		scanf("%c", &c);
		if((c >= MIN_VALUE && c <= MAX_VALUE) || c == BLANK){//No escaneo la mierda
			game[i] = c;
			i++;
		}
	}
}

void showGame(sudokuGrid game){
	int i = 0;
	while(i < GRID_SIZE){
		printf("%c", game[i]);
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

int isFull(sudokuGrid game) {
	int i = 0;
	while(i < GRID_SIZE){
		if(game[i] == BLANK){
			return FALSE;
		}
		i++;
	}
	return TRUE;
}

cell getFreeCell(sudokuGrid game) {
	int i = 0;
	while(i < GRID_SIZE){
		if(game[i] == BLANK){
			return i;
		}
		i++;
	}
	return -1;
}

void setCell(sudokuGrid game, cell aCell, value aValue){
	game[aCell] = aValue;
}

value getCell(sudokuGrid game, cell aCell){ 
	return game[aCell];
}

void clearCell(sudokuGrid game, cell aCell){
	game[aCell] = BLANK;
}