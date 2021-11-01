#ifndef BOARD_H
#define BOARD_H
#pragma once
	
#include <string>

class Board  
{
	private:
		char board[3][3];
	public:
		Board();
		bool play(char player, int row, int column);
		void checkWin(char player, int row, int column);
		void printBoard();
		bool gameState;
};
#endif