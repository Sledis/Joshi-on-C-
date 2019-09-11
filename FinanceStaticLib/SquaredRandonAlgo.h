#pragma once
#include "Random2.h"
class SquaredRandomAlgo
{public:
	SquaredRandomAlgo( long Seed_ = 3457);
	unsigned long GetOneRandomInteger();
	void SetSeed(unsigned long Seed);
	unsigned long Max();
	unsigned long Min();

private:
	unsigned long Seed;
};

class RandomFromSquares : public RandomBase {
public:
	RandomFromSquares(unsigned long Dimensionality, unsigned long Seed = 3457);
	virtual RandomBase* clone() const;
	virtual void GetUniforms(MJArray& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void ResetDimensionality(unsigned long NewDimensionality);
	virtual void Reset();


private:
	SquaredRandomAlgo InnerGenerator;
	unsigned long InitialSeed;
	double Reciprocal;

};


