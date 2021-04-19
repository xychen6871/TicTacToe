#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe.h"

struct TicTacToeBoard {
	char board[3][3];
	int open;
};

struct TicTacToeBoard Game;

void clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Game.board[i][j] = '*';
		}
	}
	Game.open = 9;
}

bool placeChar(int x, int y, char c) {
	if (x < 0 || x > 2 || y < 0 || y > 2 || (c != 'O' && c != 'X')) {
		return false; // Invalid position or character given, return false
	}

	if (board[x][y] == '*') {
		Game.board[x][y] = c; // Position is unoccupied, so we can place either a 'X' or 'O' on the position
		Game.open--;
		return true;
	}
	return false; // Position is occupied return false
}

