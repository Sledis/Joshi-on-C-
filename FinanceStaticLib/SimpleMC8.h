#pragma once
#include "Vanilla3.h"
#include "Parameters.h"
#include "Random2.h"
#include "MCStatistics.h"

int SimpleMonteCarlo6(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, double runTime, StatisticsMC& gatherer, RandomBase& generator);