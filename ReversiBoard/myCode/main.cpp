// Standard (system) header files
#include <iostream>
#include <cstdlib>

// Add more standard header files as required

using namespace std;

// Add your project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

// Main program
int main()
{
	cout << "ReversiBoard started." << endl << endl;

	unsigned int rows, columns;

	cout << "Please enter the size (x,y) of the game: " << endl;
	cin >> rows >> columns;

	ReversiBoard r1(rows, columns);

	ReversiConsoleView rv(&r1);

	r1.boardInitialState(rows, columns);
	rv.boardPrint(&r1);

	char c;
	unsigned int x, y;

	while (true)
	{
		while (true)
		{
			cout << "Player 1 (x): Enter a position (x, y) and a coin: ";
			cin >> x >> y >> c;
			cout << endl;

			// Check if the entered position and coin create a valid move
			if (c == 'x')
			{
				if (r1.boardValidPositionX(x, y, c))
				{
					// If valid, set the move on the board
					r1.boardSet(x, y, c);
					r1.flipOtoX(x, y, c);
					rv.boardPrint(&r1);
					break;
				}
				else
				{
					// If invalid, prompt the user again without updating the board
					cout << "Invalid move. Enter a new position and coin."
							<< endl;
				}
			}
			else
			{
				cout << "Invalid character! Only 'x' is allowed" << endl;
			}
		}

		while (true)
		{

			cout << "Player 2 (o): Enter a position (x, y) and a coin: ";
			cin >> x >> y >> c;
			cout << endl;

			// Check if the entered position and coin create a valid move
			if (c == 'o')
			{
				if (r1.boardValidPositionO(x, y, c))
				{
					// If valid, set the move on the board
					r1.boardSet(x, y, c);
					r1.flipXtoO(x, y, c);
					rv.boardPrint(&r1);
					break;
				}
				else
				{
					// If invalid, prompt the user again without updating the board
					cout << "Invalid move. Enter a new position and coin."
							<< endl;
				}
			}
			else
			{
				cout << "Invalid character! Only 'o' is allowed" << endl;
			}
		}
	}

	return 0;
}
