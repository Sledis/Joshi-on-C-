#pragma once
#include <math.h>


template<class T, double (T::* Value)(double) const, T* (T::* Derivative)() const>
double HalleysMethod(double Target, double Start, double Tolerance, const T* TheObject) {
	double x = Start;
	double y = (*TheObject.*Value)(Start);
	double yPrime = ((*TheObject.*Derivative()).Value) (Start);
	double yPrimePrime = (((*TheObject.*Derivative).*Derivative).*Value)(Start);

	while (fabs(y-Target) > Tolerance) {
		
		double Numerator = 2*y*yPrime;
		double Denominator = 2 * yPrime * yPrime - y * yPrimePrime;
		x -=Numerator/Denominator;
		y = (*TheObject.*Value)(x);
		yPrime = ((*TheObject.*Derivative).*Value) (x);
		yPrimePrime = (((*TheObject.*Derivative).*Derivative).*Value)(x);

	}
	return x;
}
