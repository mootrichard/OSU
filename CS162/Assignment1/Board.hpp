#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <string>

class Board
{
	private:
		static const unsigned int ROW = 21;
		static const unsigned int COLUMN = 41;
		int gameArea[ROW][COLUMN];
		int mirrorArea[ROW][COLUMN];
	public:
		Board();
		Board(unsigned int live);
		void displayBoard();
		void copyBoard(int array1[ROW][COLUMN], int array2[ROW][COLUMN]);
};

#endif // !BOARD_HPP
