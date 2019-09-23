#pragma once
#include "pch.h"
#include "DifferentiableFunction.h"
class BSPutTwo : public DifferentiableFunction
{
public:
	BSPutTwo(double r_, double d_, double T, double Spot_, double Strike_);
	virtual double value(double x) const;
	virtual DifferentiableFunction* differentiate() const;


private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};

class BSPutVegaTwo : public DifferentiableFunction
{
public:
	BSPutVegaTwo(double r_, double d_, double T, double Spot_, double Strike_);
	virtual double value(double x) const;
	virtual DifferentiableFunction* differentiate() const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};

class BSPutVommaTwo : public DifferentiableFunction
{
public:
	BSPutVommaTwo(double r_, double d_, double T, double Spot_, double Strike_);
	double value(double Vol) const;
	virtual DifferentiableFunction* differentiate() const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;
};
