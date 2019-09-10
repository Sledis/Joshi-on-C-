#include "pch.h"
#include "PayOffFactory.h"
#include <iostream>
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction) {
	TheCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction2 CreatorFunction) {
	TheCreatorFunctions2.insert(pair<string, CreatePayOffFunction2>(PayOffId, CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike) {
	map<string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);
	if (i == TheCreatorFunctions.end()) {
		std::cout << PayOffId << " is an unknown payoff." << std::endl;
		return NULL;
	}
	return (i->second)(Strike);
}

PayOff* PayOffFactory::CreatePayOff2(string PayOffId, double lowerStrike, double upperStrike) {
	map<string, CreatePayOffFunction2>::const_iterator i = TheCreatorFunctions2.find(PayOffId);
	if (i == TheCreatorFunctions2.end()) {
		std::cout << PayOffId << " is an unknown payoff." << std::endl;
		return NULL;
	}
	return (i->second)(lowerStrike, upperStrike);
}


PayOffFactory& PayOffFactory::Instance() {
	static PayOffFactory theFactory;
	return theFactory;
}
