#include "pch.h"
#include "SimpleMC8.h"
#include <cmath>
#include "Arrays.h"
#include <time.h>


using namespace std;

int SimpleMonteCarlo6(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, double runTime, StatisticsMC& gatherer, RandomBase& generator) {
	generator.ResetDimensionality(1);
	double Expiry = TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;
	double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);

	double thisSpot;
	double discounting = exp(-r.Integral(0, Expiry));

	MJArray VariateArray(1);
	time_t timer1;
	time(&timer1);
	int i = 0;
	double seconds = 0;
	while( i < NumberOfPaths&& seconds < runTime) {
		generator.GetGaussians(VariateArray);
		thisSpot = movedSpot * exp(rootVariance * VariateArray[0]);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayOff * discounting);
		time_t timer2;
		time(&timer2);
		seconds = difftime(timer2, timer1);
		
		i++;
	}
	return 0;
}