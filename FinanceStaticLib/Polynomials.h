#pragma once
#include <vector>
class Polynomials
{
public:
	Polynomials(std::vector<double>);
	double value(double x) const;
	double derivative(double x) const;

private:
	std::vector<double> Coefficients;
};

