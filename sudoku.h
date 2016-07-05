#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#define FALSE 0
#define TRUE  1

#define BLANK '.'
#define MIN_VALUE '1'
#define MAX_VALUE '9'

#define BLOCK_SIZE 3
#define NUM_VALUES (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUES * NUM_VALUES)
#define MAX_CELL (GRID_SIZE - 1)


typedef char value;
typedef int cell;
typedef value sudokuGrid[GRID_SIZE];


void readGame(sudokuGrid game);
void showGame(sudokuGrid game);
int hasSolution(sudokuGrid game);
int isFull(sudokuGrid game);
cell getFreeCell(sudokuGrid game);
int isLegal(sudokuGrid game, cell aCell, value aValue);
void setCell(sudokuGrid game, cell aCell, value aValue);
value getCell(sudokuGrid game, cell aCell);
void clearCell(sudokuGrid game, cell aCell);

#endif