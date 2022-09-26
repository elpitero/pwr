#pragma once
#include<iostream>
#include<vector>
#include"Query.h"

class Individual
{
private:
	int genoSize;
	bool* genotype;
public:
	Individual(int numOfVar);
	~Individual() { delete[] genotype; }

	bool get(int i) { return genotype[i]; }
	void mutation(int mutProb);
	std::pair<Individual*,Individual*> crossover(Individual* p1, Individual* p2);
	int fitness(std::vector<Query>*Q);
	Individual* copy();
};