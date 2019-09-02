#pragma once
#include "PayOff3.h"

class VanillaOption
{
public:
	VanillaOption(const PayOff& ThePayOff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	VanillaOption& operator =(const VanillaOption& original);
	~VanillaOption();

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOff* ThePayOffPtr;
};

