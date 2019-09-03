#include "pch.h"
#include <iostream>
#include "MCStatistics.h"

using namespace std;

StatisticsMean::StatisticsMean() :RunningSum(0.0), PathsDone(0) {

}
void StatisticsMean::DumpOneResult(double result) {
	PathsDone++;
	RunningSum += result;
}

vector<vector<double>> StatisticsMean::GetResultsSoFar() const {
	vector<vector<double>> Results(1);
	Results[0].resize(1);
	Results[0][0] = RunningSum / PathsDone;

	return Results;
}

StatisticsMC* StatisticsMean::clone() const {
	return new StatisticsMean(*this);
}

StatisticsFirstNMoments::StatisticsFirstNMoments(int Length):Length(Length)  {
	
	for (int i = 0; i < Length; i++) {
		RunningSums.push_back(0);
	}
	PathsDone = 0;
	
}

void StatisticsFirstNMoments::DumpOneResult(double result) {
	PathsDone++;
	for (int i = 0; i < Length; i++) {
		RunningSums[i] += pow(result, i + 1);
	}
}

vector<vector<double>> StatisticsFirstNMoments::GetResultsSoFar() const {
	vector<vector<double>> Results(1);
	Results[0].resize(Length);
	for (int i = 0; i < Length; i++) {
		Results[0][i] = RunningSums[i] / PathsDone;
	}
	
	return Results;
}

StatisticsMC* StatisticsFirstNMoments::clone() const {
	return new StatisticsFirstNMoments(*this);
}