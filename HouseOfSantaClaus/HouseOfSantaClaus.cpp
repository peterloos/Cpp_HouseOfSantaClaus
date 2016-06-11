#include <iostream>
using namespace std;

#include <stdio.h>
#include "HouseOfSantaClaus.h"

// c'tor
HouseOfSantaClaus::HouseOfSantaClaus()
{
	m_count = 0;
	m_solutions = (int*)0;
}

// d'tor
HouseOfSantaClaus::~HouseOfSantaClaus()
{
	delete[] m_solutions;
}

// private helper methods
void HouseOfSantaClaus::AddSolution(int number)
{
	// allocate new array
	int* tmp = new int[m_count + 1];

	// copy existing solutions
	for (int i = 0; i < m_count; i++)
		tmp[i] = m_solutions[i];

	// add new solution
	tmp[m_count] = number;

	// switch buffers
	delete[] m_solutions;
	m_solutions = tmp;
	m_count++;
}

// output
ostream& operator<< (ostream& os, const HouseOfSantaClaus& house)
{
	for (int i = 0; i < house.m_count; i += 2)
	{
		house.PrintSolution(os, house.m_solutions[i]);
		os << "   ";

		if (i + 1 < house.m_count)
			house.PrintSolution(os, house.m_solutions[i + 1]);

		os << endl;
	}

	return os;
}

// private helper method
void HouseOfSantaClaus::PrintSolution(ostream& os, int number) const
{
	if (number >= 10)
	{
		int rest = number % 10;
		PrintSolution(os, number / 10);
		os << "->" << rest;
	}
	else
		os << number;
}
