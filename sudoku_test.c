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
	//testHasSolution();
	//testIsLegal();
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
	
}