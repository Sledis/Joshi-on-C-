#include "Bisection.h"
#include <cmath>
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"
#include <iostream>

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double r;
	double d;
	double Price;

	cout << "Enter expiry: " << flush;
	cin >> Expiry;

	cout << "Enter strike: " << flush;
	cin >> Strike;

	cout << "Enter spot: " << flush;
	cin >> Spot;

	cout << "Enter price: " << flush;
	cin >> Price;

	cout << "Enter r: " << flush;
	cin >> r;

	cout << "Enter d: " << flush;
	cin >> d;

	double low, high;

	cout << "Lower guess: " << flush;
	cin >> low;

	cout << "high guess: " << flush;
	cin >> high;

	double tolerance;

	cout << "Enter tolerance: " << flush;
	cin >> tolerance;

	BSCall theCall(r, d, Expiry, Spot, Strike);

	double vol = Bisection(Price, low, high, tolerance, theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

	cout << "vol: " << vol << ". pricetwo: " << PriceTwo<< "." << endl;

	return 0;

}

