#include "pch.h"
#include "PayOffDigital.h"

PayOffDigitalCall::PayOffDigitalCall(double Strike_) :Strike(Strike_) {};

double PayOffDigitalCall::operator() (double Spot) const {
	if (Spot > Strike) {
		return 1;
	}
	return 0;
}

PayOff* PayOffDigitalCall::clone() const {
	return new PayOffDigitalCall(*this);
}

PayOffDigitalPut::PayOffDigitalPut(double Strike_) :Strike(Strike_) {};

double PayOffDigitalPut::operator() (double Spot) const {
	if (Spot > Strike) {
		return 0;
	}
	return 1;
}

PayOff* PayOffDigitalPut::clone() const {
	return new PayOffDigitalPut(*this);
}