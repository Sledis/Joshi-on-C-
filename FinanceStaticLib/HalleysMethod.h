#pragma once
#include <math.h>


template<class T, double (T::* Value)(double) const, double (T::* Derivative)(double) const, double (T::* SecondDerivative)(double) const>
double HalleysMethod(double Target, double Start, double Tolerance, const T& TheObject) {
	double x = Start;
	double y = (TheObject.*Value)(Start);
	double yPrime = (TheObject.*Derivative)(Start);
	double yPrimePrime = (TheObject.*SecondDerivative)(Start);

	while (fabs(y-Target) > Tolerance) {
		
		double Numerator = 2*y*yPrime;
		double Denominator = 2 * yPrime * yPrime - y * yPrimePrime;
		x -=Numerator/Denominator;
		y = (TheObject.*Value)(x);

	}
	return x;
}
