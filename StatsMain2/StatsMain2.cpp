#include <iostream>
#include "SimpleMC7.h"
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

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

	PayOffCall thePayOff(Strike);

	VanillaOption theOption(thePayOff, Expiry);

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo);

	vector<vector<double>> results = gathererTwo.GetResultsSoFar();

	cout << "For the call price the results are " << endl;

	for (unsigned long i = 0; i < results.size(); i++) {
		for (unsigned long j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << flush;
		}
		cout << endl;
	}
	

	double tmp;
	cin >> tmp;

	return 0;
}

