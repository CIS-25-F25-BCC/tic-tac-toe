#include "TicTacToe.h"
#include <sstream>

TicTacToe::TicTacToe() : currentPlayer('X'), moveCount(0) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

char TicTacToe::getCell(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return '\0';  // Invalid position
    }
    return board[row][col];
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

bool TicTacToe::isFull() const {
    return moveCount == 9;
}

char TicTacToe::getWinner() const {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';  // No winner
}

bool TicTacToe::isGameOver() const {
    return getWinner() != ' ' || isFull();
}

int TicTacToe::getMoveCount() const {
    return moveCount;
}

bool TicTacToe::makeMove(int row, int col) {

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {

        return false;

    }

    if (board[row][col] != ' ') {

        return false;

    }

    board[row][col] = currentPlayer;

    moveCount++;

    // AI feature: track move history

    moveHistory.push_back({row, col, currentPlayer});

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    return true;

}


void TicTacToe::reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
    moveCount = 0;
}

std::string TicTacToe::toString() const {
    std::ostringstream oss;
    for (int i = 0; i < 3; i++) {
        oss << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) {
            oss << "---|---|---\n";
        }
    }
    return oss.str();
}
