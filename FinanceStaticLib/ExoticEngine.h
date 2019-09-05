#pragma once
#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "MCStatistics.h"
#include <vector>

class ExoticEngine
{
public:
	ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);
	virtual void GetOnePath(MJArray& SpotValues) = 0;
	void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
	virtual ~ExoticEngine() {};
	double DoOnePath(const MJArray& SpotValues) const;

private:
	Wrapper<PathDependent> TheProduct;
	Parameters r;
	MJArray Discounts;
	mutable std::vector<CashFlow> TheseCashFlows;
};

