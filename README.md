# ReversiBoard Game
This repository provides a basic console-based implementation of the classic board game Reversi (also known as Othello). The game is played on an 8x8 grid where players alternate turns placing pieces, aiming to capture their opponent’s pieces by enclosing them between their own. More details about the game can be found here: https://en.wikipedia.org/wiki/Reversi
. You can also try playing it online at: https://cardgames.io/reversi/

# File Descriptions
# 1. ReversiBoard.h, ReversiBoard.cpp
- Define and implement the ReversiBoard class, which represents the game board state.
- Provide functions to query and modify the state of individual cells on the board.
- Contain the core game logic for validating moves and updating the board accordingly.

# 2. ReversiConsoleView.h, ReversiConsoleView.cpp
- Define and implement the ReversiConsoleView class, which handles displaying the game board in the console.
- Use the ReversiBoard class to retrieve the board state and generate the corresponding console output.

# 3. main.cpp
- Contains the main entry point for the Reversi game.
- Initializes the game board and console view.
- Runs the main game loop where players alternate turns until no valid moves remain for either player.

# How to Play
1. Compile the provided source files with a C++ compiler:
2. Run the generated executable.
3. Follow the on-screen prompts to make moves on the board. The game continues until neither player has any valid moves left.
