#pragma once
class BSCall
{
public:
	BSCall(double r_, double d_, double T, double Spot_, double Strike_);
	double operator()(double Vol) const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};

