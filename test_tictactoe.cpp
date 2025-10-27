#include "TicTacToe.h"
#include <iostream>
#include <cassert>

// Students will implement these tests in the lab

void test_initial_state() {
    // TODO: Students implement this
TicTacToe game;
	if (game.getCurrentPlayer() == 'X' &&
		game.getMoveCount() == 0 &&
		game.getCell('\0', '\0') &&
		game.getWinner() == 'X' || game.getWinner() == 'O') {
    std::cout << "✓ Initial state test passed\n";}
}

void test_valid_move() {
    // TODO: Students implement this
TicTacToe game;
game.makeMove(0, 0);

    if (game.getCell(0, 0) == 'X' &&
        game.getCurrentPlayer() == 'O' &&
        game.getMoveCount() == 1) {
    std::cout << "✓ Valid move test passed\n";}

}

void test_invalid_moves() {
    // TODO: Students implement this
TicTacToe game;

game.makeMove(1, 0);
bool Valid = game.makeMove(1, 0);
bool move = game.makeMove(-1, 5);
bool move1 = game.makeMove(3, 5);

game.makeMove(0, 0);
game.makeMove(1, 1);
game.makeMove(0, 1);
game.makeMove(2, 2);
game.makeMove(0, 2);
bool Valid2 = game.makeMove(2, 0);

	if (!Valid &&
		!move &&
		!move1 &&
		!Valid2){
    std::cout << "✓ Invalid moves test passed\n";}
}

void test_winner_detection_row() {
    // TODO: Students implement this
TicTacToe game;
game.makeMove(0, 0);
game.makeMove(1, 1);
game.makeMove(0, 1);
game.makeMove(2, 2);
game.makeMove(0, 2);

if (game.getWinner() == 'X' &&
	game.isGameOver() == true){
    std::cout << "✓ Winner detection (row) test passed\n";}
}

void test_winner_detection_column() {
    // TODO: Students implement this
TicTacToe game;
game.makeMove(0, 0);
game.makeMove(1, 0);
game.makeMove(2, 0);
game.makeMove(1, 1);
game.makeMove(2, 2);
game.makeMove(1, 2);

if (game.getWinner() == 'O' &&
	game.isGameOver() == true){
    std::cout << "✓ Winner detection (column) test passed\n";}
}

void test_winner_detection_diagonal() {
    // TODO: Students implement this
TicTacToe game;
game.makeMove(0, 0);
game.makeMove(1, 0);
game.makeMove(1, 1);
game.makeMove(0, 1);
game.makeMove(2, 2);
game.makeMove(1, 2);

if (game.getWinner() == 'X'){
    std::cout << "✓ Winner detection (diagonal) test passed\n";}
}

void test_full_board_no_winner() {
    // TODO: Students implement this
TicTacToe game;
game.makeMove(0, 0);
game.makeMove(1, 0);
game.makeMove(2, 0);
game.makeMove(0, 1);
game.makeMove(0, 2);
game.makeMove(1, 1);
game.makeMove(1, 2);
game.makeMove(2, 2);
game.makeMove(2, 1);

if (game.getWinner() == ' ' &&
    game.isGameOver() == true &&
	game.isFull() == true){
    std::cout << "✓ Full board no winner test passed\n";}
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
    std::cout << "\nNote: These are placeholder tests.\n";
    std::cout << "Students need to implement the actual test logic.\n";

    return 0;
}
