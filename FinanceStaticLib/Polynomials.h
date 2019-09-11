#pragma once
#include <vector>
class Polynomials
{
public:
	Polynomials(std::vector<double>);
	double value(double x) const;
	double derivative(double x) const;
	double integral(double start, double end) const;
	Polynomials square() const;

private:
	std::vector<double> Coefficients ;
};

