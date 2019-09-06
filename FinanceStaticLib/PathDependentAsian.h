#pragma once
#include "PathDependent.h"
#include "PayOffBridge.h"
class PathDependentAsian :
	public PathDependent
{
public:
	PathDependentAsian(const MJArray& LookAtTimes_, double DeliveryTime_, const PayOffBridge& ThePayOff_);
	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlowTimes() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
	virtual ~PathDependentAsian() {};
	virtual PathDependent* clone() const;

private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;

};

