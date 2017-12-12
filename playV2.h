#include "population.h"

namespace play
{
	void switchCurrPlayer(int& currPlayer);
	void playAiGame(Learner& AiOne, Learner& AiTwo);
	void recieveHumanMove(int currPlayer, Board& board);
	void playHumanGame(int humanPlayer, Learner Ai);
	void displayWinner(int humanPlayer, int victor, Board board);
};
		