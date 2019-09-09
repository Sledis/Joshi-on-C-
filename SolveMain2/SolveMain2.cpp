#include "NewtonRaphson.h"
#include <cmath>
#include"BSCallTwo.h"
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

	double start;

	cout << "start guess: " << flush;
	cin >> start;

	double tolerance;

	cout << "Enter tolerance: " << flush;
	cin >> tolerance;

	BSCallTwo theCall(r, d, Expiry, Spot, Strike);
	double vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, start, tolerance, theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

	cout << "The vol from Newton Raphson is: " << vol << endl;
	cout << "The price from this implied vol is: " << PriceTwo << endl;

	
	
	return 0;
}

