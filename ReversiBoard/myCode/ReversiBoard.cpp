/*
 * ReversiBoard.cpp
 *
 *  Created on: 05-Nov-2024
 *      Author: Dheeraj Swaroop S M
 */

/**
 * @file ReversiBoard.cpp
 * @brief Implements the logic of the Reversi game board.
 *
 * This file contains the methods to manage the board, handle the initial setup,
 * check for valid moves, and flip the discs during gameplay.
 * It uses dynamic memory allocation to store the board state and provides methods
 * to manipulate the board during the game.
 */

#include <iostream>

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

/**
 * @brief Constructor that initializes the game board.
 *
 * This constructor creates a board of the specified rows and columns and
 * initializes it with empty cells ('.').
 *
 * @param rows Number of rows in the board.
 * @param columns Number of columns in the board.
 */
ReversiBoard::ReversiBoard(unsigned int rows, unsigned int columns) :
		rows(rows), columns(columns)
{
	pBoard = new char[rows * columns]; // Allocate memory for the board
	boardClear();
}

/**
 * @brief Destructor that cleans up the dynamically allocated memory.
 */
ReversiBoard::~ReversiBoard()
{
	// TODO Auto-generated destructor stub
	delete[] pBoard;
}

/**
 * @brief Calculates the index of the board cell from row and column.
 *
 * This method is used internally to convert the 2D board position to a 1D index
 * for accessing the board array.
 *
 * @param row Row index of the board.
 * @param column Column index of the board.
 * @return The calculated index in the 1D board array.
 */
unsigned int ReversiBoard::boardCalcIndex(unsigned int row,
		unsigned column) const
{
	return row * columns + column;
}

/**
 * @brief Clears the board by setting all cells to '.'.
 *
 * This method is used to initialize the board by setting all positions to empty cells.
 *
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiBoard::boardClear()
{
	for (unsigned int i = 0; i < rows * columns; i++)
	{
		pBoard[i] = '.';
	}
	return RC_OK;
}

/**
 * @brief Sets a piece ('x' or 'o') on the board at a specified position.
 *
 * This method places the specified coin at the given row and column on the board.
 *
 * @param row Row index to place the coin.
 * @param column Column index to place the coin.
 * @param coin Character representing the coin ('x' or 'o').
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiBoard::boardSet(unsigned int row, unsigned int column, char coin)
{
	unsigned int index = boardCalcIndex(row, column);
	pBoard[index] = coin;

	return RC_OK;
}

/**
 * @brief Initializes the board state with the four starting pieces.
 *
 * This method places the initial pieces ('x' and 'o') at the center of the board
 * to start the game.
 *
 * @param rows Number of rows in the board.
 * @param columns Number of columns in the board.
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiBoard::boardInitialState(unsigned int rows, unsigned int columns)
{
	unsigned int x[] =
	{ (rows / 2) - 1, (rows / 2), (rows / 2) - 1, (rows / 2) };
	unsigned int y[] =
	{ (columns / 2) - 1, (columns / 2) - 1, (columns / 2), (columns / 2) };
	char symbols[] =
	{ 'x', 'o', 'o', 'x' };

	// Calculate the number of elements
	unsigned int numElements = sizeof(x) / sizeof(x[0]);

	// Loop through each initial position and set it on the board
	for (unsigned int i = 0; i < numElements; ++i)
	{
		boardSet(x[i], y[i], symbols[i]);
	}

	return RC_OK;
}

/**
 * @brief Checks if a move by player 'x' is valid.
 *
 * This method checks if placing an 'x' at the specified position would result in a
 * valid move by checking all 8 directions.
 *
 * @param row Row index of the move.
 * @param column Column index of the move.
 * @param coin The coin being placed ('x').
 * @return True if the move is valid, false otherwise.
 */
bool ReversiBoard::boardValidPositionX(unsigned int row, unsigned int column,
		char coin)
{
	// Define offsets for eight directions in clockwise order.
	int xOffsets[] =
	{ -1, -1, 0, 1, 1, 1, 0, -1 };
	int yOffsets[] =
	{ 0, -1, -1, -1, 0, 1, 1, 1 };
	unsigned int numElements = sizeof(xOffsets) / sizeof(xOffsets[0]);

	// Check if any direction leads to a valid move
	for (unsigned int i = 0; i < numElements; i++)
	{
		int x = row + xOffsets[i];
		int y = column + yOffsets[i];

		// Check if there's an 'o' in the current direction immediately adjacent.
		if (x >= 0 && x < rows && y >= 0 && y < columns
				&& pBoard[boardCalcIndex(x, y)] == 'o'
				&& pBoard[boardCalcIndex(row, column)] == '.')
		{
			int currentX = x;
			int currentY = y;

			// Traverse in the current direction.
			while (currentY >= 0 && currentX >= 0 && currentY < columns
					&& currentX < rows)
			{
				char currentCoin = pBoard[boardCalcIndex(currentX, currentY)];

				if (currentCoin == '.')
				{
					break;
				}
				else if (currentCoin == 'x')
				{
					return true;  // Valid move found
				}
				else if (currentCoin == 'o')
				{
					// Move one step further in the current direction
					currentX += xOffsets[i];
					currentY += yOffsets[i];
				}
			}
		}
	}

	cout << "Invalid move. Try again." << endl;
	return false;  // No valid move found
}

/**
 * @brief Checks if a move by player 'o' is valid.
 *
 * This method checks if placing an 'o' at the specified position would result in a
 * valid move by checking all 8 directions.
 *
 * @param row Row index of the move.
 * @param column Column index of the move.
 * @param coin The coin being placed ('o').
 * @return True if the move is valid, false otherwise.
 */
