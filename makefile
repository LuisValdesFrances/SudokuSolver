main: main.c sudoku.h sudoku.c sudoku_test.h sudoku_test.c
	gcc -Wall -Werror -o main main.c sudoku.c sudoku_test.c


debug: main.c sudoku.h sudoku.c sudoku_test.h sudoku_test.c
	gcc -Wall -Werror -o debug main.c sudoku.c sudoku_test.c -g


.PHONY:clean
clean:
	rm main