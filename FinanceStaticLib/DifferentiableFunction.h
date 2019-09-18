#pragma once
class DifferentiableFunction
{public:
	DifferentiableFunction() {};
	virtual DifferentiableFunction* differentiate()=0;
	virtual double value(double x)=0;

};

