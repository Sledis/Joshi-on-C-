#include "PayOff1.h"
#include <minmax.h>

PayOff::PayOff(double Strike_, OptionType TheOptionsType_):Strike(Strike_), TheOptionsType(TheOptionsType_) {

}

double PayOff::operator ()(double spot) const {
	switch (TheOptionsType) {
	case Call :
		return max(spot - Strike, 0.0);

	case Put :
		return max(Strike - spot, 0.0);

	default :
		throw("unknown option type found.");
	}
}
