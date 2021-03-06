#include <iostream>
#include <vector>
#include "board.hpp"


int main()
{
    std::cout << "Welcome to tic-tac-toe amigo!" << std::endl;

    //print board
    Board board;

    // X's start first
    char player = 'X';

    board.printBoard();
    // play until there's a winner or the board is full / gameState switches to false
    while (board.gameState) {
        int row;
        int column;
        bool played = false;

        std::cout << player << "'s turn!" << std::endl;
        // continue until successful play
        while (!played) {
            // get row input and check for type and range
            std::cout << "Row: ";
            std::cin >> row;   
            while (std::cin.fail() || row > 3 || row < 1) {
                std::cout << "Error, please enter an row from 1 to 3:" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> row;    
            }
            // get column input and check for type and range
            std::cout << "Column: ";
            std::cin >> column;  
            while (std::cin.fail() || column > 3 || column < 1) {
                std::cout << "Error, please enter a column from 1 to 3:" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> column;    
            }
            // try to play the move
            played = board.play(player, row-1, column-1);
        }
        
        // switch players
        player = (player == 'X')? player = 'O' : player = 'X';
        // print board
        board.printBoard();
    }
}
