#pragma once
#include "PayOff3.h"
class PayOffDigitalCall :
	public PayOff
{
public:
	PayOffDigitalCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDigitalCall() {};
	virtual PayOff* clone() const;

private:
	double Strike;

};
class PayOffDigitalPut :
	public PayOff
{
public:
	PayOffDigitalPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDigitalPut() {};
	virtual PayOff* clone() const;

private:
	double Strike;

};

