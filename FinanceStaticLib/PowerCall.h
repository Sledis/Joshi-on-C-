#pragma once
#include "PayOff2.h"
class PayOffPowerCall :
	public PayOff
{
public:
	PayOffPowerCall(double Strike_, double Power_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPowerCall() {};
private:
	double Strike;
	double Power;
};

