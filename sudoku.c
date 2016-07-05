#include <stdio.h>

#include "sudoku.h"


int isFull(sudokuGrid game) {return 0;}
cell getFreeCell(sudokuGrid game) {return 0;}
int isLegal(sudokuGrid game, cell aCell, value aValue) {return 0;}
void setCell(sudokuGrid game, cell aCell, value aValue){}
value getCell(sudokuGrid game, cell aCell){ return '0';}
void clearCell(sudokuGrid game, cell aCell){}

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
	printf("\n");
}