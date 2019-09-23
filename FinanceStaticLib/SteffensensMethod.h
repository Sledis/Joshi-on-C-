#pragma once
#include <math.h>


template<class T, double (T::* Value)(double) const>
double SteffensensMethod(double Target, double Start, double Tolerance, const T& TheObject) {
	double y = (TheObject.*Value)(Start)-Target;
	double x = Start;

	while (fabs(y ) > Tolerance) {
		if (y == 0) {
			return x;
		}
		double Numerator = (TheObject.*Value)(x + y) - Target;
		double g = (Numerator / y) - 1;
		x -= y/g;
		y = (TheObject.*Value)(x)-Target;
		

	}
	return x;
}
