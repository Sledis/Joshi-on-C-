#include "pch.h"
#include "Polynomials.h"
#include <cmath>

using namespace std;

Polynomials::Polynomials(vector<double> Coefficients_):Coefficients(Coefficients_){}

double Polynomials::value(double x) const {
	int Length = Coefficients.size();
	double sum = 0;
	for (unsigned i = 0; i < Length; i++) {
		sum += pow(x, i) * Coefficients[Length - 1 - i];
	}
	return sum;
}

double Polynomials::derivative(double x) const  {
	int Length = Coefficients.size();
	double sum = 0;
	for (unsigned i = 0; i < Length-1; i++) {
		sum += (i+1)*pow(x, i) * Coefficients[Length - 2 - i];
	}
	return sum;
}
