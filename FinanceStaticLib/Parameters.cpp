#include "pch.h"
#include "Parameters.h"
#include <cmath>
#include "Polynomials.h"
#include <iostream>

Parameters::Parameters(const ParametersInner& innerObject) {
	InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original) {
	InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original) {
	if (this != &original) {
		delete InnerObjectPtr;
		InnerObjectPtr = original.InnerObjectPtr->clone();
	}
	return *this;
}

Parameters::~Parameters() {
	delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const {
	double total = Integral(time1, time2);
	return total / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const {
	double total = IntegralSquare(time1, time2);
	return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double constant) {
	Constant = constant;
	ConstantSquare = Constant * Constant;
}

ParametersInner* ParametersConstant::clone() const {
	return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const {
	return (time2 - time1) * Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
	return (time2 - time1) * ConstantSquare;
}

ParametersExponential::ParametersExponential(double coefficient, double power) :Coefficient(coefficient), Power(power) {};

ParametersInner* ParametersExponential::clone() const {
	return new ParametersExponential(*this);
}

double ParametersExponential::Integral(double time1, double time2) const {
	if (Power != 0) {
		return (Coefficient / Power) * (exp(Power * time2) - exp(Power * time1));
	}
	else {
		return Coefficient * (time2 - time1);
	}
	
}

double ParametersExponential::IntegralSquare(double time1, double time2) const {
	if (Power != 0) {
		return (Coefficient * Coefficient / (2 * Power)) * (exp(2 * Power * time2) - exp(2 * Power * time1));
	}
	else {
		return Coefficient*Coefficient * (time2 - time1);
	}
	
}

ParametersPolynomial::ParametersPolynomial(std::vector<double> Coefficients) :Coefficients(Coefficients) {};

ParametersInner* ParametersPolynomial::clone() const {
	return new ParametersPolynomial(*this);
}

double ParametersPolynomial::Integral(double time1, double time2) const{     
	
	Polynomials p(Coefficients);
	return p.integral(time1, time2);

	
}

double ParametersPolynomial::IntegralSquare(double time1, double time2) const {
	Polynomials p(Coefficients);
	Polynomials pSq = p.square();
	return pSq.integral(time1, time2);

}

ParametersLocallyConstant::ParametersLocallyConstant(std::vector<double> Values_, std::vector<double> LengthOfTimes_) :Values(Values_), LengthOfTimes(LengthOfTimes_) {
	TotalTime = 0;
	for (int i = 0; i < Values.size(); i++) {
		TotalTime += LengthOfTimes[i];
	}
};

ParametersInner* ParametersLocallyConstant::clone() const {
	return new ParametersLocallyConstant(*this);

}

std::pair<int, double> ParametersLocallyConstant::GetState(double time) const {

	int i = 0;
	double RunningTime = LengthOfTimes[i];
	while (RunningTime < time&&i<LengthOfTimes.size()-1) {
		i++;
		RunningTime += LengthOfTimes[i];
	}
	std::pair<int, double> v(i, -time + RunningTime );
	return v;
}


double ParametersLocallyConstant::Integral(double time1, double time2) const {
	int i = GetState(time1).first;
	double startRemainder = GetState(time1).second;
	int j = GetState(time2).first;
	double endRemainder =LengthOfTimes[j]- GetState(time2).second;
	
	if (i == j) {
		return (-endRemainder + startRemainder) * Values[i];
	}
	double sum = startRemainder * Values[i] + endRemainder * Values[j];
	while (i < j - 1) {
		i++;
		sum += LengthOfTimes[i] * Values[i];
	}

	return sum;
}

double ParametersLocallyConstant::IntegralSquare(double time1, double time2) const {
	return 0;
}