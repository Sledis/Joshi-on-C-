#include "pch.h"
#include "TreeProduct.h"

TreeProduct::TreeProduct(double FinalTime_):FinalTime(FinalTime_){}

double TreeProduct::GetFinalTime() const {
	return FinalTime;
}
