//Weight 0 is rows with 1x in a row and the rest open
//Weight 1 is rows with 2x in a row and the rest open
//Weight 2 is rows with 3x in a row.
//Weight 3 is rows with 1o in a row and the rest open
//Weight 4 is rows with 2o in a row and the rest open

#include "AiLearner.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

Learner::Learner() {
	weights.resize(5, rand()%100);
	fitness = 0;
	player = 1;
}

void Learner::getMove(Board& board) {
	vector<possibleMoves> allPossibleMoves;
	bool empty = false;
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			if (board.intAt(i, j) == 0) {
				float moveScore = checkPossibleMoves(board, i, j);
				possibleMoves Move(i, j, moveScore);
				allPossibleMoves.push_back(Move);
			} else {
				empty = true;
			}
		}
	}
	if (empty) {
		board.SetVal(1, 1, 1);
	}
	int bestMove = 0;
	int maxScore = -100000;
	for (int i = 0, ilen = allPossibleMoves.size(); i < ilen; i ++) {
		if (allPossibleMoves[i].score > maxScore) {
			maxScore = allPossibleMoves[i].score;
			bestMove = i;
		}
	}
	board.SetVal(player, allPossibleMoves[bestMove].x, allPossibleMoves[bestMove].y);
}

float Learner::checkPossibleMoves(Board& board, int i, int j) {
	board.SetVal(player, i, j);
	board.BoardStateEvaluate(player);
	board.SetVal(0, i, j);
	float TotalScore = getTotalScore(board);
	return TotalScore;
}
				
float Learner::getTotalScore(Board board) {
	vector <float> score = board.getBoardScore();
	float TotalScore = 0;
	if (player == 1) {
		for (int i = 0; i < 3; i ++) {
			TotalScore += weights[i] * score[i];
		}
		TotalScore -= (weights[3]*score[3] + weights[4]*score[4]);
	} else {
		for (int j = 0; j < 3; j ++) {
			TotalScore += weights[j]*score[j+3];
		}
		TotalScore -= (weights[3]*score[0] + weights[4] * score[1]);
	}
	return TotalScore;
}

void Learner::updateScore(int victor) {
	if (player == victor) {
		++fitness;
	} else if (victor == 0) {
		fitness += 0.5;
	} else {
		--fitness;
	}
}

void Learner::mutate() {
	int weightToChange = rand() % weights.size();
	int sign;
	if (rand() % 2 == 0) {
		sign = -1;
	} else {
		sign = 1;
	}
	float magnitudeOfChange = rand() / RAND_MAX * 5 * sign;
	weights[weightToChange] += magnitudeOfChange;
}

int Learner::getPlayer() {
	return player;
}

void Learner::changePlayer(int newGamePlayer) {
	player = newGamePlayer;
}

int Learner::getFitness() {
	return fitness;
}

void Learner::resetFitness() {
	fitness = 0;
}

float Learner::getWeight(int weight) {
	return weights[weight];
}

void Learner::changeWeight(int weightToChange, float weight) {
	weights[weightToChange] = weight;
}
	