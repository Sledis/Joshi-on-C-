#pragma once
#include <iostream>
#include <string>
#include "PayOff3.h"
#include "PayOffFactory.h"

template <class T>
class PayOffHelper
{
public:
	PayOffHelper(std::string);
	static PayOff* Create(double);
};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike) {
	return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id) {
	PayOffFactory& thePayOffFactor = PayOffFactory::Instance();
	thePayOffFactor.RegisterPayOff(id, PayOffHelper<T>::Create);
}

