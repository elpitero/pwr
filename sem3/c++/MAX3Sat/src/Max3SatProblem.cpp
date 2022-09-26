#include "Max3SatProblem.h"
#include <fstream>

int Max3SatProblem::compute()
{
	return optimzer->getBest()->fitness(&problem);
}

void Max3SatProblem::load(std::string filename)
{
	std::ifstream file;
	file.open(filename);

	char tmp;
	int a, b, c;

	while (!file.eof())
	{
		file >> tmp >> a >> b >> c >> tmp;
		problem.push_back(Query(a, b, c));
	}
	problem.erase(problem.end() - 1);

	file.close();

	for (int i = 0; i < 10; i++)
	{
		optimzer->runIteration();
		std::cout << compute() << std::endl;
	}
		
}
