#include <iostream>
#include "LowDiscrepencyPAdic.h"

using namespace std;

int main() {

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
	

	return 0;
}