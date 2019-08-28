#include "Random1.h"
#include <iostream>
#include <cmath>

using namespace std;

double simpleMonteCarlo1(string Type, double Expiry, double Strike, double upperStrike, double Spot, double Vol, double r, unsigned long NumberOfPaths) {
	double variance = Vol * Vol * Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; i++) {
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff;
		if (Type == "Call") {
			thisPayoff = thisSpot - Strike;
			thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
		}
		else if (Type == "Put"){
			thisPayoff = Strike - thisSpot;
			thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
		}
		else if (Type == "DoubleDigital") {
			if (Strike < thisSpot && thisSpot < upperStrike) {
				thisPayoff = 1.0;
			}
			else {
				thisPayoff = 0.0;
			}
		}
		else {
			thisPayoff = 0.0;
		}
		
		
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r * Expiry);
	return mean;
}

int main() {
	string Type;
	double Expiry;
	double Strike;
	double upperStrike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	string repeat;


	do {
		cout << "Enter type : " << flush;
		cin >> Type;

		cout << "Enter expiry : " << flush;
		cin >> Expiry;



		if (Type != "DoubleDigital") {

			cout << "Enter strike : " << flush;
			cin >> Strike;

			upperStrike = 0;
		}
		else {

			cout << "Enter lower strike : " << flush;
			cin >> Strike;

			cout << "Enter upper strike : " << flush;
			cin >> upperStrike;
		}

		cout << "Enter spot : " << flush;
		cin >> Spot;

		cout << "Enter vol : " << flush;
		cin >> Vol;

		cout << "Enter r : " << flush;
		cin >> r;

		cout << "Enter number of paths : " << flush;
		cin >> NumberOfPaths;

		double result = simpleMonteCarlo1(Type, Expiry, Strike, upperStrike, Spot, Vol, r, NumberOfPaths);
		cout << endl;
		cout << "The price is " << result << "." << endl;
		cout << endl;
		cout << endl;
		cout << "Price another option? y/n. ";
		cin >> repeat;

	} while (repeat == "y");

	return 0;
}