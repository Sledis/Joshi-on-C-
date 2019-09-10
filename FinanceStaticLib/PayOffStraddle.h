#pragma once
#include "PayOff3.h"
class PayOffStraddle :
	public PayOff
{
public:
	PayOffStraddle(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffStraddle() {};
	virtual PayOff* clone() const;

private:
	double Strike;
};

