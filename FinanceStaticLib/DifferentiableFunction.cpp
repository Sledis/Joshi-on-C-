#include "pch.h"
#include "DifferentiableFunction.h"

double DifferentiableFunction::NumericDifferentiate(double x, double h) {
	return (this->value(x + h) - this->value(x)) / h;
}