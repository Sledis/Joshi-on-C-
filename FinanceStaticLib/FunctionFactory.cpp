#include "pch.h"
#include "FunctionFactory.h"
#include <iostream>

using namespace std;

void FunctionFactory::RegisterFunction(std::string FunctionID, CreateFunction NewFunction) {
	TheFunctions.insert(pair<string, CreateFunction>(FunctionID, NewFunction));
}


ParametersInner* FunctionFactory::CreateParameters(std::string FunctionID, std::vector<double> Definitions) {
	map<string, CreateFunction>::const_iterator i = TheFunctions.find(FunctionID);
	if (i == TheFunctions.end()) {
		std::cout << FunctionID << " is an unknown function." << endl;
		return NULL;
	}

	return (i->second)(Definitions);
}

FunctionFactory& FunctionFactory::Instance() {
	static FunctionFactory theFunctionFactory;
	return theFunctionFactory;
}
