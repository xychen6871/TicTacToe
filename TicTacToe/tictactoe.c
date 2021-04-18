#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TicTacToeBoard {
	char board[3][3];
}

struct TicTacToeBoard board;

void clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}