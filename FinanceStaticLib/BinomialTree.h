#pragma once
#include "TreeProduct.h"
#include <vector>
#include "Parameters.h"
#include "Arrays.h"

class SimpleBinomialTree
{
public:
	SimpleBinomialTree(double Spot_, const Parameters& r_, const Parameters& d_, double Volatility_, unsigned long Steps, double Time);
	double GetThePrice(const TreeProduct& TheProduct);

protected:
	void BuildTree();

private:
	double Spot;
	Parameters r;
	Parameters d;
	double Volatility;
	unsigned long Steps;
	double Time;
	bool TreeBuilt;
	std::vector<std::vector<std::pair<double, double>>> TheTree;
	MJArray Discounts;
	
};

