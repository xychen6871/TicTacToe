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
};

struct TicTacToeBoard Game;

void clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Game.board[i][j] = '*';
		}
	}
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
		return true;
	}
	return false; // Position is occupied return false
}

bool isGameOver() {
	if (HorizontalWin() || VerticalWin() || DiagonalWin()) { // A player has managed to place three of his/her marks on a horizontal, vertical, or diagonal row.
		return true;
	}

	if (Game.open <= 0) { // No open spots left but neither player has won the game -> draw
		Game.state = DRAW;
		return true;
	}
	return false;
}

bool HorizontalWin() {
	if ((Game.board[0][0] == Game.board[0][1]) && (Game.board[0][1] == Game.board[0][2]) && (Game.board[0][0] == 'X' || Game.board[0][0] == 'O')) { // 3 X's or 3 O's in first row
		if (Game.board[0][0] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else if ((Game.board[1][0] == Game.board[1][1]) && (Game.board[1][1] == Game.board[1][2]) && (Game.board[1][0] == 'X' || Game.board[1][0] == 'O')) { // 3 X's or 3 O's in 2nd row
		if (Game.board[1][0] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else if ((Game.board[2][0] == Game.board[2][1]) && (Game.board[2][1] == Game.board[2][2]) && (Game.board[2][0] == 'X' || Game.board[2][0] == 'O')) { // 3 X's or 3 O's in 3rd row
		if (Game.board[2][0] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else {
		return false;
	}
}

bool VerticalWin() {
	if ((Game.board[0][0] == Game.board[1][0]) && (Game.board[1][0] == Game.board[2][0]) && (Game.board[0][0] == 'X' || Game.board[0][0] == 'O')) { // 3 X's or 3 O's in first column
		if (Game.board[0][0] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else if ((Game.board[0][1] == Game.board[1][1]) && (Game.board[1][1] == Game.board[2][1]) && (Game.board[0][1] == 'X' || Game.board[0][1] == 'O')) { // 3 X's or 3 O's in 2nd column
		if (Game.board[0][1] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else if ((Game.board[0][2] == Game.board[1][2]) && (Game.board[1][2] == Game.board[2][2]) && (Game.board[0][2] == 'X' || Game.board[0][2] == 'O')) { // 3 X's or 3 O's in 3rd column
		if (Game.board[0][2] == 'O') {
			Game.state = O_WINS;
		} else {
			Game.state = X_WINS;
		}
		return true;
	} else {
		return false;
	}
}

bool DiagonalWin() {
	bool diag1 = (Game.board[0][0] == Game.board[1][1]) && (Game.board[1][1] == Game.board[2][2]);
	bool diag2 = (Game.board[0][2] == Game.board[1][1]) && (Game.board[1][1] == Game.board[2][0]);
	if (diag1 || diag2) {
		if (Game.board[1][1] == 'O') {
			Game.state = O_WINS;
			return true;
		} else if (Game.board[1][1] == 'X') {
			Game.state = X_WINS;
			return true;
		}
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
			printf("Player 1, it is your turn. Please enter a valid coordinate.\n");
			
		} else { // Player 2's turn
			printf("Player 2, it is your turn. Please enter a valid coordinate.\n");
			
		}
		int x;
		int y;
		scanf("%d %d", &x, &y);
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
	} else {
		printf("PLAYER 2 WINS\n");
	}
}


int main() {
	Play();
	return 0;

}