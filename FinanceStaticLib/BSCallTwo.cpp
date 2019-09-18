#include "pch.h"
#include "BSCallTwo.h"
#include "BlackScholesFormulas.h"

BSCallTwo::BSCallTwo(double r_, double d_, double T_, double Spot_, double Strike_):r(r_),d(d_),T(T_),Spot(Spot_),Strike(Strike_){}

double BSCallTwo::value(double Vol) {
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}



double BSCallTwo::Vega(double Vol) const {
	return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}

double BSCallTwo::Vomma(double Vol) const {
	return BlackScholesCallVomma(Spot, Strike, r, d, Vol, T);
}

DifferentiableFunction* BSCallTwo::differentiate()
{	
	BSCallVegaTwo* BSVega = new BSCallVegaTwo(r, d, T, Spot, Strike);
	return BSVega;
}


BSCallVegaTwo::BSCallVegaTwo(double r_, double d_, double T_, double Spot_, double Strike_) :r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

DifferentiableFunction* BSCallVegaTwo::differentiate() {
	BSCallVommaTwo* BSVomma = new BSCallVommaTwo(r, d, T, Spot, Strike);
	return BSVomma;
}


double BSCallVegaTwo::value(double Vol) {
	return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}


BSCallVommaTwo::BSCallVommaTwo(double r_, double d_, double T_, double Spot_, double Strike_) :r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {}

double BSCallVommaTwo::value(double Vol) {
	return BlackScholesCallVomma(Spot, Strike, r, d, Vol, T);
}

DifferentiableFunction* BSCallVommaTwo::differentiate() {
	return __nullptr;
}