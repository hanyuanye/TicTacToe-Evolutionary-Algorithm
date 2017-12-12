#include "BoardV2.h"
#include <vector>

//Evolutionary Algorithm:
//Start with population of 1000
//Population has randomized weights of (w0, w1, w2, w3, w4, w5) expressed as vector
//Population plays round robin with each other
//Score is recorded as wins - losses
//Take 10% of population = 100, find 2 most fit, reproduce

//Reproduction Algorithm: 
//Sum fitness * weighting vector / average fitness to get weighting vector
//Children have 5% chance to mutate.

//Mutation Algorithm: 
//Change a random weighting by +- 0.2

//After number of reproduced children hits 300, delete weakest 300 from original 1000 
//and add in new children

//Repeat process until the population is fit enough. (Maybe test against MinMaxAi?) 

/* Required functions:

Constructor to randomly assign weights
Function to check the values of board state
Function to return total score based on each possible move from board state
Function to return wins/loss score
(Loop) until 300:
Function to randomly pick 10% of population and find 2 most fit, rand()%1000
Function to reproduce using weighted vectors of 2 fit and score
Function to mutate children by choosing a random weight and changing it marginally

Function to replace each of the bottom 30% of AI with new chilren

Function to test if successful (maybe unneccessary)

*/
class Learner
{
	public:
		void getMove(Board& board);
		float checkPossibleMoves(Board& board, int i, int j);
		float getTotalScore(Board board);
		void updateScore(int victor);
		int getPlayer();
		void changePlayer(int newGamePlayer);
		int getFitness();
		void resetFitness();
		void mutate();
		float getWeight(int weight);
		void changeWeight(int weightToChange, float weight);
		
	//Constructor
	Learner();
		std::vector<float> weights;
		int player;
		int fitness;   //Total wins - total losses
	struct possibleMoves{
		float score;
		int x;
		int y;
		possibleMoves(int x, int y, int score): x(x), y(y), score(score){}
	};
};