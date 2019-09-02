#include "SimpleMC3.h"
#include <iostream>
#include "DoubleDigital.h"

using namespace std;

int main()
{
	double Expiry;
	double Low, Up;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "Enter expry: " << flush;
	cin >> Expiry;

	cout << "Enter low barrier: " << flush;
	cin >> Low;

	cout << "Enter up barrier: " << flush;
	cin >> Up;

	cout << "Enter spot: " << flush;
	cin >> Spot;

	cout << "Enter vol: " << flush;
	cin >> Vol;

	cout << "Enter r: " << flush;
	cin >> r;

	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	PayOffDoubleDigital thePayOff(Low, Up);
	VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

	cout << "The price is " << result << "." << endl;

	return 0;







}

