#include <stdio.h>
#include <stdlib.h>

#include "sudoku.h"
#include "sudoku_test.h"

int main(int argc, char *argv[]) {

	test();
	SudokuGrid game = makeSudokuGrid();
	readGame(game);
	
	printf("Input:\n");
	showGame(game);
	printf("Number free cell: ");
	printf("%d\n", getNumberFreeCell(game));

	printf("\n");
	if (hasSolution(game)) {
		printf("Solution:\n");
		showGame(game);
	} else {
		printf("There's no solution\n");
	}

	destroySudokuGrid(&game);

	return EXIT_SUCCESS;
}


