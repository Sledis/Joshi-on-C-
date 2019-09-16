#include <iostream>
#include "LowDiscrepencyPAdic.h"
#include <time.h>

using namespace std;

int main() {
	time_t timer;
	time(&timer);
	LowDiscrepencyPAdic Random(1, 8);

	for (int i = 0; i < 100; i++) {
		 
		cout << Random.GetOneRandom() << endl;
	}

	int Dim = 10;
	RandomLowDiscrepencyPAdic RandomTable(Dim);
	RandomTable.printBases();
	RandomTable.SetSeed(7);
	RandomTable.printBases();
	MJArray M(Dim);


	for (int i = 0; i < 100; i++) {

		RandomTable.GetUniforms(M);
	}
	time_t timer2;
	time(&timer2);
	double seconds = difftime(timer2, timer);
	cout << endl;
	cout << seconds << endl;
	return 0;
}