#include <stdio.h>
#include <stdlib.h>

#include "sudoku.h"
#include "sudoku_test.h"

int main(int argc, char *argv[]) {

	test();
	sudokuGrid game;
	readGame(game);
	printf("readGame ok\n");
	
	printf("Input:\n");
	showGame(game);
	printf("showGame ok\n");

	printf("\n");
	if (hasSolution(game)) {
		printf("Solution:\n");
		showGame(game);
	} else {
		printf("There's no solution\n");
	}


	return EXIT_SUCCESS;
}


