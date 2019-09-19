#pragma once
#include <math.h>
#include <iostream>
using namespace std;


template<class T, double (T::* Value)(double) const>
double SecantMethod(double Target, double Initial1, double Initial2, double Tolerance, const T* TheObject) {
	double x1 = Initial1;
	double x2 = Initial2;
	double y1 = (*TheObject.*Value)(x1);
	double y2 = (*TheObject.*Value)(x2);
	while (y2 == y1) {
		x2 += Tolerance;
		y2 = (*TheObject.*Value)(x2);
		
	}
	

	while (fabs(y2 -Target) > Tolerance) {

		cout << x2 << endl;
		double x2dup = x2;
		x2 -= (y2-Target) * (x2 - x1) / (y2 - y1);
		x1 = x2dup;
		y1 = y2;
		y2 = (*TheObject.*Value)(x2);
	}
	return x2;
}