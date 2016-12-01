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

void boardDisplay(Board b)
{
	for (int i = 0; i < b.height; i++)
	{
		for (int j = 0; j < b.width; j++)
		{
			cout << b.board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isWinner(char player, Board b)
// Check if "player" is the winner of the game
{
	for (int i = 0; i < b.height; i++)
	{
		for (int j = 0; j < b.width; j++)
		{
			if (j < b.width - 3)
			{
				if (b.board[i][j] == b.board[i][j + 1] && b.board[i][j + 1] == b.board[i][j + 2] && b.board[i][j + 2] == b.board[i][j + 3] && b.board[i][j] == player)
					return true;	//If there's 4 in a row horizontally
			}
			if (i < b.height - 3)
			{
				if (b.board[i][j] == b.board[i + 1][j] && b.board[i + 1][j] == b.board[i + 2][j] && b.board[i + 2][j] == b.board[i + 3][j] && b.board[i][j] == player)
					return true;	//If there's 4 in a row vertically
			}
			if (j < b.width - 3 && i < b.height - 3)
			{
				if (b.board[i][j] == b.board[i + 1][j + 1] && b.board[i + 1][j + 1] == b.board[i + 2][j + 2] && b.board[i + 2][j + 2] == b.board[i + 3][j + 3] && b.board[i][j] == player)
					return true;	//If there's 4 in a row diagonally from northwest to southeast
			}
			if (j < b.width - 3 && i >= 3)
			{
				if (b.board[i][j] == b.board[i - 1][j + 1] && b.board[i - 1][j + 1] == b.board[i - 2][j + 2] && b.board[i - 2][j + 2] == b.board[i - 3][j + 3] && b.board[i][j] == player)
					return true;	//If there's 4 in a row diagonally from southwest to northeast
			}
		}

	}
	return false;
}

char **addDisc(char player, char **board, int height, int width)
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
	return board;
}

char **addDisc(char player, Board b)
// It's the board with the player's disc added to the chosen column
{
	bool filled = true;
	int column = -1;
	while (filled || column < 0 || column > b.width - 1)
	{
		cout << "Player " << player << ", choose your column:" << endl;
		cin >> column;
		column--;	//The player pick a column, substracted by 1 for index
		if (b.board[0][column] == '_') filled = false;
	}
	int i = b.height - 1;
	while (b.board[i][column] != '_') { i--; }
	b.board[i][column] = player;
	return  b.board;
}