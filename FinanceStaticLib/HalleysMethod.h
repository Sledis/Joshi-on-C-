#pragma once
#include <math.h>

/*
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
}*/

template < class T>
vector<double> HalleyMethod(double Target, double Start, double Tolerance, T& TheObject) {
	vector<double> v(2);
	double x = Start;
	double y = Evaluate<T, & T::value>(x, TheObject);
	T* diffedFunction = diffFunction<DifferentiableFunction, & DifferentiableFunction::differentiate>(TheObject);
	T* doubleDiffedFunction = diffFunction<DifferentiableFunction, & DifferentiableFunction::differentiate>(*diffedFunction);
	double loops = 0;

	while (std::fabs(y - Target) > Tolerance) {
		double yPrime = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(x, *diffedFunction);
		double yPrimePrime = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(x, *doubleDiffedFunction);
	

		double Numerator = 2 * (y - Target) * yPrime;
		double Denominator = 2 * yPrime * yPrime - (y - Target) * yPrimePrime;
		x -= Numerator / Denominator;
		y = Evaluate<DifferentiableFunction, & DifferentiableFunction::value>(x, TheObject);
		loops++;
	}
	v[0] = x;
	v[1] = loops;
	return v;

}
