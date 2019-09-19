#include "pch.h"
#include "BSPutTwo.h"
#include "BlackScholesFormulas.h"

BSPutTwo::BSPutTwo(double r_, double d_, double T_, double Spot_, double Strike_) :r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

double BSPutTwo::value(double Vol) const {
	return BlackScholesPut(Spot, Strike, r, d, Vol, T);
}





DifferentiableFunction* BSPutTwo::differentiate() const
{
	BSPutVegaTwo* BSVega = new BSPutVegaTwo(r, d, T, Spot, Strike);
	return BSVega;
}


BSPutVegaTwo::BSPutVegaTwo(double r_, double d_, double T_, double Spot_, double Strike_) :r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

DifferentiableFunction* BSPutVegaTwo::differentiate() const {
	BSPutVommaTwo* BSVomma = new BSPutVommaTwo(r, d, T, Spot, Strike);
	return BSVomma;
}


double BSPutVegaTwo::value(double Vol) const {
	return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}


BSPutVommaTwo::BSPutVommaTwo(double r_, double d_, double T_, double Spot_, double Strike_) :r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

double BSPutVommaTwo::value(double Vol) const {
	return BlackScholesCallVomma(Spot, Strike, r, d, Vol, T);
}

DifferentiableFunction* BSPutVommaTwo::differentiate() const {
	return __nullptr;
}