#include "Optimizer.h"
#include<cstdlib>
#include<ctime>

Optimizer::Optimizer(int populationSize, int crossProbability, int mutProbability)
{
	popSize = populationSize;
	crossProb = crossProbability;
	mutProb = mutProbability;
}

void Optimizer::initialize(int numOfVars, std::vector<Query>*q)
{
	Q = q;
	for (int i = 0; i < popSize; i++)
		population.push_back(new Individual(numOfVars));
}

void Optimizer::runIteration()
{
	srand(time(NULL));

	std::vector<Individual*> newPopulation;
	Individual *p1, *p2, *c1, *c2;
	std::pair<Individual*, Individual*> t;
	
	while (newPopulation.size() < population.size())
	{
		p1 = chooseParent();
		p2 = chooseParent();

		if (rand()%100 < mutProb)
		{
			t = p1->crossover(p1, p2);
			c1 = t.first;
			c2 = t.second;
		}
		else
		{
			c1 = p1->copy();
			c2 = p2->copy();
		}

		c1->mutation(mutProb);
		c2->mutation(mutProb);

		newPopulation.push_back(c1);
		newPopulation.push_back(c2);
	}
	while (!population.empty())
	{
		delete population.back();
		population.pop_back();
	}
	population = newPopulation;
	newPopulation.clear();
}

Individual * Optimizer::chooseParent()
{
	srand(time(NULL));

	int i1 = rand() % population.size();
	int i2 = rand() % population.size();

	if(population[i1]->fitness(Q) > population[i2]->fitness(Q))
		return population[i1];
	return population[i2];
}

Individual * Optimizer::getBest()
{
	Individual* max = population[0];
	int m = population[0]->fitness(Q);
	int tmp;
	for (int i = 1; i < population.size(); i++)
	{
		tmp = population[i]->fitness(Q);
		if (tmp > m)
		{
			m = tmp;
			max = population[i];
		}
	}
	return max;
}