// VanillaMain2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleMC4.h"
#include "Vanilla3.h"

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

	double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

	cout << "The Call price is " << result << "." << endl;

	VanillaOption secondOption(theOption);
	
	result = SimpleMonteCarlo3(secondOption, Spot, Vol, r, NumberOfPaths);

	cout << "The call price is " << result << "." << endl;

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption =  thirdOption;

	result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

	cout << "The put price is " << result << "." << endl;

	return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
