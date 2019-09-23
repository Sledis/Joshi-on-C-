#include "ValueDiffableFunction.h"
#include <cmath>
#include"BSCallTwo.h"
#include "BSPutTwo.h"
#include "BlackScholesFormulas.h"
#include "SecantMethod.h"
#include "Polynomials.h"
#include "SteffensensMethod.h"
#include "HalleysMethod.h"
#include "TestFileReader1.h"
#include "NewtonRaphson.h"






#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string EnterType;

	cout << "Enter t to run from a text document, anything else for self input: " << flush;
	cin >> EnterType;

	if (EnterType == "t") {
		string TestFileName;
		cout << "Text document name: " << flush;
		cin >> TestFileName;


		TestFileReader test1(TestFileName);
		while (!test1.is_open()) {
			cout << "The file submitted can not be opened. Please enter a different name: " << flush;
			cin >> TestFileName;
			test1 = TestFileReader(TestFileName);
		}

		while (!test1.eof()) {

			pair<string, vector<double>> Option = test1.getData();
			string Type = Option.first;
			vector<double> Data = Option.second;

			double Expiry = Data[0];
			double Strike = Data[1];
			double Spot = Data[2];
			double Vol = Data[3];
			double r = Data[4];
			double d = Data[5];
			double AnalyticPrice = Data[6];





			DifferentiableFunction* BSptr;
			if (Type == "Call") {
				BSptr = new BSCallTwo(r, d, Expiry, Spot, Strike);
				if (AnalyticPrice < 0) {
					cout << "Trying to write" << endl;
					AnalyticPrice = BlackScholesCall(Spot, Strike, r, d, Vol, Expiry);
					
				}

			}
			else {
				BSptr = new BSPutTwo(r, d, Expiry, Spot, Strike);
				if (AnalyticPrice < 0) {
					AnalyticPrice = BlackScholesPut(Spot, Strike, r, d, Vol, Expiry);
				}
			}

			vector<double> ans = NewtonRaphson<DifferentiableFunction>(AnalyticPrice, 0.5, 0.0001, *BSptr);
			vector<double> HMans = HalleyMethod<DifferentiableFunction>(AnalyticPrice, 0.5, 0.0001, *BSptr);

			cout << "The Newton Raphson vol is: " << ans[0] << " in " << ans[1] << " loops. The acutal vol is: " << Vol << "." << endl;
			cout << "The Halley Method vol is: " << HMans[0] << " in " << HMans[1] << " loops." << endl;

			//cout << AnalyticPrice << endl;

			//double volNR = NewtonRaphson<DifferentiableFunction, & DifferentiableFunction::value, & DifferentiableFunction::differentiate>(AnalyticPrice, 0.5, 0.00001, BSptr);

			//cout << "The Vol from Newton Raphson is: " << volNR << ". The actual given vol is: " << Vol << "." << endl;

			//double volSec = SecantMethod<DifferentiableFunction, & DifferentiableFunction::value>(AnalyticPrice, 0.05, 0.5, 0.00001, BSptr);

			//cout << "The vol from Secant Method is: " << volSec << ". The actual given vol is: " << Vol << "." << endl;

			//double volHM = HalleysMethod<DifferentiableFunction, & DifferentiableFunction::value, & DifferentiableFunction::differentiate>(AnalyticPrice, 0.5, 0.00001, BSptr);

			//cout << "The vol from Halleys Method is: " << volHM << endl;


			delete BSptr;

		}

	}
	else {
		cout << "Standard input" << endl;
	}


	/*
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

	double volNR = NewtonRaphson<DifferentiableFunction, & DifferentiableFunction::value, & DifferentiableFunction::differentiate>(Price, start, tolerance, &theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, volNR, Expiry);

	cout << "The vol from Newton Raphson is: " << volNR << endl;
	cout << "The price from this implied vol is: " << PriceTwo << endl;

	double volSec = SecantMethod<BSCallTwo, & BSCallTwo::value>(Price, tolerance, start, tolerance, theCall);

	cout << "The vol from Secant Method is: " << volSec << endl;

	double volSM = SteffensensMethod<BSCallTwo, & BSCallTwo::value>(Price, start, tolerance, theCall);

	cout << "The vol from Steffensens Method is: " << volSM << endl;

	double volHM = HalleysMethod<BSCallTwo, & BSCallTwo::value, & BSCallTwo::Vega, &BSCallTwo::Vomma>(Price, start, tolerance, theCall);

	cout << "The vol from Halleys Method is: " << volHM << endl;

	std::vector<double> v = {1,0,-5};
	Polynomials P(v);


	double x = NewtonRaphson<DifferentiableFunction, & DifferentiableFunction::value, & DifferentiableFunction::differentiate>(0, 5, 0.0001, &P);

	//double y = HalleysMethod<Polynomials, & Polynomials::value, & Polynomials::differentiate>(0, 1, 0.001, P);
	cout << x << endl;
	cout << P.getDerivative(1,4) << endl;
	*/
	return 0;
}

