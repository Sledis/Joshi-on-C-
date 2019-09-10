#include "pch.h"
#include "PayOffStraddle.h"
#include <cmath>

PayOffStraddle::PayOffStraddle(double Strike_) :Strike(Strike_) {};
double PayOffStraddle::operator() (double Spot) const {
	return abs(Spot - Strike);
}

PayOff* PayOffStraddle::clone() const {
	return new PayOffStraddle(*this);
}
