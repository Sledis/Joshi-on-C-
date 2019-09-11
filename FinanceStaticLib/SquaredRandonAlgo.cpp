#include "pch.h"
#include "SquaredRandonAlgo.h"
#include <iostream>

SquaredRandomAlgo::SquaredRandomAlgo( long Seed_) :Seed(Seed_) {
	while (Seed > 9999) {
		Seed -= 1000;
	};
	while (Seed < 1001) {
		Seed += 1000;
	};
}

unsigned long SquaredRandomAlgo::GetOneRandomInteger() {
	int seedSquared = Seed * Seed;
	int endBit = seedSquared % 100;
	int almostThere = (seedSquared - endBit) / 100;
	
	SetSeed(almostThere % 10000);
	std::cout << Seed << " ";
	return Seed;
}

void SquaredRandomAlgo::SetSeed(unsigned long Seed_) {
	Seed = Seed_;
	while (Seed > 9999) {
		Seed -= 1000;
	}
	while (Seed < 1001) {
		Seed += 1000;
	}
	Seed += 179;
}

unsigned long SquaredRandomAlgo::Max() {
	return 9999;
}

unsigned long SquaredRandomAlgo::Min() {
	return 1001;
}





RandomFromSquares::RandomFromSquares(unsigned long Dimensionality, unsigned long Seed) : RandomBase(Dimensionality), InnerGenerator(Seed), InitialSeed(Seed) {
	Reciprocal = 1.0 / (InnerGenerator.Max() - InnerGenerator.Min());
}

RandomBase* RandomFromSquares::clone() const {
	return new RandomFromSquares(*this);
}

void RandomFromSquares::GetUniforms(MJArray& variates) {
	for (unsigned long j = 0; j < GetDimensionality(); j++) {
		variates[j] = InnerGenerator.GetOneRandomInteger() * Reciprocal;
	}
}

void RandomFromSquares::Skip(unsigned long numberOfPaths) {
	MJArray tmp(GetDimensionality());
	for (unsigned long j = 0; j < numberOfPaths; j++) {
		GetUniforms(tmp);
	}
}

void RandomFromSquares::SetSeed(unsigned long Seed) {
	InitialSeed = Seed;
	InnerGenerator.SetSeed(Seed);
}

void RandomFromSquares::Reset() {
	InnerGenerator.SetSeed(InitialSeed);
}

void RandomFromSquares::ResetDimensionality(unsigned long NewDimensionality) {
	RandomBase::ResetDimensionality(NewDimensionality);
	InnerGenerator.SetSeed(InitialSeed);
}

/*











*/