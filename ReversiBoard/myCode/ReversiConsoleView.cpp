/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 05-Nov-2024
 *      Author: Dheeraj Swaroop S M
 */

/**
 * @file ReversiConsoleView.cpp
 * @brief Implements the console view to print the game board.
 *
 * This file contains the methods that render the Reversi game board to the console.
 * It provides the `boardPrint` method to display the board state.
 */

#include <iostream>

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

/**
 * @brief Prints the current state of the board to the console.
 *
 * This method prints the current state of the game board, showing the row and column indices
 * along with the board contents for visual representation in the console.
 *
 * @param rv Pointer to the ReversiBoard object containing the board state.
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiConsoleView::boardPrint(ReversiBoard *rv) const
{
	cout << "  ";
	for (unsigned int r = 0; r < rv->rows; r++)
	{
		cout << r << " ";
	}
	cout << endl;

	for (unsigned int c = 0; c < rv->columns; c++)
	{
		cout << c << " ";
		for (unsigned int r = 0; r < rv->rows; r++)
		{
			cout << rv->pBoard[rv->boardCalcIndex(r, c)] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return RC_OK;
}
