#pragma once
#include <map>
#include <string>
#include "PayOff3.h"
#include "DoubleDigital.h"
class PayOffFactory
{
public:
	typedef PayOff* (*CreatePayOffFunction)(double);
	typedef PayOff* (*CreatePayOffFunction2)(double, double);
	static PayOffFactory& Instance();
	void RegisterPayOff(std::string, CreatePayOffFunction);
	void RegisterPayOff(std::string, CreatePayOffFunction2);
	PayOff* CreatePayOff(std::string PayOffId, double Strike);
	PayOff* CreatePayOff2(std::string PayOffId, double lowerStrike, double upperStrike);
	~PayOffFactory(){}

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	std::map<std::string, CreatePayOffFunction2> TheCreatorFunctions2;
	PayOffFactory() {};
	PayOffFactory(const PayOffFactory&) {};
	PayOffFactory& operator=(const PayOffFactory&) { return *this; };
};

