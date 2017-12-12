#include "playV2.h"
#include <iostream>

using namespace std;

void play::switchCurrPlayer(int& currPlayer) {
	if (currPlayer == 1) {
		currPlayer = 2;
	}
	else {
		currPlayer = 1;
	}
}
void play::playAiGame(Learner& AiOne, Learner& AiTwo) {
	Board board;
	int currPlayer = 1;
	AiOne.changePlayer(1);
	AiTwo.changePlayer(2);
	while (board.CheckVictory() == 3) {
		if (AiOne.getPlayer() == currPlayer) {
			AiOne.getMove(board);
		}
		else {
			AiTwo.getMove(board);
		}
		switchCurrPlayer(currPlayer);
	}
	int victor = board.CheckVictory();
	AiOne.updateScore(victor);
	AiTwo.updateScore(victor);
}

void play::playHumanGame(int humanPlayer, Learner Ai) {
	Board board;
	int currPlayer = 1;
	if (humanPlayer == 1) {
		Ai.changePlayer(2);
	}
	else {
		Ai.changePlayer(1);
	}
	while (board.CheckVictory() == 3) {
		if (currPlayer == humanPlayer) {
			recieveHumanMove(currPlayer, board);
		}
		else {
			Ai.getMove(board);
		}
		switchCurrPlayer(currPlayer);
	}
	displayWinner(humanPlayer, board.CheckVictory(), board);
}

void play::recieveHumanMove(int currPlayer, Board& board) {
	int row, column;
	board.PrintBoard();
	cout << "Enter the row number: " << endl;
	cin >> row;
	cout << "Enter the column number: " << endl;
	cin >> column;
	board.SetVal(currPlayer, row-1, column-1);
}
			
void play::displayWinner(int humanPlayer, int victor, Board board) {
	board.PrintBoard();
	if (victor == humanPlayer) {
		cout << "The player has won." << endl;
	}
	else if (victor == 0) {
		cout << "The game is a tie. " << endl;
	}
	else {
		cout << "The AI has won. " << endl;
	}
}