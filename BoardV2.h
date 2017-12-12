#include <vector>
#pragma once
class Board 
{
public:
	void BoardStateEvaluate(int player);
	void BoardStateCountReset();
	void BoardStateCountAssign(int valueAtCoords);
	void BoardStateCountScore();
	std::vector<float> getBoardScore();
	char valAt(int x, int y);
	int intAt(int x, int y);
	void SetVal(int player, int x, int y);
	void PrintBoard();
	int CheckVictory();
	void clear();
	//Constructor
	Board();
private:
	int board[3][3];
	int xcount;
	int ocount;
	int emptycount;
	std::vector<float> score;
};
