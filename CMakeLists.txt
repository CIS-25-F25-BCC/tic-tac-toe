cmake_minimum_required(VERSION 3.10)
project(TicTacToeTest)

set(CMAKE_CXX_STANDARD 11)

# Enable testing
enable_testing()

# Add the TicTacToe library
add_library(tictactoe TicTacToe.cpp
        TicTacToe.cpp)

# Add main executable
add_executable(tictactoe_game main.cpp
        TicTacToe.cpp)
target_link_libraries(tictactoe_game tictactoe)

# Add test executable (students will implement the tests)
add_executable(test_tictactoe test_tictactoe.cpp
        TicTacToe.cpp)
target_link_libraries(test_tictactoe tictactoe)

# Register tests with CTest
add_test(NAME TicTacToeTests COMMAND test_tictactoe)
