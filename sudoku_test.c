#include <stdio.h>
#include <assert.h>

#include "sudoku_test.h"
#include "sudoku.h"

void testGetFreeCell();
void testGetCell();
void testSetCell();
void testClearCell();
void testIsFull();
void testIsLegal();
void testHasSolution();
void testDestroySudokuGrid();

 
void test() {
	testGetFreeCell();
	testGetCell();
	testSetCell();
	testClearCell();
	//testIsFull();
	//testIsLegal();
	//testHasSolution();
	testDestroySudokuGrid();
	printf("All passed!\n");
}

void testGetFreeCell(){
	printf("testGetFreeCell\n");
	SudokuGrid sg = makeSudokuGrid();
	cell free = GRID_SIZE/2;
	int i = 0;
	while(i < GRID_SIZE){
		if(i != free){
			setCell(sg, i, MIN_VALUE);
		}else{
			setCell(sg, i, BLANK);
		}
		i++;
	}
	assert(getFreeCell(sg) == free);
}

void testGetCell(){
	printf("testGetCell\n");
	SudokuGrid sg = makeSudokuGrid();
	cell aCell = GRID_SIZE/2;
	value aValue = GRID_SIZE/4;
	setCell(sg, aCell, aValue);
	assert(getCell(sg, aCell) == aValue);
}

void testSetCell(){
	printf("testSetCell\n");
	SudokuGrid sg = makeSudokuGrid();
	cell aCell = GRID_SIZE/2;
	value aValue = GRID_SIZE/4;
	setCell(sg, aCell, aValue);
	assert(getCell(sg, aCell) == aValue);
}

void testClearCell(){
	printf("testClearCell\n");
	SudokuGrid sg = makeSudokuGrid();
	int i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, MIN_VALUE);
		i++;
	}
	cell aCell = GRID_SIZE/2;
	clearCell(sg, aCell);
	assert(getCell(sg, aCell) == BLANK);
}

void testDestroySudokuGrid(){
	printf("testDestroySudokuGrid\n");
	SudokuGrid sg = makeSudokuGrid();
	//assert(sg != NULL);
	//destroySudokuGrid(sg);
	//assert(sg == NULL);
}

