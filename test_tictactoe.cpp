#include "TicTacToe.h"
#include <iostream>
#include <cassert>

//Test 1: Test that a newly created game has the correct initial state
void test_initial_state() {
    TicTacToe game;
    //Current player should be 'X'
    assert(game.getCurrentPlayer() == 'X');

    //Move count should be 0
    assert(game.getMoveCount() == 0);

    //All cells should be empty (' ')
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            assert(game.getCell(i,j) == ' ');
        }
    }

    //Game should not be over
    assert(game.isGameOver() == false);

    std::cout << "✓ Initial state test passed\n";
}

//Test 2:Test that making a valid move works correctly
void test_valid_move() {
    //Create a game
    TicTacToe game;

    //Make a move at position (0, 0)
    game.makeMove(0,0);

    //Verify the cell now contains 'X'
    assert(game.getCell(0,0) == 'X');

    //Verify the current player switched to 'O'
    assert(game.getCurrentPlayer() == 'O');

    //Verify move count increased to 1
    assert(game.getMoveCount() == 1);

    std::cout << "✓ Valid move test passed\n";
}

//Test 3: Test that invalid moves are rejected properly:
void test_invalid_moves() {
    TicTacToe game;

    game.makeMove(0,0);

    //Moving to an already occupied cell should return false
    assert(game.makeMove(0,0) == false);

    //Moving to out-of-bounds positions should return false
    assert(game.makeMove(-1,5) == false);

    //Make winning moves, causing game to end
    game.makeMove(0,1);
    game.makeMove(1,0);
    game.makeMove(0,2);
    game.makeMove(2,0);

    //Moving after game is over should return false
    assert(game.makeMove(1,1) == false);
    std::cout << "✓ Invalid moves test passed\n";
}

//Test 4: Test that the game correctly detects a winner in a row
void test_winner_detection_row() {

    //Set up a game where X wins in the top row
    TicTacToe game;
    game.makeMove(0,0);
    game.makeMove(1,0);
    game.makeMove(0,1);
    game.makeMove(1,1);
    game.makeMove(0,2);

    //Verify getWinner() returns 'X'
    assert(game.getWinner() == 'X');

    //Verify isGameOver() returns true
    assert(game.isGameOver() == true);

    std::cout << "✓ Winner detection (row) test passed\n";
}

//Test 5: Test that the game correctly detects a winner in a column
void test_winner_detection_column() {
    //Set up a game where O wins in a column
    TicTacToe game;
    game.makeMove(1,0);
    game.makeMove(0,1); //O col 1
    game.makeMove(0,2);
    game.makeMove(1,1); //O col 1
    game.makeMove(1,2);
    game.makeMove(2,1); //O col 1

    //Verify getWinner() returns 'O'
    assert(game.getWinner() == 'O');

    //Verify isGameOver() returns true
    assert(game.isGameOver() == true);

    std::cout << "✓ Winner detection (column) test passed\n";
}

//Test 6: Test that the game correctly detects a winner in a diagonal
void test_winner_detection_diagonal() {
    //Set up moves that result in a diagonal win
    TicTacToe game;
    game.makeMove(0,0);
    game.makeMove(0,1);
    game.makeMove(1,1);
    game.makeMove(1,2);
    game.makeMove(2,2);

    //Verify the winner is detected correctly
    assert(game.getWinner() == 'X');
    assert(game.isGameOver() == true);

    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

//Test 7: Test the tie game scenario
void test_full_board_no_winner() {
    //Fill the entire board without creating three in a row
    TicTacToe game;
    game.makeMove(0,2);
    game.makeMove(0,0);
    game.makeMove(0,1);

    game.makeMove(1,2);
    game.makeMove(1,0);
    game.makeMove(1,1);

    game.makeMove(2,2);
    game.makeMove(2,0);
    game.makeMove(2,1);

    //Verify getWinner() returns ' ' (no winner)
    assert(game.getWinner() == ' ');
    //Verify isGameOver() returns true (game is over)
    assert(game.isGameOver() == true);
    //Verify isFull() returns true
    assert(game.isFull() == true);

    std::cout << "✓ Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! ✓\n";

    return 0;
}
