#include "pch.h"
#include "PowerCall.h"
#include <minmax.h>
#include <cmath>
PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_) :Strike(Strike_), Power(Power_) {

}
double PayOffPowerCall::operator()(double Spot) const {
	if (Strike - Spot > 0) {
		return max(0.0, pow((Strike - Spot), Power));
	}
	else {
		return 0;
	}
}