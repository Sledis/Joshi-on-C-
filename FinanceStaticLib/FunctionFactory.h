#pragma once
#include "Parameters.h"
#include <map>
#include <string>
#include <vector>


class FunctionFactory
{
public:
	typedef ParametersInner* (*CreateFunction)(std::vector<double>);
	static FunctionFactory& Instance();
	void RegisterFunction(std::string, CreateFunction);
	ParametersInner* CreateParameters(std::string FunctionID, std::vector<double> Definitions);
	~FunctionFactory() {};


private:
	std::map<std::string, CreateFunction> TheFunctions;
	FunctionFactory() {};
	FunctionFactory(const FunctionFactory&) {};
	FunctionFactory& operator=(const FunctionFactory&) { return *this; };

};

