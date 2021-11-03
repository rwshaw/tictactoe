#ifndef BOARD_H
#define BOARD_H
#pragma once
	
#include <string>
#include <vector>

class Board  
{
	private:
		std::vector< std::vector < std::string > > board;
	public:
		Board();
		bool play(char player, int row, int column);
		void checkWin(char player, int row, int column);
		void printBoard();
		bool gameState;
};
#endif