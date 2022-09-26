#include "Individual.h"
#include<ctime>
#include<cstdlib>

Individual::Individual(int numOfVars)
{
	srand(time(NULL));

	genoSize = numOfVars;
	genotype = new bool[numOfVars];
	for (int i = 0; i < numOfVars; i++)
		if (rand() % 2 == 0)
			genotype[i] = false;
		else
			genotype[i] = true;
}

void Individual::mutation(int mutProb)
{
	srand(time(NULL));

	for (int i = 0; i < genoSize; i++)
		if (rand()%100 < mutProb)
			genotype[i] = !(genotype[i]);
}


std::pair<Individual*, Individual*> Individual::crossover(Individual * p1, Individual * p2)
{
	srand(time(NULL));

	std::pair<Individual*, Individual*> t;
	t.first = new Individual(genoSize);
	t.second = new Individual(genoSize);

	for (int i = 0; i < genoSize; i++)
		if (rand() % 2)
		{
			t.first->genotype[i] = p1->get(i);
			t.second->genotype[i] = p2->get(i);
		}
		else
		{
			t.first->genotype[i] = p2->get(i);
			t.second->genotype[i] = p1->get(i);
		}
	return t;
}

int Individual::fitness(std::vector<Query> *Q)
{
	int counter = 0;
	for (int i = 0; i < Q->size(); i++)
		if (Q->at(i).checkQuery(
			genotype[Q->at(i).get1()],
			genotype[Q->at(i).get2()],
			genotype[Q->at(i).get3()]
		))
			counter++;

	return counter;
}

Individual * Individual::copy()
{
	Individual* copy = new Individual(genoSize);
	for (int i = 0; i < genoSize; i++)
		copy->genotype[i] = genotype[i];
	return copy;
}
