#include "Board.hpp"

Board::Board()
{
	for (unsigned int r = 0; r < ROW; r++)
	{
		for (unsigned int c = 0; c < COLUMN; c++)
		{
			gameArea[r][c] = 0;
		};
	};
}

Board::Board(unsigned int live)
{
	for (unsigned int r = 0; r < ROW; r++)
	{
		for (unsigned int c = 0; c < COLUMN; c++)
		{
			gameArea[r][c] = live;
		};
	};
}

void Board::displayBoard()
{
	std::cout << std::string(42, '#') << "\n";
	for (unsigned int r = 1; r<=ROW-1; r++)
	{
		std::cout << "#";
		for (unsigned int c = 1; c<=COLUMN-1; c++)
		{
			if (gameArea[r][c] == 1)
			{
				std::cout << "O";
			}
			else
			{
				std::cout << " ";
			}
		};
		std::cout << "#" << "\n";
	};
	std::cout << std::string(42, '#') << "\n";
}

void Board::copyBoard(int array1[ROW][COLUMN], int array2[ROW][COLUMN])
{
	for (unsigned int r = 0; r < ROW; r++)
	{
		for (unsigned int c = 0; c < COLUMN; c++)
		{
			array1[r][c] = array2[r][c];
		};
	};
}