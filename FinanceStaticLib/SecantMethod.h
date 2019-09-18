#pragma once
#include <math.h>


template<class T, double (T::* Value)(double) const>
double SecantMethod(double Target, double Initial1, double Initial2, double Tolerance, const T& TheObject) {
	double x1 = Initial1;
	double x2 = Initial2;
	double y1 = (TheObject.*Value)(x1) - Target;
	double y2 = (TheObject.*Value)(x2) - Target;
	while (y2 == y1) {
		x2 += Tolerance;
		y2 = (TheObject.*Value)(x2) - Target;
		
	}
	

	while (fabs(y2) > Tolerance) {
		double xNew = (x1 * y2 - x2 * y1) / (y2 - y1);
		x1 = x2;
		x2 = xNew;
		y1 = y2;
		y2 = (TheObject.*Value)(x2)-Target;
	}
	return x2;
}