#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "PayOffForward.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	double d;
	unsigned long Steps;

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

	cout << "Enter Number of Steps: " << flush;
	cin >> Steps;

	PayOffCall thePayOff(Strike);

	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	TreeEuropean europeanOption(Expiry, thePayOff);
	TreeAmerican americanOption(Expiry, thePayOff);
	PayOffForward forwardPayOff(Strike);
	TreeEuropean forward(Expiry, forwardPayOff);

	SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);
	double euroPrice = theTree.GetThePrice(europeanOption);
	double americanPrice = theTree.GetThePrice(americanOption);
	double forwardPrice = theTree.GetThePrice(forward);

	cout << "The european price is " << euroPrice << ", the American price is " << americanPrice << " and the forward price is " << forwardPrice<< endl;

	SimpleBinomialTree theNewTree(Spot, rParam, dParam, Vol, Steps+1, Expiry);

	double euroNewPrice = theNewTree.GetThePrice(europeanOption);
	double americanNewPrice = theNewTree.GetThePrice(americanOption);
	double forwardNewPrice = theNewTree.GetThePrice(forward);

	cout << "The new euro price is " << euroNewPrice << " and the new american price is " << americanNewPrice << "." << endl;

	double averageEuro = 0.5 * (euroPrice + euroNewPrice);
	double averageAmer = 0.5 * (americanPrice + americanNewPrice);
	double averageFor = 0.5 * (forwardPrice + forwardNewPrice);

	cout << "The average prices for the euro, american and forward are: " << averageEuro << " "<< averageAmer << " " << averageFor << endl;
}
