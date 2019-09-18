#pragma once
#include <vector>
class Polynomials
{
public:
	Polynomials(std::vector<double>);
	double value(double x) const;
	Polynomials differentiate() const;
	double getDerivative(double x,int n) const;
	double firstDerivative(double x) const;
	double secondDerivative(double x) const;
	double integral(double start, double end) const;
	Polynomials square() const;

private:
	std::vector<double> Coefficients;
};

