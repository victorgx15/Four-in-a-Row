#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

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
	char player1 = '+', player2 = 'x';
	Board firBoard = iniBoard(height, width);
	int play = 0; // A variable to determine which player plays
	while (!firBoard.isWinner(player1) && !firBoard.isWinner(player2))
	{
		firBoard.boardDisplayer();
		char player = (play % 2 == 0) ? player1 : player2;
		firBoard.board = firBoard.addDisc(player);
		play++;
	}
	if (firBoard.isWinner(player1))
		cout << "Player 1 is the winner !";
	else
		cout << "Player 2 is the winner !";

	//TODO: deallocate board
	int end;
	cin >> end;
	return 0;
}