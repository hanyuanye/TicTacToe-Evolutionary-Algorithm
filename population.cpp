#include "population.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Population::Population(int NumberOfAi) {
	population.resize(NumberOfAi);
	for (int i = 0; i < NumberOfAi; i ++) {
		Learner Ai;
		population[i] = Ai;
	}
	BestTwo.resize(2);
}

void Population::reproduce() {
	sampleSize = population.size() / 10;
	for (int i = 0; i < 250; i ++) {
		chooseSample();
		chooseBestTwo();
		sample.clear();
		Learner child;
		createChild(child);
		if ((rand() % 100) % 5 == 0) {
			child.mutate();
		}
		children.push_back(child);  //New vector to tempoarily store children
	}
	cout << 2 << endl;
	for (int i = 0, ilen = population.size(); i < ilen; i++) {
		population[i].resetFitness();
	}
	for (int i = 0, ilen = children.size(); i < ilen; i ++) {
		population.push_back(children[i]);  //Population shuold be size 700 here
	}
	BestTwo.erase(BestTwo.begin(), BestTwo.begin()+2);  //Temp vector to store top 2 fitness in sample
	BestTwo.resize(2);
	children.clear();
}

void Population::chooseSample() {
	for (int i = 0; i < sampleSize; i++) {
		int index = rand() % population.size();
		sample.push_back(population[index]);
	}
}

void Population::chooseBestTwo() {
	int best, secondBest;
	int minimum = 0;
	if (sample[0].getFitness() > sample[1].getFitness()) {
		best = 0;
		secondBest = 1;
	} else {
		best = 1;
		secondBest = 0;
	}
	for (int i = 2, ilen = sample.size(); i < ilen; i ++) {
		if (sample[i].getFitness() > sample[secondBest].getFitness()) {
			if (sample[i].getFitness() > sample[best].getFitness()) {
				secondBest = best;
				best = i;
			} else {
				secondBest = i;
			}
		}
		if (sample[i].getFitness() < sample[minimum].getFitness()) {
			minimum = i;
		}
	}
	population.erase(population.begin()+minimum);
	BestTwo[0] = sample[best];
	BestTwo[1] = sample[secondBest];
}

void Population::createChild(Learner &child) {
	float averageFitness = (BestTwo[0].getFitness() + BestTwo[1].getFitness()) / 2;
	float w0 = (BestTwo[0].getWeight(0) * BestTwo[0].getFitness() + BestTwo[1].getWeight(0) * BestTwo[1].getFitness()) / averageFitness;
	float w1 = (BestTwo[0].getWeight(1) * BestTwo[0].getFitness() + BestTwo[1].getWeight(1) * BestTwo[1].getFitness()) / averageFitness;		
	float w2 = (BestTwo[0].getWeight(2) * BestTwo[0].getFitness() + BestTwo[1].getWeight(2) * BestTwo[1].getFitness()) / averageFitness;
	float w3 = (BestTwo[0].getWeight(3) * BestTwo[0].getFitness() + BestTwo[1].getWeight(3) * BestTwo[1].getFitness()) / averageFitness;
	float w4 = (BestTwo[0].getWeight(4) * BestTwo[0].getFitness() + BestTwo[1].getWeight(4) * BestTwo[1].getFitness()) / averageFitness;
	child.changeWeight(0, w0);
	child.changeWeight(1, w1);
	child.changeWeight(2, w2);
	child.changeWeight(3, w3);
	child.changeWeight(4, w4);
}
	
int Population::getFittest() {
	int best = 0;
	for (int i = 1, ilen = population.size(); i < ilen; i ++) {
		if (population[i].getFitness() > population[best].getFitness()) {
			best = i;
		}
	}
	return best;
}