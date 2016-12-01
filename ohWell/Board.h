#pragma once

struct Board
{
	int height, width;
	char** board;

	void boardDisplayer();
	bool isWinner(char);
	char **addDisc(char);
};


Board iniBoard(int, int);
