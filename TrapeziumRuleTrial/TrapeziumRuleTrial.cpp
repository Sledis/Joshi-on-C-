

#include <iostream>
#include "Linear.h"
#include "Polynomials.h"
#include "TrapeziumRule.h"

using namespace std;

int main()
{
	int degreeOfPolynomial;
	cout << "Enter degree of Polynomial: " << flush;
	cin >> degreeOfPolynomial;

	vector<double> Coefficients(degreeOfPolynomial+1);

	for (unsigned i = 0; i < degreeOfPolynomial + 1; i++) {
		double coefficient;
		cout << "Enter the " << degreeOfPolynomial - i << "'th coefficient: " << flush;
		cin >>  coefficient;
		Coefficients[i] = coefficient;
	}

	Polynomials function(Coefficients);
	Polynomials function2=function.square();

	double Start;
	cout << "Enter the starting point: " << flush;
	cin >> Start;

	double Stop;
	cout << "Enter the stopping point: " << flush;
	cin >> Stop;

	double Steps;
	cout << "Enter the number of steps: " << flush;
	cin >> Steps;

	double integral = TrapeziumRule<Polynomials, & Polynomials::value>(Start, Stop, Steps, function);
	cout << "The numberical integral has value: " << integral << endl;
	cout << "The actual value is: " << function.integral(Start, Stop) << endl;
	//cout << "The actual value is: " << function2.integral(Start, Stop) << endl;
	//Linear aLine(1, 0);
	//vector<double> Coefficients{ 1,0,0,2 };
	//Polynomials quad(Coefficients);
	//double integral = TrapeziumRule<Linear, & Linear::Value>(0, 10, 1, aLine);
	//cout << integral << endl;
	//cout << quad.value(1) << " " << quad.derivative(1) << endl;


	return 0;
}

