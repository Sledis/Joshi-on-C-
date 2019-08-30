// SimpleMCMain4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleMC2.h"
#include "DoubleDigital.h"
#include "PowerCall.h"
#include <string>

using namespace std;

int main()
{
	string Continue;
	do {
		string Type;
		double Expiry;
		double Strike;
		double UpperStrike = 0;
		double Power = 1;
		double Spot;
		double Vol;
		double r;
		unsigned long NumberOfPaths;

		cout << "Enter type : " << flush;
		cin >> Type;

		cout << "Enter expiry : " << flush;
		cin >> Expiry;

		if (Type == "DoubleDigital") {
			cout << "Enter lower strike : " << flush;
			cin >> Strike;

			cout << "Enter upper strike : " << flush;
			cin >> UpperStrike;
		}
		else if  (Type == "PowerCall"){
			cout << "Enter strike : " << flush;
			cin >> Strike;

			cout << "Enter power : " << flush;
			cin >> Power;
		}
		else {
			cout << "Enter strike : " << flush;
			cin >> Strike;
		}





		cout << "Enter spot : " << flush;
		cin >> Spot;

		cout << "Enter vol : " << flush;
		cin >> Vol;

		cout << "Enter r : " << flush;
		cin >> r;

		cout << "Enter number of paths : " << flush;
		cin >> NumberOfPaths;



		PayOff* thePayOffPtr;

		if (Type == "Call") {
			thePayOffPtr = new PayOffCall(Strike);
		}
		else if (Type == "Put") {
			thePayOffPtr = new  PayOffCall(Strike);
		}
		else if (Type == "DoubleDigital") {
			thePayOffPtr = new PayOffDoubleDigital(Strike, UpperStrike);
		}
		else if (Type == "PowerCall") {
			thePayOffPtr = new PayOffPowerCall(Strike, Power);
		}
		else {
			thePayOffPtr = new PayOffDoubleDigital(Strike, Strike);
			cout << "Type is not recoginzed." << endl;
		}


		double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);

		cout << "The price is " << result << "." << endl;

		delete thePayOffPtr;

		cout << endl;
		cout << "Would you like to price another option? y/n : " << flush;
		cin >> Continue;

		cout << endl;
		cout << endl;
	} while (Continue == "y");

	return 0;




}

