#include <iostream>
#include "board.hpp"


int main()
{
    std::cout << "Welcome to tic-tac-toe amigo!" << std::endl;
    Board board;
    char player = 'X';

    board.printBoard();
    // play until there's a winner or the board is full / gameState switches to false
    while (board.gameState) {
        int row;
        int column;
        bool played = false;

        std::cout << player << "'s turn!" << std::endl << "Row: ";
        // continue until successful play
        while (!played) {
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> column;
            played = board.play(player, row-1, column-1);
        }
        
        // switch players
        player = (player == 'X')? player = 'O' : player = 'X';
        board.printBoard();

    }

    // board.printBoard();
    // int pos[2] = {1,2};
    // board.play('X', pos);
    // board.printBoard();
    // pos[0] = 2;
    // board.play('X', pos);
    // board.printBoard();
    // pos[0] = 0;
    // board.play('X', pos);
    // board.printBoard();

}