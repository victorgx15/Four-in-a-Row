#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Board iniBoard(int height, int width)
{
	Board result;
	result.height = height;
	result.width = width;
	char **board;
	board = new char *[height];
	for (int i = 0; i < height; i++)
	{
		board[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			board[i][j] = '_';
		}
	}
	result.board = board;
	return result;
}

void Board::boardDisplayer()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) cout << board[i][j] << " ";
		cout << endl;
	}
}

bool Board::isWinner(char player)
// Check if "player" is the winner of the game
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j < width - 3)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j] == player)
					return true;	//If there's 4 in a row horizontally
			}
			if (i < height - 3)
			{
				if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i][j] == player)
					return true;	//If there's 4 in a row vertically
			}
			if (j < width - 3 && i < height - 3)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i][j] == player)
					return true;	//If there's 4 in a row diagonally from northwest to southeast
			}
			if (j < width - 3 && i >= 3)
			{
				if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i][j] == player)
					return true;	//If there's 4 in a row diagonally from southwest to northeast
			}
		}

	}
	return false;
}

char** Board::addDisc(char player)
// It's the board with the player's disc added to the chosen column
{
	bool filled = true;
	int column = -1;
	while (filled || column < 0 || column > width - 1)
	{
		cout << "Player " << player << ", choose your column:" << endl;
		cin >> column;
		column--;	//The player pick a column, substracted by 1 for index
		if (board[0][column] == '_') filled = false;
	}
	int i = height - 1;
	while (board[i][column] != '_') { i--; }
	board[i][column] = player;
	return  board;
}