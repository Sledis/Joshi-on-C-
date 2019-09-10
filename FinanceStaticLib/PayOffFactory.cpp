#include "pch.h"
#include "PayOffFactory.h"
#include <iostream>
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction) {
	TheCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike) {
	map<string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);
	if (i == TheCreatorFunctions.end()) {
		std::cout << PayOffId << " is an unknown payoff." << std::endl;
		return NULL;
	}
	return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance() {
	static PayOffFactory theFactory;
	return theFactory;
}
