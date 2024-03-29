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
#include "FunctionFactory.h"
#include "SquaredRandonAlgo.h"
#include "LowDiscrepencyPAdic.h"

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

	string rFunction;
	cout << "Enter name of r function: " << flush;
	cin >> rFunction;

	int NumberOfFeatures;
	vector<double> Coefficients;
	cout << "Enter number of defining features: " << flush;
	cin >> NumberOfFeatures;

	Coefficients.resize(NumberOfFeatures);
	for (int i = 0; i < NumberOfFeatures; i++) {
		double entry;
		cout << "Enter the " << NumberOfFeatures-i << "-th feature: " << flush;
		cin >> entry;
		Coefficients[i] = entry;
	}

	ParametersInner* rParam = FunctionFactory::Instance().CreateParameters(rFunction, Coefficients);

	double d;
	cout << "Enter d: " << flush;
	cin >> d;

	double vol;
	cout << "Enter vol: " << flush;
	cin >> vol;

	unsigned long NumberOfPaths;
	cout << "Enter number of paths: " << flush;
	cin >> NumberOfPaths;

	if (NumberOfPaths < 1) {
		NumberOfPaths = ULLONG_MAX;
	}

	double runTime;
	cout << "Enter max run time in seconds: " << flush;
	cin >> runTime;

	
	ParametersConstant dParam(d);
	ParametersConstant volParam(vol);

	StatisticsMean theGatherer;
	ConvergenceTable Table(theGatherer);

	RandomParkMiller generator(1);
	AntiThetic gen(generator);

	VanillaOption theOption(*PayOffPtr, Expiry);

	SimpleMonteCarlo6(theOption,Spot,volParam,*rParam,NumberOfPaths,runTime,Table,gen);

	


	vector<vector<double>> results = Table.GetResultsSoFar();

	cout << "The results are : " << endl;

	for (unsigned long i = 0; i < results.size(); i++) {
		for (unsigned long j = 0; j < results[i].size(); j++) {
			cout << results[i][j] << " ";
		}
		cout << endl;
	}


	

	RandomLowDiscrepencyPAdic pAdicGenerator(1);
	

	

	StatisticsMean theGatherer2;
	ConvergenceTable Table2(theGatherer2);

	SimpleMonteCarlo6(theOption, Spot, volParam, *rParam, NumberOfPaths, runTime, Table2, pAdicGenerator);




	vector<vector<double>> results2 = Table2.GetResultsSoFar();

	cout << "The results are : " << endl;

	for (unsigned long i = 0; i < results2.size(); i++) {
		for (unsigned long j = 0; j < results2[i].size(); j++) {
			cout << results2[i][j] << " ";
		}
		cout << endl;
	}


	delete PayOffPtr;
	return 0;
}
