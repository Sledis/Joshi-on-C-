#include "pch.h"
#include "Polynomials.h"
#include <cmath>
#include <minmax.h>
#include <iostream>

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

Polynomials Polynomials::differentiate() const {
	int Length = Coefficients.size();
	vector<double> NewCoefficients;
	if (Length == 1) {
		Polynomials P({ 0 });
		return P;
	}
	NewCoefficients.resize(Length - 1);
	for (unsigned i = 0; i < Length - 1; i++) {
		NewCoefficients[i]= (Length-1-i) *  Coefficients[i];
	}
	return NewCoefficients;
};

double Polynomials::getDerivative(double x, int n) const {
	Polynomials P(this->Coefficients);
	for (int i = 0; i < n; i++) {
		P = P.differentiate();
	}
	return P.value(x);
}

double Polynomials::firstDerivative(double x) const {
	return this->getDerivative(x, 1);
}

double Polynomials::secondDerivative(double x) const {
	return this->getDerivative(x, 2);
}





double Polynomials::integral(double start, double end) const {
	int Length = Coefficients.size();
	double sum = 0;
	for (unsigned i = 0; i < Length; i++) {
		sum += pow(end, i + 1) * Coefficients[Length - 1 - i] / (i + 1) - pow(start, i + 1) * Coefficients[Length - 1 - i] / (i + 1);
	};


	return sum;
};

Polynomials Polynomials::square() const {
	
	vector<double> SquareCoefficients;
	int Length = Coefficients.size();
	SquareCoefficients.resize(2 * Coefficients.size()-1);
	
	for (int i = 0; i < SquareCoefficients.size(); i++) {
		for (int k = 0; k <= min(i, Coefficients.size()-1); k++) {
			
			if (i - k < Length) {
				
				SquareCoefficients[i] += Coefficients[k] * Coefficients[i - k];
			}
		}
	}
	return Polynomials(SquareCoefficients);
}