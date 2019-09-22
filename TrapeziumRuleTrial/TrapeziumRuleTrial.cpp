

#include <iostream>
#include "Linear.h"
#include "Polynomials.h"
#include "TrapeziumRule.h"
#include <chrono>
#include "Parameters.h"
#include "ValueDiffableFunction.h"

using namespace std;



int main()
{
	
	ParametersLocallyConstant p(std::vector<double>{1, -1, 3}, std::vector<double>{20, 1, 2});
	std::pair<int, double> answer=p.GetState(23.2);
	cout << p.Integral(0,26) << endl;

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

	double y = Evaluate<DifferentiableFunction, &DifferentiableFunction::value>(3, function);
	cout << y << endl;



	DifferentiableFunction* f=diffFunction<DifferentiableFunction, &DifferentiableFunction::differentiate>(function);
	double z= Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(3, *f);

	cout << z << endl;

	DifferentiableFunction* g = diffFunction<DifferentiableFunction, & DifferentiableFunction::differentiate>(*f);
	double w = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(3, *g);

	cout << w << endl;

	double sqrt = NewtonRaphson<DifferentiableFunction>(0, 2, 0.001, function);

	cout << sqrt << endl;


	/*

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


		
	*/

	
	
	
	
	
	
	


}

