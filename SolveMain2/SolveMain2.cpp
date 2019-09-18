#include "NewtonRaphson.h"
#include <cmath>
#include"BSCallTwo.h"
#include "BlackScholesFormulas.h"
#include "SecantMethod.h"
#include "Polynomials.h"
#include "SteffensensMethod.h"
#include "HalleysMethod.h"


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

	cout << (theCall.differentiate()->differentiate())->value(0.1) << endl;

	double volNR = NewtonRaphson<BSCallTwo, & BSCallTwo::value, &  BSCallTwo::differentiate>(Price, start, tolerance, theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, volNR, Expiry);

	//cout << "The vol from Newton Raphson is: " << volNR << endl;
	//cout << "The price from this implied vol is: " << PriceTwo << endl;

	/*double volSec = SecantMethod<BSCallTwo, & BSCallTwo::value>(Price, tolerance, start, tolerance, theCall);

	cout << "The vol from Secant Method is: " << volSec << endl;

	double volSM = SteffensensMethod<BSCallTwo, & BSCallTwo::value>(Price, start, tolerance, theCall);

	cout << "The vol from Steffensens Method is: " << volSM << endl;

	double volHM = HalleysMethod<BSCallTwo, & BSCallTwo::value, & BSCallTwo::Vega, &BSCallTwo::Vomma>(Price, start, tolerance, theCall);

	cout << "The vol from Halleys Method is: " << volHM << endl;*/
	
	std::vector<double> v = {3,0,5,1};
	Polynomials P(v);

	
	double x = HalleysMethod<Polynomials, & Polynomials::value, & Polynomials::firstDerivative, & Polynomials::secondDerivative>(0, 1, 0.001, P);

	//double y = HalleysMethod<Polynomials, & Polynomials::value, & Polynomials::differentiate>(0, 1, 0.001, P);

	cout << P.getDerivative(1,4) << endl;

	return 0;
}

