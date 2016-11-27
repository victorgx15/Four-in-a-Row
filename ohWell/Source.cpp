#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char **boardGenerator(int, int);
void boardDisplayer(char**, int, int);
bool isWinner(char, char**, int, int);
char **addDisc(char, char**, int, int);

int main()
{
	int width = 0, height = 0;
	cout << "Choose the size of your connect-4 board" << endl;
	while (width < 4)
	{
		cout << "width: ";
		cin >> width;
	}
	while (height < 4)
	{
		cout << "height: ";
		cin >> height;
	}
	char player1 = '+', player2 = 'x', **board = boardGenerator(height, width);
	int play = 0; // A variable to determine which player plays
	while (!isWinner(player1, board, height, width) && !isWinner(player2, board, height, width))
	{
		boardDisplayer(board, height, width);
		char player = (play % 2 == 0) ? player1 : player2;
		board = addDisc(player, board, height, width);
		play++;
	}
	if (isWinner(player1, board, height, width))
		cout << "Player 1 is the winner !";
	else
		cout << "Player 2 is the winner !";
	int end;
	cin >> end;
	return 0;
}

char **boardGenerator(int height, int width)
// A function to create the Connect-4 board
{
	char **board;
	board = new char *[height];
	for (int i = 0; i < height; i++)
	{
		board[i] = new char[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[i][j] = '_';
		}
	}
	return board;
}

void boardDisplayer(char **board, int height, int width)
// A function to display the state of the board
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isWinner(char player, char** board, int height, int width)
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