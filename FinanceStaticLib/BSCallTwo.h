#pragma once
#include "pch.h"
#include "DifferentiableFunction.h"
class BSCallTwo: public DifferentiableFunction
{
public:
	BSCallTwo(double r_, double d_, double T, double Spot_, double Strike_);
	virtual double value(double x);
	virtual DifferentiableFunction* differentiate();
	double Vega(double Vol) const;
	double Vomma(double Vol) const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};

class BSCallVegaTwo: public DifferentiableFunction
{
public:
	BSCallVegaTwo(double r_, double d_, double T, double Spot_, double Strike_);
	virtual double value(double x);
	virtual DifferentiableFunction* differentiate();

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};

class BSCallVommaTwo : public DifferentiableFunction
{
public:
	BSCallVommaTwo(double r_, double d_, double T, double Spot_, double Strike_);
	double value(double Vol);
	virtual DifferentiableFunction* differentiate();

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};
