#pragma once
class PayOff
{
public:
	enum OptionType {Call, Put};
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;


private:
	double Strike;
	OptionType TheOptionsType;
};

