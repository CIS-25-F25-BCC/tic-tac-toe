# Tic-Tac-Toe: Object-Oriented Style (C++)

This is an **object-oriented programming** implementation of Tic-Tac-Toe in C++, demonstrating:

- **Encapsulation**: State hidden inside the `TicTacToe` class
- **Mutation**: Methods modify internal state (`makeMove()` changes the board)
- **Object lifecycle**: Constructor initializes, methods operate, destructor cleans up

## OOP vs Functional Comparison

| Aspect | OOP Version (this) | Functional Version |
|--------|-------------------|-------------------|
| State | Hidden inside object | Explicit, passed as argument |
| Mutation | `game.makeMove()` modifies object | `makeMove()` returns new board |
| Undo | Need to store history manually | Just use the previous board |
| Interface | Methods on object | Free functions |

**See also**: [Functional Version](https://github.com/CIS-25-F25-BCC/tic-tac-toe-functional) for comparison

## Building

```bash
mkdir build && cd build
cmake ..
make
```

## Running

```bash
./tictactoe
```

## Running Tests

```bash
ctest --verbose
```

## Key OOP Concepts Demonstrated

### 1. Encapsulation
```cpp
class TicTacToe {
private:
    char board[3][3];      // Hidden state
    char currentPlayer;     // Hidden state
public:
    bool makeMove(int row, int col);  // Public interface
};
```

### 2. State Mutation
```cpp
TicTacToe game;
game.makeMove(0, 0);  // Modifies game's internal state
game.makeMove(1, 1);  // More modification
// Can't easily access old states!
```

### 3. Query Methods (Side-Effect Free)
```cpp
// These don't modify state - easier to test
char getWinner() const;
bool isGameOver() const;
bool isFull() const;
```

## Course Information

**CIS-25: Programming Using C++**
Fall 2025, Berkeley City College

GitHub Organization: [CIS-25-F25-BCC](https://github.com/CIS-25-F25-BCC)
