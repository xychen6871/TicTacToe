#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe.h"

enum status {ONGOING, DRAW, O_WINS, X_WINS};

struct TicTacToeBoard {
	char board[3][3];
	int open;
	enum status state;
	int rows[3]; // increments by 1 if O is placed, decrements by 1 if X is placed
	int cols[3]; // increments by 1 if O is placed, decrements by 1 if X is placed
	int diag; // increments by 1 if O is placed, decrements by 1 if X is placed
	int antiDiag; // increments by 1 if O is placed, decrements by 1 if X is placed
};

struct TicTacToeBoard Game;

void clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Game.board[i][j] = '*';
		}
	}

	for (int i = 0; i < 3; i++) {
		Game.rows[i] = 0;
		Game.cols[i] = 0;
	}

	Game.diag = 0;
	Game.antiDiag = 0;
	Game.state = ONGOING;
	Game.open = 9;
}

bool placeChar(int x, int y, char c) {
	if (x < 0 || x > 2 || y < 0 || y > 2 || (c != 'O' && c != 'X')) {
		return false; // Invalid position or character given, return false
	}

	if (Game.board[x][y] == '*') {
		Game.board[x][y] = c; // Position is unoccupied, so we can place either a 'X' or 'O' on the position
		Game.open--;

		Game.rows[x] += (c == 'O') ? 1 : -1;
		Game.cols[y] += (c == 'O') ? 1 : -1;
		if (x == y) {
			Game.diag += (c == 'O') ? 1 : -1;
		}
		if (x + y + 1 == 3) {
			Game.antiDiag += (c == 'O') ? 1 : -1;
		}
		return true;
	}
	return false; // Position is occupied return false
}

bool isGameOver() {
	if (HorizontalWin() || VerticalWin() || DiagonalWin()) { // A player has managed to place three of his/her marks on a horizontal, vertical, or diagonal row.
		return true;
	} else if (Game.open <= 0) { // No open spots left but neither player has won the game -> draw
		Game.state = DRAW;
		return true;
	}
	return false;
}

bool HorizontalWin() {
	for (int i = 0; i < 3; i++) {
		if (abs(Game.rows[i]) == 3) {
			Game.state = (Game.rows[i] > 0) ? O_WINS : X_WINS;
			return true;
		}
	}
	return false;
}

bool VerticalWin() {
	for (int i = 0; i < 3; i++) {
		if (abs(Game.cols[i]) == 3) {
			Game.state = (Game.cols[i] > 0) ? O_WINS : X_WINS;
			return true;
		}
	}
	return false;
}

bool DiagonalWin() {
	if (abs(Game.diag) == 3) {
		Game.state = (Game.diag > 0) ? O_WINS : X_WINS;
		return true;
	} else if (abs(Game.antiDiag) == 3) {
		Game.state = (Game.antiDiag > 0) ? O_WINS : X_WINS;
		return true;
	}
	return false;
}

void printBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", Game.board[i][j]);
		}
		printf("\n");
	}
}

void Play() {
	printf("Welcome to the game of Tic-Tac-Toe. Player 1 will use the token O, while Player 2 will use the token X.\n");
	clearBoard();
	int turn = 0; // even = Player 1's turn, odd = Player 2's turn
	while (!isGameOver()) {
		printBoard();
		if (turn % 2 == 0) { // Player 1's turn
			printf("Player 1, it is your turn. Please enter a valid coordinate (r, c).\n");
			
		} else { // Player 2's turn
			printf("Player 2, it is your turn. Please enter a valid coordinate (r, c).\n");
			
		}
		int x;
		int y;
		int r;
		r = scanf("%d %d", &x, &y);
		if (r != 2) {
			break;
		}
		
		
		char c = (turn % 2 == 0) ? 'O' : 'X';
		if (placeChar(x,y,c)) {
			turn++;
			turn %= 2;
		} else {
			printf("This is not a valid move. Please try again\n");
		}
	}
	printBoard();
	if (Game.state == DRAW) {
		printf("DRAW\n");
	} else if (Game.state == O_WINS) {
		printf("PLAYER 1 WINS\n");
	} else if (Game.state == X_WINS) {
		printf("PLAYER 2 WINS\n");
	} else {
		printf("ABORTED\n");
	}
}


int main() {
	Play();
	return 0;

}