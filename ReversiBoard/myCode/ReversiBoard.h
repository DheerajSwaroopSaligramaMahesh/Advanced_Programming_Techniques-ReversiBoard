/*
 * ReversiBoard.h
 *
 *  Created on: 05-Nov-2024
 *      Author: Dheeraj Swaroop S M
 */

/**
 * @file ReversiBoard.h
 * @brief Declares the Reversi board class and its methods.
 *
 * This header file declares the `ReversiBoard` class, which represents the game board for
 * the Reversi (Othello) game. It provides methods for initializing, modifying, and querying
 * the state of the game board, including setting up the initial state, clearing the board,
 * validating moves, and flipping pieces.
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#include "global.h"

/**
 * @class ReversiBoard
 * @brief A class representing the Reversi game board and its operations.
 *
 * The `ReversiBoard` class is responsible for managing the game state of the Reversi game.
 * It provides methods to initialize the board, modify the pieces on the board, validate
 * player moves, and check the status of specific positions on the board.
 */
class ReversiBoard
{
	friend class ReversiConsoleView;
private:
	unsigned short rows;
	unsigned short columns;
	char *pBoard;

	/**
	 * @brief Calculates the index in the board array for a given row and column.
	 *
	 * This private method computes the linear index in the board array for the given
	 * row and column, which is necessary for accessing the board's state efficiently.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @return The calculated index in the board array.
	 */
	unsigned int boardCalcIndex(unsigned int row, unsigned column) const;

public:
	/**
	 * @brief Constructs a ReversiBoard object with specified dimensions.
	 *
	 * This constructor initializes the Reversi board with the specified number of rows
	 * and columns. It also allocates memory for the board's state.
	 *
	 * @param rows The number of rows on the board.
	 * @param columns The number of columns on the board.
	 */
	ReversiBoard(unsigned int rows, unsigned int columns);

	/**
	 * @brief Destroys the ReversiBoard object and deallocates memory.
	 *
	 * The destructor frees any dynamically allocated memory associated with the board.
	 */
	~ReversiBoard();

	/**
	 * @brief Clears the board and resets all positions.
	 *
	 * This method resets the board to its empty state, with no pieces placed on it.
	 *
	 * @return RC_OK if the operation is successful, or an error code otherwise.
	 */
	RC_t boardClear();

	/**
	 * @brief Sets a piece at a specific position on the board.
	 *
	 * This method places a player's piece (either 'X' or 'O') on the specified row and column.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @param coin The coin to place on the board ('X' or 'O').
	 * @return RC_OK if the operation is successful, or an error code otherwise.
	 */
	RC_t boardSet(unsigned int row, unsigned int column, char coin);

	/**
	 * @brief Initializes the board to the standard initial state for Reversi.
	 *
	 * This method sets the board to its standard initial state, with the pieces
	 * placed at the center of the board.
	 *
	 * @param rows The number of rows on the board.
	 * @param columns The number of columns on the board.
	 * @return RC_OK if the operation is successful, or an error code otherwise.
	 */
	RC_t boardInitialState(unsigned int rows, unsigned int columns);

	/**
	 * @brief Validates if a move is valid for player 'X' at the given position.
	 *
	 * This method checks if player 'X' can place a piece at the specified row and column
	 * according to the Reversi rules.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @param coin The coin to validate ('X').
	 * @return true if the move is valid for 'X', false otherwise.
	 */
	bool boardValidPositionX(unsigned int row, unsigned int column, char coin);

	/**
	 * @brief Validates if a move is valid for player 'O' at the given position.
	 *
	 * This method checks if player 'O' can place a piece at the specified row and column
	 * according to the Reversi rules.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @param coin The coin to validate ('O').
	 * @return true if the move is valid for 'O', false otherwise.
	 */
	bool boardValidPositionO(unsigned int row, unsigned int column, char coin);

	/**
	 * @brief Flips opponent's 'O' pieces to 'X' for a valid move.
	 *
	 * If player 'X' places a piece at the given position, this method flips the opponent's
	 * 'O' pieces to 'X' according to Reversi rules.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @param coin The coin to flip ('X').
	 * @return RC_OK if the operation is successful, or an error code otherwise.
	 */
	RC_t flipOtoX(unsigned int row, unsigned int column, char coin);

	/**
	 * @brief Flips opponent's 'X' pieces to 'O' for a valid move.
	 *
	 * If player 'O' places a piece at the given position, this method flips the opponent's
	 * 'X' pieces to 'O' according to Reversi rules.
	 *
	 * @param row The row index (starting from 0).
	 * @param column The column index (starting from 0).
	 * @param coin The coin to flip ('O').
	 * @return RC_OK if the operation is successful, or an error code otherwise.
	 */
	RC_t flipXtoO(unsigned int row, unsigned int column, char coin);
};

#endif /* REVERSIBOARD_H_ */
