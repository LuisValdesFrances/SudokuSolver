#include <stdio.h>

#include "sudoku.h"

int isLegal(sudokuGrid game, cell aCell, value aValue) {
	int legal = TRUE;
	int i = 0;
	int cellRow = aCell / NUM_VALUES;
	int cellColumn = aCell % NUM_VALUES;
	int currentFirstCellInRow;
	int currentRow;
	int currentColumn;
	int firsRowBlock;
	int lastRowBlock;
	int headBlock = -1;
	int endBlock = -1;
	int headBlockRow;
	int headBlockColumn;
	int headRow;
	
	while(i < GRID_SIZE && legal){
		//Search at the row
		if(i / NUM_VALUES == cellRow){
			if(game[i] == aValue){
				legal = FALSE;
			}
		}
		//Search at the column
		currentFirstCellInRow = (i / NUM_VALUES) * (NUM_VALUES);
		if(i == (currentFirstCellInRow + cellColumn)){
			if(game[i] == aValue){
				legal = FALSE;
			}
		}
		//Search at the block
		currentRow = i / NUM_VALUES;
		currentColumn = i % NUM_VALUES;
		if(headBlock == -1){
			//i is in a head
			if(currentRow%BLOCK_SIZE == 0 && currentColumn%BLOCK_SIZE == 0){
				headBlock = i;
				endBlock = (NUM_VALUES * (currentRow+2)) + (currentColumn+2);
				headRow = currentRow;
				headBlockRow = headBlock / NUM_VALUES;
				headBlockColumn = headBlock % NUM_VALUES;

				//i is outside head
				if(aCell < headBlock || aCell > endBlock 
					|| cellRow < headBlockRow || cellRow > headBlockRow + (BLOCK_SIZE-1)
					|| cellColumn < headBlockColumn || cellColumn > headBlockColumn + (BLOCK_SIZE-1)){
					headBlock = -1;
				}
			}
		}
		if(headBlock != -1 && i <= endBlock){

			firsRowBlock = headBlock + (NUM_VALUES * (currentRow - headRow));
			lastRowBlock = firsRowBlock + (BLOCK_SIZE-1);
		
			if(i >= firsRowBlock && i <= lastRowBlock){
				if(game[i] == aValue){
					legal = FALSE;
				}
			}
		}
		//headBlock = pow(firsRowBlock, currentCell) + currentColumn;
		i++;
	}
	return legal;
}

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
	int full = TRUE;
	while(i < GRID_SIZE && full == TRUE){
		if(game[i] == BLANK){
			full = FALSE;
		}else{
			i++;
		}
	}
	return full;
}

cell getFreeCell(sudokuGrid game) {
	int i = 0;
	int cell = -1;
	while(i < GRID_SIZE && cell == -1){
		if(game[i] == BLANK){
			cell =  i;
		}else{
			i++;
		}
	}
	return cell;
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