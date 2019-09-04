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

	StatisticsFirstNMoments gatherer(NumberOfMoments);
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1);

	AntiThetic GenTwo(generator);

	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo, GenTwo);
	
	vector<vector<double>> results = gathererTwo.GetResultsSoFar();
	
	cout << "For the call price the first " << NumberOfMoments << " using Anti-thetic sampling are :" << endl;
	
	for (unsigned long i = 0; i < results.size(); i++) {
		for (unsigned long j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " " << flush;
		}
		cout << endl;
	}
	StatisticsFirstNMoments gathererThree(NumberOfMoments);
	ConvergenceTable gathererFour(gathererThree);
	RandomParkMiller GenOne(1);

	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererFour, GenOne);

	vector<vector<double>> results2 = gathererFour.GetResultsSoFar();

	cout << "For the call price the first " << NumberOfMoments << " using non Anti-thetic sampling are :" << endl;

	for (unsigned long i = 0; i < results2.size(); i++) {
		for (unsigned long j = 0; j < results2[i].size(); j++) {
			cout << results2[i][j] << " " << flush;
		}
		cout << endl;
	}
}

