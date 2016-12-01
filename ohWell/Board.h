#pragma once

char **addDisc(char, char**, int, int);

struct Board
{
	int height, width;
	char** board;
};


Board iniBoard(int, int);
void boardDisplay(Board);
bool isWinner(char, Board);
char **addDisc(char, Board);
