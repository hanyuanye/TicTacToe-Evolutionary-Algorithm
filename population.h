#include "AiLearner.h"

class Population
{
	public:
		void reproduce();
		void chooseSample();
		void chooseBestTwo();
		void createChild(Learner& child);
		void mutate();
		int getFittest();
		std::vector<Learner> population;
	//Constructer
	Population(int NumberOfAi);
		
	private:
		std::vector<Learner> children;
		std::vector<Learner> sample;
		std::vector<Learner> BestTwo;
		int sampleSize;
};