#pragma once
#include "TreeProduct.h"
#include "PayOffBridge.h"
class TreeAmerican :
	public TreeProduct
{
public:
	TreeAmerican(double FinalTime, const PayOffBridge& ThePayOff_);
	virtual TreeProduct* clone() const;
	virtual double FinalPayOff(double Spot) const;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
	virtual ~TreeAmerican() {};

private:
	PayOffBridge ThePayOff;
};

