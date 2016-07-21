#include <stdio.h>
#include <assert.h>

#include "sudoku_test.h"
#include "sudoku.h"

void testMakeSudokuGrid();
void testDestroySudokuGrid();
void testGetFreeCell();
void testGetCell();
void testSetCell();
void testClearCell();
void testIsFull();
void testIsLegal();
void testHasSolution();


 void test() {
	testMakeSudokuGrid();
	testGetFreeCell();
	testGetCell();
	testSetCell();
	testClearCell();
	testIsFull();
	testIsLegal();
	testHasSolution();
	testDestroySudokuGrid();
	printf("All passed!\n");
}

void testMakeSudokuGrid(){
	printf("testMakeSudokuGrid\n");
	SudokuGrid sg = makeSudokuGrid();
	assert(sg != NULL);
	
}

void testDestroySudokuGrid(){
	printf("testDestroySudokuGrid\n");
	//Si makeSudokuGrid devuelve un puntero...
	SudokuGrid sg = makeSudokuGrid();
	destroySudokuGrid(&sg);
	assert(sg == NULL);
	
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

void testIsFull(){
	printf("testIsFull\n");
	//Full
	SudokuGrid sg = makeSudokuGrid();
	int i = 0;
	while(i < GRID_SIZE){
		clearCell(sg, i);
		i++;
	}
	assert(!isFull(sg));
	//Not full
	i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, MIN_VALUE);
		i++;
	}
	assert(isFull(sg));
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
	SudokuGrid sg = makeSudokuGrid();
	int i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, input[i]);
		i++;
	}
	assert(!isLegal(sg, 0, '1'));
	assert(!isLegal(sg, 0, '2'));
	assert(!isLegal(sg, 0, '3'));
	assert(!isLegal(sg, 0, '4'));
	assert(isLegal(sg, 0, '5'));
	assert(!isLegal(sg, 0, '6'));
	assert(!isLegal(sg, 0, '7'));
	assert(!isLegal(sg, 0, '8'));
	assert(!isLegal(sg, 0, '9'));
	
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
	sg = makeSudokuGrid();
	i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, input2[i]);
		i++;
	}

	assert(!isLegal(sg, 40, '1'));
	assert(!isLegal(sg, 40, '2'));
	assert(!isLegal(sg, 40, '3'));
	assert(!isLegal(sg, 40, '4'));
	assert(!isLegal(sg, 40, '5'));
	assert(isLegal(sg, 40, '6'));
	assert(!isLegal(sg, 40, '7'));
	assert(!isLegal(sg, 40, '8'));
	assert(!isLegal(sg, 40, '9'));

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
	sg = makeSudokuGrid();
	i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, input3[i]);
		i++;
	}

	assert(!isLegal(sg, 60, '1'));
	assert(!isLegal(sg, 60, '2'));
	assert(isLegal(sg, 60, '3'));
	assert(!isLegal(sg, 60, '4'));
	assert(!isLegal(sg, 60, '5'));
	assert(!isLegal(sg, 60, '6'));
	assert(!isLegal(sg, 60, '7'));
	assert(!isLegal(sg, 60, '8'));
	assert(!isLegal(sg, 60, '9'));

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
	sg = makeSudokuGrid();
	i = 0;
	while(i < GRID_SIZE){
		setCell(sg, i, input4[i]);
		i++;
	}

	assert(!isLegal(sg, 77, '1'));
	assert(!isLegal(sg, 77, '2'));
	assert(isLegal(sg, 77, '3'));
	assert(!isLegal(sg, 77, '4'));
	assert(!isLegal(sg, 77, '5'));
	assert(!isLegal(sg, 77, '6'));
	assert(!isLegal(sg, 77, '7'));
	assert(!isLegal(sg, 77, '8'));
	assert(!isLegal(sg, 77, '9'));
}

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

	SudokuGrid sg = makeSudokuGrid();
	int i = 0;
	while(i < GRID_SIZE){
		clearCell(sg, i);
		i++;
	}
	i = 0;
	while(i < GRID_SIZE){
		if(input[i] != BLANK){
			setCell(sg, i, input[i]);
		}
		i++;
	}

	assert(hasSolution(sg));

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

	sg = makeSudokuGrid();
	i = 0;
	while(i < GRID_SIZE){
		clearCell(sg, i);
		i++;
	}
	i = 0;
	while(i < GRID_SIZE){
		if(input2[i] != BLANK){
			setCell(sg, i, input2[i]);
		}
		i++;
	}
	printf("Number free cell: ");
	printf("%d\n", getNumberFreeCell(sg));
	assert(!hasSolution(sg));
	
}