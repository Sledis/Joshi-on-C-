#pragma once

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

template < class T>
double NewtonRaphson(double Target, double Start, double Tolerance, T& TheObject) {

	double x = Start;
	double y = Evaluate<T, &T::value>(x, TheObject);
	T* diffedFunction = diffFunction<DifferentiableFunction, & DifferentiableFunction::differentiate>(TheObject);

	while (fabs(y - Target) > Tolerance) {
		double d = Evaluate<DifferentiableFunction, & DifferentiableFunction:: value>(x, *diffedFunction);
		x += (Target - y) / d;
		y = Evaluate<DifferentiableFunction, & DifferentiableFunction:: value>(x, TheObject);
	}
	return x;

}