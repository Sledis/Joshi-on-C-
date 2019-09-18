#pragma once
#include <math.h>

template<class T, double (T::*Value)(double), T* (T::*Derivative)() >
double NewtonRaphson(double Target, double Start, double Tolerance, T* TheObject) {
	double y = (*TheObject.*Value)(Start);
	double x = Start;

	while (fabs(y - Target) > Tolerance) {
		double d = ((TheObject->differentiate())->value(x));
		x += (Target - y) / d;
		y = (*TheObject.*Value)(x);
	}
	return x;
}

