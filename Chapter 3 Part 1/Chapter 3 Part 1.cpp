#include <iostream>
#include "SimpleMC2.h"

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

	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);



	cout << "The call price is " << resultCall << "." << endl;
	cout << "The put price is " << resultPut << "." << endl;


	return 0;
}