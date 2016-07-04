#include <stdio.h>

#include "sudoku.h"

#define FALSE 0
#define TRUE  1

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
	int num;
	while(i < GRID_SIZE){

		scanf("%c", &c);
		num = (int)c;
		if((num > 48 && num < 58) || num == 46){//No escaneo la mierda
			if(num == 46){
				c = 46;
			}
			game[i] = c;
			i++;
		}
	}
}

void showGame(sudokuGrid game){
	int i = 0;
	//int fileSpace = 2;
	while(i < GRID_SIZE){


		int fileSize = MAX_VALUE - '0';//No se como funciona este cast pero tira
		if(game[i] != 46){
			printf("%c", game[i]);
		}else{
			printf(".");
		}
		printf(" ");
		if((i+1) % BLOCK_SIZE == 0){
			printf(" ");
		}
		if((i+1) % fileSize  == 0){
			printf("\n");
		}if((i+1) % (fileSize * BLOCK_SIZE) == 0){
			printf("\n");
		}
		i++;
	}
	printf("\n");
}