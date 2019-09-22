#pragma once
#include <math.h>
#include <vector>
#include "DifferentiableFunction.h"



template < class T>
std::vector<double> NewtonRaphson(double Target, double Start, double Tolerance, T& TheObject) {
	vector<double> v(2);
	double x = Start;
	double y = Evaluate<T, & T::value>(x, TheObject);
	T* diffedFunction = diffFunction<DifferentiableFunction, & DifferentiableFunction::differentiate>(TheObject);
	double loops = 0;
	while (std::fabs(y - Target) > Tolerance) {
		double d = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(x, *diffedFunction);
		x += (Target - y) / d;
		y = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(x, TheObject);
		loops++;
	}
	v[0] = x;
	v[1] = loops;
	return v;

}

/*
template<class T, double (T::*Value)(double) const, T* (T::*Derivative)() const>
double NewtonRaphson(double Target, double Start, double Tolerance, T* TheObject) {
	double y = (*TheObject.*Value)(Start);
	double x = Start;

	while (fabs(y - Target) > Tolerance) {
		double d = (TheObject->differentiate)->value(Start);
		x += (Target - y) / d;
		y = (*TheObject.*Value)(x);
	}
	return x;
}
/*
template<class T, double (T::*Value)(double) const/*, double (T::*Derivative)(double) const>
double NewtonRaphsonTrial(double Target, double Start, double Tolerance, const T& TheObject) {
	double y = (TheObject.*Value)(Start);


	return y;
}*/