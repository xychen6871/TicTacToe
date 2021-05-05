# TicTacToe

This is just a basic game of Tic-Tac-Toe. Two human players are required to play this game. 

## The Rules

Player 1 uses the token 'O' while Player uses the token 'X'. The board will initially look like this when the players start playing the game:
...
...
...
Note that valid positions on the board are always 0-indexed. Player 1 will always start first. The game will print the current state board for every turn. The current player would enter two numbers that represent a position on the board. If the position is out of bounds or occupied by a token ('O' or 'X'), the player must try again. If the player attempts to enter an invalid input, the game will be aborted. Otherwise, the game would place the token on the board and let the other player take his or her turn. The players keep playing until one players places three tokens in a horizontal, vertical, or diagonal row or there are no more moves to be made. The first player who does so wins the game. If neither player managed to win by the time the board is completely filled, the game will end in a draw. 
