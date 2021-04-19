#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TICTACTOE
#define TICTACTOE
/*
clearBoard(): clear the TicTacToe board by setting all values of the 3x3 board to '*'
*/
void clearBoard();

/*
placeChar(): places a character on the board
@x: row number of the board, must be between 0 and 2
@y: column number of the board, must be between 0 and 2
@c: character must either be 'O' or 'X'

This function returns false if either x, y, or c are invalid or if the position is already occupied. Otherwise, the function returns true.
*/
bool placeChar(int x, int y, char c);

#endif