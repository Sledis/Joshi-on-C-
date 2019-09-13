#include "pch.h"
#include "LowDiscrepencyPAdic.h"
#include <cmath>
#include <iostream>

bool isPrime(int num) {
	if (num <= 3) {
		return num > 1;
	}
	else if (num % 2 == 0 || num % 3 == 0) {
		return false;
	}
	else {
		for (int i = 5; i * i <= num; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
}

LowDiscrepencyPAdic::LowDiscrepencyPAdic() {
	Seed = 1;
	Base = 2;
}


LowDiscrepencyPAdic::LowDiscrepencyPAdic(int Seed_, int Base_) {
	if (Seed_ < 1) {
		Seed_ = 1;
	}
	if (Base_ < 2) {
		Base_ = 2;
	}
	Seed = Seed_;
	Base = Base_;
}

double LowDiscrepencyPAdic::GetOneRandom() {
	int highestPower = floor(log(Seed) / log(Base));
	double sum = 0;
	int j = Seed;
	for (int k = 1; k < highestPower + 2; k++) {
		int a= j % Base;
		sum += (a+0.0) / pow(Base, k);
		j = (j - a) / Base;
	}
	Seed++;
	return sum;
}

void LowDiscrepencyPAdic::SetSeed(int newSeed) {
	Seed = newSeed;
}


RandomLowDiscrepencyPAdic::RandomLowDiscrepencyPAdic(unsigned long Dimensionality_, unsigned long Seed_):RandomBase(Dimensionality) {
	
	Dimensionality = Dimensionality_;
	
	InitialSeed = Seed_;
	InnerGenerators.resize(Dimensionality);
	std::vector<int> v(Dimensionality);
	int count = 0;
	int trialBase = 2;
	while (count < Dimensionality) {
		if (isPrime(trialBase) == true) {
			v[count] = trialBase;
			trialBase++;
			count++;
		}
		else {
			trialBase++;
		}
	}

	Bases = v;
	for (int i = 0; i < Dimensionality; i++) {
		InnerGenerators[i] = LowDiscrepencyPAdic(InitialSeed, Bases[i]);
	}
}

void RandomLowDiscrepencyPAdic::printBases() const {
	for (int i = 0; i < Dimensionality; i++) {
		std::cout << Bases[i] << std::endl;
	}
}



void RandomLowDiscrepencyPAdic::GetUniforms(MJArray& variates) {
	for (int i = 0; i < Dimensionality; i++) {
		variates[i] = InnerGenerators[i].GetOneRandom();

	}

}



void RandomLowDiscrepencyPAdic::SetSeed(unsigned long Seed_) {
	InitialSeed = Seed_;
}


RandomBase* RandomLowDiscrepencyPAdic::clone() const {
	return new RandomLowDiscrepencyPAdic(*this);

}

void RandomLowDiscrepencyPAdic::Skip(unsigned long numberOfPaths) {
	MJArray tmp(GetDimensionality());
	for (unsigned long j = 0; j < numberOfPaths; j++) {
		GetUniforms(tmp);
	}
}

void RandomLowDiscrepencyPAdic::Reset() {
	for (int i = 0; i < Dimensionality; i++) {
		InnerGenerators[i].SetSeed(1);
	}
	
}

void RandomLowDiscrepencyPAdic::ResetDimensionality(unsigned long NewDimensionality) {
	RandomBase::ResetDimensionality(NewDimensionality);
	for (int i = 0; i < Dimensionality; i++) {
		InnerGenerators[i].SetSeed(1);
	}
}
