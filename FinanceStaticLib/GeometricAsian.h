#pragma once
#include "PathDependent.h"
#include "PayOffBridge.h"
class GeometricAsian :
	public PathDependent
{
public:
	GeometricAsian(const MJArray& LookAtTimes_, double DeliveryTime_, const PayOffBridge& ThePayOff_);
	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlowTimes() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedFlows) const;
	virtual ~GeometricAsian() {};
	virtual PathDependent* clone() const;

private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;
};

