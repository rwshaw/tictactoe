#include <iostream>
#include <vector>
#include "board.hpp"  
	
Board::Board()
{
    board.resize(3, std::vector<std::string>(3));
    gameState = true;
}

void Board::printBoard() {
    // Board printer

    std::cout << "-------------" << std::endl;
    for (const auto &row: this->board) {
        std::cout << "|";
        for (const auto &elem: row) {
            std::cout << " ";
            if (elem.empty()) {
                std::cout << " ";
            } else {
                std::cout << elem;
            }
            std::cout << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

bool Board::play(char player, int row, int column) {
    // check if move is legal, return false if not
    if (this->board[row][column].compare(" ")) {
        this->board[row][column] = player;
        this->checkWin(player, row, column);
        return true;
    } else {
        std::cout << "Can't play here, try again!" << std::endl;
        return false;
    }
}
	
void Board::checkWin(char player, int row, int column) {
    // check for win state and if the board is full
    // check rows (we only need to check the row or column that has been played)
    if (board[row][0] == board[row][1] && board[row][2] == board[row][1]) {
        std::cout << player << " wins!" << std::endl;

        this->gameState = false;
    }
    // columns
    if (board[0][column] == board[1][column] && board[2][column] == board[1][column] ) {
        std::cout << player << " wins!" << std::endl;
        this->gameState = false;
    }
    // diagonals (don't check if the middle is empty)
    if (!board[1][1].compare(" ")) {
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
    for (const auto &row: this->board) {
        for (const auto &elem: row) {
            if (elem.empty()) {
                freeSpace = true;
            }
        }
    }
    if (freeSpace == false) {
        std::cout << std::endl << "It's a draw!" << std::endl;
        this->gameState = false;
    }
}

