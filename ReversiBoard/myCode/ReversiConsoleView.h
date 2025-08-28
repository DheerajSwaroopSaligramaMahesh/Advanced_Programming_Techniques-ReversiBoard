/*
 * ReversiConsoleView.h
 *
 *  Created on: 05-Nov-2024
 *      Author: Dheeraj Swaroop S M
 */

/**
 * @file ReversiConsoleView.h
 * @brief Declares the console view for displaying the Reversi board.
 *
 * This header file declares the `ReversiConsoleView` class, which is responsible for
 * rendering the game board to the console. It provides the `boardPrint` method for displaying
 * the board state.
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "global.h"
#include "ReversiBoard.h"

class ReversiConsoleView
{
private:
	ReversiBoard *rv;

public:
	/**
	 * @brief Constructs a ReversiConsoleView object with a pointer to the ReversiBoard.
	 *
	 * This constructor initializes the `ReversiConsoleView` object with the provided
	 * pointer to the `ReversiBoard` object, which will be used for rendering the board.
	 *
	 * @param rv A pointer to the ReversiBoard object containing the game state.
	 */
	ReversiConsoleView(ReversiBoard *rv) :
			rv(rv)
	{
	}

	/**
	 * @brief Prints the current state of the board to the console.
	 *
	 * This method prints the current game board, including row and column numbers,
	 * and the state of each cell (either an empty space or a player's piece).
	 *
	 * @param rv Pointer to the ReversiBoard object to be printed.
	 * @return RC_OK if the operation was successful.
	 */
	RC_t boardPrint(ReversiBoard *rv) const;
};

#endif /* REVERSICONSOLEVIEW_H_ */
