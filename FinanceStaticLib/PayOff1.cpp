#include "pch.h"
#include <minmax.h>
#include "PayOff1.h"



	PayOff::PayOff(double Strike_, double UpperStrike_, OptionType TheOptionsType_) :Strike(Strike_), UpperStrike(UpperStrike_), TheOptionsType(TheOptionsType_) {

	}

	double PayOff::operator ()(double spot) const {
		switch (TheOptionsType) {
		case Call:
			return max(spot - Strike, 0.0);

		case Put:
			return max(Strike - spot, 0.0);

		case Digital:
			if (spot > Strike) {
				return 1;
			}
			else {
				return 0;
			};

		case DoubleDigital:
			if (spot > Strike && spot < UpperStrike) {
				return 1;
			}
			else {
				return 0;
			}

		default:
			throw("unknown option type found.");
		}
	}