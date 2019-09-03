#include <iostream>
#include "SimpleMC6.h"
#include "Vanilla3.h"
#include "Parameters.h"

using namespace std;

int main()
{

	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "Enter expry: " << flush;
	cin >> Expiry;

	cout << "Enter strike barrier: " << flush;
	cin >> Strike;



	cout << "Enter spot: " << flush;
	cin >> Spot;

	cout << "Enter vol: " << flush;
	cin >> Vol;

	cout << "Enter r: " << flush;
	cin >> r;

	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	PayOffCall thePayOff(Strike);

	VanillaOption theOption(thePayOff, Expiry);

	double result;

	VanillaOption secondOption(theOption);

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	result = SimpleMonteCarlo4(secondOption, Spot, VolParam, rParam, NumberOfPaths);

	cout << "The call price is " << result << "." << endl;

	

	return 0;


}