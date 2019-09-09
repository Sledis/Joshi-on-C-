#include "pch.h"
#include "Linear.h"

Linear::Linear(double a_, double b_) :a(a_), b(b_) {};

double Linear::Value(double x) const {
	return a * x + b;
}

double Linear::Derivative(double x) const {
	return a;
}
