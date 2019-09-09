#pragma once

template<class T, double (T::*Value)(double) const>
double TrapeziumRule(double Start, double Stop, int Spaces, const T& TheObject) {
	double multFactor = (Stop - Start + 0.0) / (2 * Spaces);
	double sum = (TheObject.*Value)(Start) + (TheObject.*Value)(Stop);
	for (unsigned i = 1; i < Spaces; i++) {
		Start += 2 * multFactor;
		sum += 2 * (TheObject.*Value)(Start);
	}
	return sum * multFactor;

}
