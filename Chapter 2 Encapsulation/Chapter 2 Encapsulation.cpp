#include<iostream>
#include "SimpleMC.h"
#include "PayOff1.h"

using namespace std;

int main() {
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	

	cout << "Enter expiry : " << flush;
	cin >> Expiry;

	cout << "Enter strike : " << flush;
	cin >> Strike;

	cout << "Enter spot : " << flush;
	cin >> Spot;

	cout << "Enter vol : " << flush;
	cin >> Vol;

	cout << "Enter r : " << flush;
	cin >> r;

	cout << "Enter number of paths : " << flush;
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, PayOff::Call);
	PayOff putPayOff(Strike, PayOff::Put);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

	cout << "the prices are " << resultCall << " for the call and " << resultPut << " for the put." << endl;


	return 0;
}
