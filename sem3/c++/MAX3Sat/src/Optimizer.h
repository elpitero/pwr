#pragma once
#include "Individual.h"

class Optimizer
{
	std::vector <Individual*> population;
	int popSize;
	int crossProb;
	int mutProb;
	std::vector<Query> *Q;
public:
	Optimizer(int populationSize, int crossProbability, int mutProbability);
	~Optimizer() {
		while (!population.empty())
		{
			delete population.back();
			population.pop_back();
		}
	}

	void initialize(int numOfVars, std::vector<Query>*q);
	void runIteration();
	Individual* chooseParent();

	Individual* getBest();
};

