#include "pch.h"
#include "PayOffForward.h"

double PayOffForward::operator() (double Spot) const {
	return Spot - Strike;
}

PayOffForward::PayOffForward(double Strike_) : Strike(Strike_) {};

PayOff* PayOffForward::clone() const {
	return new PayOffForward(*this);
}
