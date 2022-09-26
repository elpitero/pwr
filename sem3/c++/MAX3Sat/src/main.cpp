#include<iostream>
#include"Max3SatProblem.h"
using namespace std;

int main()
{
	Max3SatProblem m(350);
	m.load("m3s_350_49.txt");

	std::cout << m.compute() << endl;
}