/*
void testIsFull(){
	printf("testIsFull\n");
	//Full
	SudokuGrid sg = makeSudokuGrid();
	int i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, MIN_VALUE);
		i++;
	}
	assert(isFull(sg));
	//Not full
	cell aCell = GRID_SIZE/2;
	setCell(sg, aCell, BLANK);
	assert(!isFull(sg));
}


void testIsLegal(){
	printf("testIsLegal\n");

	value input[] = {
		'.','9','6', '7','3','1', '8','2','4',
		'7','8','2', '5','9','4', '1','3','6',
		'3','4','1', '2','8','6', '7','9','5',

		'6','2','9', '3','1','5', '4','8','7',
		'4','7','3', '8','6','9', '2','5','1',
		'1','5','8', '4','2','7', '9','6','3',

		'2','1','5', '6','4','8', '3','7','9',
		'9','3','7', '1','5','2', '6','4','8',
		'8','6','4', '9','7','3', '5','1','2'
	};
	assert(!isLegal(input, 0, '1'));
	assert(!isLegal(input, 0, '2'));
	assert(!isLegal(input, 0, '3'));
	assert(!isLegal(input, 0, '4'));
	assert(isLegal(input, 0, '5'));
	assert(!isLegal(input, 0, '6'));
	assert(!isLegal(input, 0, '7'));
	assert(!isLegal(input, 0, '8'));
	assert(!isLegal(input, 0, '9'));
	
	value input2[] = {
		'5','9','6', '7','3','1', '8','2','4',
		'7','8','2', '5','9','4', '1','3','6',
		'3','4','1', '2','8','6', '7','9','5',

		'6','2','9', '3','1','5', '4','8','7',
		'4','7','3', '8','.','9', '2','5','1',
		'1','5','8', '4','2','7', '9','6','3',

		'2','1','5', '6','4','8', '3','7','9',
		'9','3','7', '1','5','2', '6','4','8',
		'8','6','4', '9','7','3', '5','1','2'
	};
	assert(!isLegal(input2, 40, '1'));
	assert(!isLegal(input2, 40, '2'));
	assert(!isLegal(input2, 40, '3'));
	assert(!isLegal(input2, 40, '4'));
	assert(!isLegal(input2, 40, '5'));
	assert(isLegal(input2, 40, '6'));
	assert(!isLegal(input2, 40, '7'));
	assert(!isLegal(input2, 40, '8'));
	assert(!isLegal(input2, 40, '9'));

	value input3[] = {
		'5','9','6', '7','3','1', '8','2','4',
		'7','8','2', '5','9','4', '1','3','6',
		'3','4','1', '2','8','6', '7','9','5',

		'6','2','9', '3','1','5', '4','8','7',
		'4','7','3', '8','6','9', '2','5','1',
		'1','5','8', '4','2','7', '9','6','3',

		'2','1','5', '6','4','8', '.','7','9',
		'9','3','7', '1','5','2', '6','4','8',
		'8','6','4', '9','7','3', '5','1','2'
	};
	assert(!isLegal(input3, 60, '1'));
	assert(!isLegal(input3, 60, '2'));
	assert(isLegal(input3, 60, '3'));
	assert(!isLegal(input3, 60, '4'));
	assert(!isLegal(input3, 60, '5'));
	assert(!isLegal(input3, 60, '6'));
	assert(!isLegal(input3, 60, '7'));
	assert(!isLegal(input3, 60, '8'));
	assert(!isLegal(input3, 60, '9'));

	value input4[] = {
		'5','9','6', '7','3','1', '8','2','4',
		'7','8','2', '5','9','4', '1','3','6',
		'3','4','1', '2','8','6', '7','9','5',

		'6','2','9', '3','1','5', '4','8','7',
		'4','7','3', '8','6','9', '2','5','1',
		'1','5','8', '4','2','7', '9','6','3',

		'2','1','5', '6','4','8', '3','7','9',
		'9','3','7', '1','5','2', '6','4','8',
		'8','6','4', '9','7','.', '5','1','2'
	};
	assert(!isLegal(input4, 77, '1'));
	assert(!isLegal(input4, 77, '2'));
	assert(isLegal(input4, 77, '3'));
	assert(!isLegal(input4, 77, '4'));
	assert(!isLegal(input4, 77, '5'));
	assert(!isLegal(input4, 77, '6'));
	assert(!isLegal(input4, 77, '7'));
	assert(!isLegal(input4, 77, '8'));
	assert(!isLegal(input4, 77, '9'));
}
/*
void testHasSolution(){
	printf("testHasSolution\n");
	
	value input[] = {
		'.','9','.', '.','.','.', '8','.','4',
		'.','8','.', '5','.','.', '.','3','.',
		'3','.','.', '.','.','6', '7','.','.',

		'.','.','.', '.','.','5', '.','.','7',
		'.','.','3', '.','.','.', '2','.','.',
		'1','.','.', '4','.','.', '.','.','.',

		'.','.','5', '6','.','.', '.','.','9',
		'.','3','.', '.','.','2', '.','4','.',
		'8','.','4', '.','.','.', '.','1','.'
	};
	assert(hasSolution(input));
	
	value input2[] = {
		'2','9','.', '.','.','.', '8','.','4',
		'.','8','.', '5','.','.', '.','3','.',
		'3','.','.', '.','.','6', '7','.','.',

		'.','.','.', '.','.','5', '.','.','7',
		'.','.','3', '.','.','.', '2','.','.',
		'1','.','.', '4','.','.', '.','.','.',

		'.','.','5', '6','.','.', '.','.','9',
		'.','3','.', '.','.','2', '.','4','.',
		'8','.','4', '.','.','.', '.','1','.'
	};
	assert(!hasSolution(input2));
	
}

*/