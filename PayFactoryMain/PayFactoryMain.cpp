#include "PayOff3.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	double Strike;
	string name;

	cout << "Enter strike: " << flush;
	cin >> Strike;

	cout << "Enter pay-off name: " << flush;
	cin >> name;

	PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

	if (PayOffPtr != NULL) {
		double Spot;

		cout << "Enter spot: " << flush;
		cin >> Spot;

		cout << "\n" << PayOffPtr->operator()(Spot) << endl;
		delete PayOffPtr;
	}

	return 0;
}
