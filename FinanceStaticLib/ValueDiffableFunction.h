#pragma once
#include "DifferentiableFunction.h"

template<class T, double (T::*Value)(double) const>
double Evaluate(double point, T& TheObject) {
	double y=(TheObject.*Value)(point);
	return y;
}

template <class T, T* (T::*Differentiate)() const>
T* diffFunction(T& TheObject) {
	T* diffedFunction=(TheObject.*Differentiate)();
	return diffedFunction;
}

