#include<iostream>
#include "SimpleMC.h"
#include "PayOff1.h"

using namespace std;

int main() {
	double Expiry;
	double Strike;
	double UpperStrike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	

	cout << "Enter expiry : " << flush;
	cin >> Expiry;

	cout << "Enter strike : " << flush;
	cin >> Strike;

	cout << "Enter upper strike : " << flush;
	cin >> UpperStrike;

	cout << "Enter spot : " << flush;
	cin >> Spot;

	cout << "Enter vol : " << flush;
	cin >> Vol;

	cout << "Enter r : " << flush;
	cin >> r;

	cout << "Enter number of paths : " << flush;
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, 0, PayOff::Call);
	PayOff putPayOff(Strike, 0, PayOff::Put);
	PayOff digitalPayOff(Strike, 0, PayOff::Digital);
	PayOff doubleDigitalPayOff(Strike, UpperStrike, PayOff::DoubleDigital);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultDigital = SimpleMonteCarlo2(digitalPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultDoubleDigital = SimpleMonteCarlo2(doubleDigitalPayOff, Expiry, Spot, Vol, r, NumberOfPaths);


	cout << "The call price is " << resultCall << "." << endl;
	cout << "The put price is " << resultPut << "." << endl;
	cout << "The digital price is " << resultDigital << "." << endl;
	cout << "The double digital price is " << resultDoubleDigital << "." << endl;
	return 0;
}
