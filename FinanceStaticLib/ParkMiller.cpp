#include "pch.h"
#include "ParkMiller.h"
#include <iostream>

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_) :Seed(Seed_) {
	if (Seed == 0) {
		Seed = 1;
	}
}

void ParkMiller::SetSeed(long Seed_) {
	Seed = Seed_;
	if (Seed == 0) {
		Seed = 1;
	}
}

unsigned long ParkMiller::Max() {
	return m - 1;
}

unsigned long ParkMiller::Min() {
	return 1;
}

long ParkMiller::GetOneRandomInteger() {
	long k;
	k = Seed / q;

	Seed = a * (Seed - k * q) - r * k;
	if (Seed < 0) {
		Seed += m;
	}
	return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality, unsigned long Seed) :RandomBase(Dimensionality), InnerGenerator(Seed), InitialSeed(Seed) {
	Reciprocal = 1 / (1.0 + InnerGenerator.Max());
}

RandomBase* RandomParkMiller::clone() const {
	return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray& variates) {
	for (unsigned long j = 0; j < GetDimensionality(); j++) {
		variates[j] = InnerGenerator.GetOneRandomInteger() * Reciprocal;
	}
}

void RandomParkMiller::Skip(unsigned long numberOfPaths) {
	MJArray tmp(GetDimensionality());
	for (unsigned long j = 0; j < numberOfPaths; j++) {
		GetUniforms(tmp);
	}
}

void RandomParkMiller::SetSeed(unsigned long Seed) {
	InitialSeed = Seed;
	InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset() {
	InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality) {
	RandomBase::ResetDimensionality(NewDimensionality);
	InnerGenerator.SetSeed(InitialSeed);
}


LowDiscrepencyParkMiller::LowDiscrepencyParkMiller(unsigned long Dimensionality, unsigned long Seed) :RandomBase(Dimensionality), InnerGenerator(Seed), InitialSeed(Seed) {
	Reciprocal = 1 / (1.0 + InnerGenerator.Max());
	Previous.resize(Dimensionality);
	for (int i = 0; i < Dimensionality; i++) {
		Previous[i] = -0.5;
	}
}

RandomBase* LowDiscrepencyParkMiller::clone() const {
	return new LowDiscrepencyParkMiller(*this);
}

void LowDiscrepencyParkMiller::GetUniforms(MJArray& variates) {
	for (unsigned long j = 0; j < GetDimensionality(); j++) {
		double previousRand = Previous[j];
		double halvedRand = (InnerGenerator.GetOneRandomInteger() * Reciprocal)/2 ;
		double random = previousRand + 0.5 + halvedRand;
		while (random > 1) {
			random -= 1;
		}
		variates[j] = random;
		Previous[j] = random;
		
	
	}
}

void LowDiscrepencyParkMiller::Skip(unsigned long numberOfPaths) {
	MJArray tmp(GetDimensionality());
	for (unsigned long j = 0; j < numberOfPaths; j++) {
		GetUniforms(tmp);
	}
}

void LowDiscrepencyParkMiller::SetSeed(unsigned long Seed) {
	InitialSeed = Seed;
	InnerGenerator.SetSeed(Seed);
}

void LowDiscrepencyParkMiller::Reset() {
	InnerGenerator.SetSeed(InitialSeed);
}

void LowDiscrepencyParkMiller::ResetDimensionality(unsigned long NewDimensionality) {
	RandomBase::ResetDimensionality(NewDimensionality);
	InnerGenerator.SetSeed(InitialSeed);
}