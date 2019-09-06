#include <iostream>
#include "ParkMiller.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"





using namespace std;



int main() {
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	double d;
	unsigned long NumberOfPaths;
	unsigned NumberOfDates;


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

	cout << "Enter d: " << flush;
	cin >> d;

	cout << "Enter number of dates: " << flush;
	cin >> NumberOfDates;

	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	PayOffCall thePayOff(Strike);
	MJArray times(NumberOfDates);

	for (unsigned long i = 0; i < NumberOfDates; i++) {
		times[i] = (i + 1.0) * Expiry / NumberOfDates;
	}

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	PathDependentAsian theOption(times, Expiry, thePayOff);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(NumberOfDates);

	AntiThetic GenTwo(generator);

	ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

	theEngine.DoSimulation(gathererTwo, NumberOfPaths);

	vector<vector<double>> results = gathererTwo.GetResultsSoFar();

	cout << "For the Asian call price the results are : " << endl;

	for (unsigned long i = 0; i < results.size(); i++) {
		for (unsigned long j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}

	double tmp;
	cin >> tmp;

	return 0;

}
