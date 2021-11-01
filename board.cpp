#include <iostream>
#include "board.hpp"  
	
Board::Board()
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    gameState = true;
}

void Board::printBoard() {
    // Board printer
    std::cout << "-------------" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "|";
        for(int j = 0; j < 3; j++) {
            std::cout << " " << this->board[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

bool Board::play(char player, int row, int column) {
    // check if move is legal, return false if not
    if (this->board[row][column] == ' ') {
        this->board[row][column] = player;
        this->checkWin(player, row, column);
        return true;
    } else {
        std::cout << "Can't play here, try again!" << std::endl;
        return false;
    }
}
	
void Board::checkWin(char player, int row, int column) {
    // check for win state
    // rows
    if (board[row][0] == board[row][1] && board[row][2] == board[row][1]) {
        std::cout << player << " wins!" << std::endl;

        this->gameState = false;
    }
    //columns
    if (board[0][column] == board[1][column] && board[2][column] == board[1][column] ) {
        std::cout << player << " wins!" << std::endl;
        this->gameState = false;
    }
    //diagonals
    if (board[1][1] != ' ') {
        if (board[0][0] == board[1][1] && board[2][2]  == board[1][1]) {
            std::cout << player << " wins!" << std::endl;
            this->gameState = false;
        } else if (board[0][2] == board[1][1] && board[2][0] == board[1][1]) {
            std::cout << player << " wins!" << std::endl;
            this->gameState = false;
        }
    }
    // check to see if the board is full
    bool freeSpace = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->board[i][j] == ' ') {
                freeSpace = true;
            }
        }
    }
    if (freeSpace == false) {
        std::cout << std::endl << "It's a draw!" << std::endl;
        this->gameState = false;
    }
}

