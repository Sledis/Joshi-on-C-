#pragma once
class DifferentiableFunction
{public:
	DifferentiableFunction() {};
	virtual DifferentiableFunction* differentiate() const=0;
	virtual double value(double x) const=0;

};

