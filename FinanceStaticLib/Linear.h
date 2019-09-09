#pragma once
class Linear
{
public:
	Linear(double a, double b);
	double Value(double x) const;
	double Derivative(double x) const;

private:
	double a;
	double b;
};