bool ReversiBoard::boardValidPositionO(unsigned int row, unsigned int column,
		char coin)
{
	// Define offsets for eight directions in clockwise order.
	int xOffsets[] =
	{ -1, -1, 0, 1, 1, 1, 0, -1 };
	int yOffsets[] =
	{ 0, -1, -1, -1, 0, 1, 1, 1 };
	unsigned int numElements = sizeof(xOffsets) / sizeof(xOffsets[0]);

	// Check if any direction leads to a valid move
	for (unsigned int i = 0; i < numElements; i++)
	{
		int x = row + xOffsets[i];
		int y = column + yOffsets[i];

		// Check if there's an 'o' in the current direction immediately adjacent.
		if (x >= 0 && x < rows && y >= 0 && y < columns
				&& pBoard[boardCalcIndex(x, y)] == 'x'
				&& pBoard[boardCalcIndex(row, column)] == '.')
		{
			int currentX = x;
			int currentY = y;

			// Traverse in the current direction.
			while (currentY >= 0 && currentX >= 0 && currentY < columns
					&& currentX < rows)
			{
				char currentCoin = pBoard[boardCalcIndex(currentX, currentY)];

				if (currentCoin == '.')
				{
					break;
				}
				else if (currentCoin == 'o')
				{
					return true;  // Valid move found
				}
				else if (currentCoin == 'x')
				{
					// Move one step further in the current direction
					currentX += xOffsets[i];
					currentY += yOffsets[i];
				}
			}
		}
	}

	cout << "Invalid move. Try again." << endl;
	return false;  // No valid move found
}

/**
 * @brief Flips the opponent's pieces ('o' to 'x') after a valid move by player 'x'.
 *
 * This method flips all the opponent's pieces ('o') in the 8 directions after placing
 * an 'x' piece.
 *
 * @param row Row index of the move.
 * @param column Column index of the move.
 * @param coin The coin being placed ('x').
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiBoard::flipOtoX(unsigned int row, unsigned int column, char coin)
{
	// Define offsets for eight directions in clockwise order.
	int xOffsets[] =
	{ -1, -1, 0, 1, 1, 1, 0, -1 };
	int yOffsets[] =
	{ 0, -1, -1, -1, 0, 1, 1, 1 };
	unsigned int numElements = sizeof(xOffsets) / sizeof(xOffsets[0]);

	// Check if any direction leads to a valid move
	for (unsigned int i = 0; i < numElements; i++)
	{
		int x = row + xOffsets[i];
		int y = column + yOffsets[i];

		// Temporary storage for 'o' positions in the current direction
		int storeXcoordinates[8];
		int storeYcoordinates[8];
		unsigned int count = 0; // Track how many 'o' positions we store

		// Traverse in the current direction.
		while (x >= 0 && y >= 0 && y < columns && x < rows)
		{
			char currentCoin = pBoard[boardCalcIndex(x, y)];

			if (currentCoin == '.')
			{
				break;
			}
			else if (currentCoin == 'x')
			{
				for (unsigned int i = 0; i < count; i++)
				{
					int flipX = storeXcoordinates[i];
					int flipY = storeYcoordinates[i];
					pBoard[boardCalcIndex(flipX, flipY)] = 'x';
				}

				break;
			}
			else if (currentCoin == 'o')
			{
				storeXcoordinates[count] = x;
				storeYcoordinates[count] = y;
				count++;

				if (count >= 8)
					break;
			}
			x += xOffsets[i];
			y += yOffsets[i];
		}

	}

	return RC_OK;
}

/**
 * @brief Flips the opponent's pieces ('x' to 'o') after a valid move by player 'o'.
 *
 * This method flips all the opponent's pieces ('x') in the 8 directions after placing
 * an 'o' piece.
 *
 * @param row Row index of the move.
 * @param column Column index of the move.
 * @param coin The coin being placed ('o').
 * @return RC_OK if the operation was successful.
 */
RC_t ReversiBoard::flipXtoO(unsigned int row, unsigned int column, char coin)
{
	// Define offsets for eight directions in clockwise order.
	int xOffsets[] =
	{ -1, -1, 0, 1, 1, 1, 0, -1 };
	int yOffsets[] =
	{ 0, -1, -1, -1, 0, 1, 1, 1 };
	unsigned int numElements = sizeof(xOffsets) / sizeof(xOffsets[0]);

	// Check if any direction leads to a valid move
	for (unsigned int i = 0; i < numElements; i++)
	{
		int x = row + xOffsets[i];
		int y = column + yOffsets[i];

		// Temporary storage for 'o' positions in the current direction
		int storeXcoordinates[8];
		int storeYcoordinates[8];
		unsigned int count = 0; // Track how many 'o' positions we store

		// Traverse in the current direction.
		while (x >= 0 && y >= 0 && y < columns && x < rows)
		{
			char currentCoin = pBoard[boardCalcIndex(x, y)];

			if (currentCoin == '.')
			{
				break;
			}
			else if (currentCoin == 'o')
			{
				for (unsigned int i = 0; i < count; i++)
				{
					int flipX = storeXcoordinates[i];
					int flipY = storeYcoordinates[i];
					pBoard[boardCalcIndex(flipX, flipY)] = 'o';
				}

				break;
			}
			else if (currentCoin == 'x')
			{
				storeXcoordinates[count] = x;
				storeYcoordinates[count] = y;
				count++;

				if (count >= 8)
					break;
			}
			x += xOffsets[i];
			y += yOffsets[i];
		}

	}

	return RC_OK;
}
