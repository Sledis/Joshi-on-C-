#pragma once
#include <map>
#include <string>
#include "PayOff3.h"
class PayOffFactory
{
public:
	typedef PayOff* (*CreatePayOffFunction)(double);
	static PayOffFactory& Instance();
	void RegisterPayOff(std::string, CreatePayOffFunction);
	PayOff* CreatePayOff(std::string PayOffId, double Strike);
	~PayOffFactory(){}

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory() {};
	PayOffFactory(const PayOffFactory&) {};
	PayOffFactory& operator=(const PayOffFactory&) { return *this; };
};

