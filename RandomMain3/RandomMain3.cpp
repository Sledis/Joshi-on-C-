#include <iostream>
#include "SimpleMC8.h"
#include "ParkMiller.h"
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	int NumberOfMoments;

	cout << "Enter expiry: " << flush;
	cin >> Expiry;

	cout << "Enter strike: " << flush;
	cin >> Strike;

	cout << "Enter spot: " << flush;
	cin >> Spot;

	cout << "Enter vol: " << flush;
	cin >> Vol;

	cout << "Enter r: " << flush;
	cin >> r;

	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	cout << "Enter number of moments: " << flush;
	cin >> NumberOfMoments;

	PayOffCall thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);
	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);


	// Park Miller random

	StatisticsFirstNMoments Rgatherer(NumberOfMoments);
	ConvergenceTable Rtable(Rgatherer);
	RandomParkMiller Rgenerator(1);
	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, Rtable, Rgenerator);

	vector<vector<double>> Rresults = Rtable.GetResultsSoFar();





	// Low Discrepency stuff
	StatisticsFirstNMoments LDgatherer(NumberOfMoments);
	ConvergenceTable LDtable(LDgatherer);
	LowDiscrepencyParkMiller LDgenerator(1);
	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, LDtable, LDgenerator);
	
	vector<vector<double>> LDresults = LDtable.GetResultsSoFar();



	// Anti thetic Park Miller
	StatisticsFirstNMoments ATRgatherer(NumberOfMoments);
	ConvergenceTable ATRtable(Rgatherer);
	RandomParkMiller ATRgenerator(1);
	AntiThetic ATRgenerator2(ATRgenerator);
	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, ATRtable, ATRgenerator2);

	vector<vector<double>> ATRresults = ATRtable.GetResultsSoFar();


	// Anti thetic Low Discrepency stuff
	StatisticsFirstNMoments ATLDgatherer(NumberOfMoments);
	ConvergenceTable ATLDtable(ATLDgatherer);
	LowDiscrepencyParkMiller ATLDgenerator(1);
	AntiThetic ATLDgenerator2(ATLDgenerator);
	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, ATLDtable, ATLDgenerator2);

	vector<vector<double>> ATLDresults = ATLDtable.GetResultsSoFar();





	
	cout << "The call price convergence tables for the first " << NumberOfMoments << " using Park Miller, low discrepency Park Miller, anti thetic Park Miller and anti thetic low discrepency Park Miller :" << endl;
	
	for (unsigned long i = 0; i < Rresults.size(); i++) {
		for (unsigned long j = 0; j < Rresults[i].size()-1; j++) {
			cout << Rresults[i][j]<<" " << LDresults[i][j] << " " << ATRresults[i][j] << " " << ATLDresults[i][j] << " " << flush;
		}
		cout << endl;
	}
	
}

