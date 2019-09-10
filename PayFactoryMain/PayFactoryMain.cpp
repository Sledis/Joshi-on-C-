#include "PayOff3.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include <string>
#include <iostream>
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "ParkMiller.h"
#include "AntiThetic.h"
#include "Parameters.h"
#include "SimpleMC8.h"

using namespace std;

int main() {
	double Strike;
	string name;

	

	cout << "Enter pay-off name: " << flush;
	cin >> name;

	PayOff* PayOffPtr;
	double upperStrike;
	if (name == "doubleDigital") {

		cout << "Enter lower strike: " << flush;
		cin >> Strike;

		cout << "Enter upper strike: " << flush;
		cin >> upperStrike;
		PayOffPtr = PayOffFactory::Instance().CreatePayOff2(name, Strike, upperStrike);
	}
	else{
		cout << "Enter strike: " << flush;
		cin >> Strike;
		PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

		
	}
	
	double Spot;
	if (PayOffPtr != NULL) {
		

		cout << "Enter spot: " << flush;
		cin >> Spot;
		
	}

	double Expiry;
	cout << "Enter expiry: " << flush;
	cin >> Expiry;

	double r;
	cout << "Enter r: " << flush;
	cin >> r;

	double d;
	cout << "Enter d: " << flush;
	cin >> d;

	double vol;
	cout << "Enter vol: " << flush;
	cin >> vol;

	int NumberOfPaths;
	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	ParametersConstant rParam(r);
	ParametersConstant dParam(d);
	ParametersConstant volParam(vol);

	StatisticsMean theGatherer;
	ConvergenceTable Table(theGatherer);

	RandomParkMiller generator(1);
	AntiThetic gen(generator);

	VanillaOption theOption(*PayOffPtr, Expiry);

	SimpleMonteCarlo6(theOption,Spot,volParam,rParam,NumberOfPaths,Table,gen);

	


	vector<vector<double>> results = Table.GetResultsSoFar();

	cout << "The results are : " << endl;

	for (unsigned long i = 0; i < results.size(); i++) {
		for (unsigned long j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}


	delete PayOffPtr;
	return 0;
}
