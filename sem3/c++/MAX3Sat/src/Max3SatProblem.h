#pragma once
#include "Optimizer.h"
#include"Query.h"
#include <string>

class Max3SatProblem
{
	std::vector<Query> problem;
	Optimizer* optimzer;

public:
	Max3SatProblem(int numOfVars) { optimzer = new Optimizer(50, 40, 20); optimzer->initialize(numOfVars, &problem); }
	~Max3SatProblem() { delete optimzer; }

	int compute();
	void load(std::string filename);
};