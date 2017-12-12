#include <iostream>
#include <vector>
#include <ctime>

#include "playV2.h"

using namespace std;

int main()
{
	cout << "Simulating population..." << endl;
	int NumberOfAi = 700;
	Population population(NumberOfAi);  //Sets up the population
	int NumberOfGenerations = 0;
	int counter = 0;
	while (NumberOfGenerations < 10) {  //Will reproduce 10 times
		for (int i = 0; i < NumberOfAi-1; i ++) {
			for (int j = i+1; j < NumberOfAi;  j ++) {
				play::playAiGame(population.population[i], population.population[j]);  //Plays round robin style
			}
		}
		population.reproduce();
		NumberOfGenerations++;
	}
	int best = population.getFittest();
	int playAgain = 1;
	int first;
	while (playAgain == 1) {
		cout << "Press 1 to go first, 2 to go second. "<< endl;
		cin >> first;
		play::playHumanGame(first, population.population[best]);
		cout << "Press 1 to play again, 2 to exit. " << endl;
		cin >> playAgain;
	}
}
		