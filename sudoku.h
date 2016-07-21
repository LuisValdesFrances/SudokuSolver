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

typedef struct _sudokuGrid *SudokuGrid;

SudokuGrid makeSudokuGrid();
void destroySudokuGrid(SudokuGrid *game);


void readGame(SudokuGrid game);
void showGame(SudokuGrid game);
int hasSolution(SudokuGrid game);
int isFull(SudokuGrid game);
cell getFreeCell(SudokuGrid game);
int isLegal(SudokuGrid game, cell aCell, value aValue);
void setCell(SudokuGrid game, cell aCell, value aValue);
value getCell(SudokuGrid game, cell aCell);
void clearCell(SudokuGrid game, cell aCell);
int getNumberFreeCell(SudokuGrid game);

#endif