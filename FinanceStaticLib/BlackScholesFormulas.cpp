#include "pch.h"
#include "BlackScholesFormulas.h"
#include "Normals.h"
#include <cmath>

using namespace std;

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return Spot * exp(-d * Expiry) * CumulativeNormal(d1) - Strike * exp(-r * Expiry) * CumulativeNormal(d2);
}

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	return Strike * exp(-r * Expiry) *(1.0- CumulativeNormal(d2)) - Spot * exp(-d * Expiry) *(1- CumulativeNormal(d1));
}

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d2 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	
	return exp(-r * Expiry) * CumulativeNormal(d2);
}

double BlackScholesDigitalPut(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d2 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;

	return exp(-r * Expiry) * (1 - CumulativeNormal(d2));
}

double BlackScholesCallVega(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	
	return Spot * exp(-d * Expiry) *sqrt(Expiry)* NormalDensity(d1) ;
}

double BlackScholesCallVomma(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
	double standardDeviation = Vol * sqrt(Expiry);
	double moneyness = log(Spot / Strike);
	double d1 = (moneyness + (r - d) * Expiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	double d2 = (moneyness + (r - d) * Expiry - 0.5 * standardDeviation * standardDeviation) / standardDeviation;
	double Vega = BlackScholesCallVega(Spot, Strike, r, d, Vol, Expiry);
	return Vega * d1 * d2 / Vol;
}