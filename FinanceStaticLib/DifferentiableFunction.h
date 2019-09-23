#pragma once
class DifferentiableFunction
{public:
	DifferentiableFunction() {};
	virtual DifferentiableFunction* differentiate() const=0;
	double NumericDifferentiate(double x, double h);
	virtual double value(double x) const=0;

};

