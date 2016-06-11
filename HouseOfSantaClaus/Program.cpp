#include <iostream>
using namespace std;

#include <stdio.h>
#include "HouseOfSantaClaus.h"

void main()
{
	HouseOfSantaClausRecursive house1;
	house1.Solve();
	cout << house1 << endl;
	cout << "Solutions: " << house1.NumberOfSolutions() << endl;

	HouseOfSantaClausRecursive house2;
	house2.Solve();
	cout << house2 << endl;
	cout << "Solutions: " << house2.NumberOfSolutions() << endl;

	getchar();
}