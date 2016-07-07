#include <stdio.h>
#include <assert.h>

#include "sudoku_test.h"
#include "sudoku.h"

void testGetFreeCell();
void testGetCell();
void testSetCell();
void testClearCell();
void testIsFull();
void testHasSolution();
void testIsLegal();
 
void test() {
	testGetFreeCell();
	testGetCell();
	testSetCell();
	testClearCell();
	testIsFull();
	testIsLegal();
	//testHasSolution();
	printf("All passed!\n");
}

void testGetFreeCell(){
	printf("testGetFreeCell\n");
	value input[GRID_SIZE];
	cell free = GRID_SIZE/2;
	int i = 0;
	while(i < GRID_SIZE){
		if(i != free){
			input[i]=MIN_VALUE;
		}else{
			input[i]=BLANK;
		}
		i++;
	}
	assert(getFreeCell(input) == free);
}

void testGetCell(){
	printf("testGetCell\n");
	value input[GRID_SIZE];
	cell get = GRID_SIZE/2;
	value val = GRID_SIZE/4;
	int i = 0;
	while(i < GRID_SIZE){
		if(i != get){
			input[i]=MIN_VALUE;
		}else{
			input[i]=val;
		}
		i++;
	}
	assert(getCell(input, get) == val);
}

void testSetCell(){
	printf("testSetCell\n");
	value input[GRID_SIZE];
	cell set = GRID_SIZE/2;
	value val = GRID_SIZE/4;
	setCell(input, set, val);
	assert(input[set] == val);
}

void testClearCell(){
	printf("testClearCell\n");
	value input[GRID_SIZE];
	int i = 0;
	while(i < GRID_SIZE){
		input[i]=MIN_VALUE;
		i++;
	}
	cell clear = GRID_SIZE/2;
	clearCell(input, clear);
	assert(input[clear] == BLANK);
}

void testIsFull(){
	printf("testIsFull\n");
	//Full
	value input[GRID_SIZE];
	int i = 0;
	while(i < GRID_SIZE){
		input[i]=MIN_VALUE;
		i++;
	}
	assert(isFull(input));
	//Not full
	i = 0;
	while(i < GRID_SIZE){
		if(i == GRID_SIZE/2){
			input[i]=BLANK;
		}else{
			input[i]=MIN_VALUE;
		}
		i++;
	}
	assert(!isFull(input));
}

void testIsLegal(){
	printf("testIsLegal\n");
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
	assert(isLegal(input, 0, '5'));
	assert(!isLegal(input, 0, '8'));
	assert(isLegal(input, 11, '2'));
	assert(!isLegal(input, 11, '4'));
	assert(isLegal(input, 4, '1'));
	assert(!isLegal(input, 4, '4'));
	assert(isLegal(input, 4, '3'));
	assert(!isLegal(input, 4, '6'));
	assert(isLegal(input, 40, '0'));
	assert(!isLegal(input, 40, '5'));
	assert(isLegal(input, 40, '8'));
	assert(!isLegal(input, 40, '3'));
	assert(isLegal(input, 80, '2'));
	assert(!isLegal(input, 80, '4'));
	assert(isLegal(input, 80, '3'));
	assert(!isLegal(input, 80, '8'));
	assert(!isLegal(input, 80, '7'));
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
	assert(isLegal(input2, 40, '6'));
	assert(!isLegal(input2, 40, '1'));
	assert(!isLegal(input2, 40, '2'));
	assert(!isLegal(input2, 40, '3'));
	assert(!isLegal(input2, 40, '4'));
	assert(!isLegal(input2, 40, '5'));
	assert(!isLegal(input2, 40, '7'));
	assert(!isLegal(input2, 40, '8'));
	assert(!isLegal(input2, 40, '9'));

	
}

void testHasSolution(){

}

