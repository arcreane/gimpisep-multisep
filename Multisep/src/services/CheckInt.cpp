#include <sstream>
#include <iostream>
#include "CheckInt.h"

using namespace std;

int checkInt() {
	int numberToCheck;

	cin >> numberToCheck;
	while (cin.fail()) {
		cout << "This is not an int..." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> numberToCheck;
	}
	return numberToCheck;
}