#pragma once
#include <iostream>
#include "Parameters.h"
#include "FunctionFactory.h"
#include <string>


template <class T>
class ParametersHelper {
public:
	ParametersHelper(std::string);
	static ParametersInner* Create(std::vector<double>);
	static ParametersInner* Create(std::vector<double>, std::vector<double>);
};

template <class T>
ParametersInner* ParametersHelper<T>::Create(std::vector<double> Definitions) {
	return new T(Definitions);
}

template <class T>
ParametersInner* ParametersHelper<T>::Create(std::vector<double> Definitions, std::vector<double> secondaryDefinitions) {
	return new T(Definitions, secondaryDefinitions);
}

template <class T>
ParametersHelper<T>::ParametersHelper(std::string id) {
	FunctionFactory& theFunctionFactory = FunctionFactory::Instance();
	theFunctionFactory.RegisterFunction(id, ParametersHelper<T>::Create);
}