#pragma once
#include <iostream>
#include <string>
#include "DoubleDigital.h"
#include "PayOffFactory.h"

template <class T>
class PayOffHelper
{
public:
	PayOffHelper(std::string);
	static PayOff* Create(double,double);

};

template <class T>
PayOff* PayOffHelper<T>::Create(double lowerStrike, double upperStrike) {
	return new T(lowerStrike,upperStrike);
}




template <class T>
PayOffHelper<T>::PayOffHelper(std::string id) {
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}

