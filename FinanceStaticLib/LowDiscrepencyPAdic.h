#pragma once
#include "Random2.h"
#include <vector>
class LowDiscrepencyPAdic 
{
public:
	LowDiscrepencyPAdic();
	LowDiscrepencyPAdic(int Seed, int Base);
	double GetOneRandom();
	void SetSeed(int Seed);

private:
	int Seed;
	int Base;
};

class RandomLowDiscrepencyPAdic : public RandomBase  {
public:
	RandomLowDiscrepencyPAdic(unsigned long Dimensionality, unsigned long Seed = 1);
	void printBases() const;
	virtual RandomBase* clone() const;
	virtual void GetUniforms(MJArray& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void Reset();
	virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
	std::vector<int> Bases;
	std::vector<LowDiscrepencyPAdic> InnerGenerators;
	int InitialSeed;
	unsigned long Dimensionality;
};

