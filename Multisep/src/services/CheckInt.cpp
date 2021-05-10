#include <sstream>
#include <iostream>

int CheckInt(int numberToCheck) {
	cin >> numberToCheck;
	while (cin.fail()) {
		cout << "This is not an int..." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> numberToCheck;
	}
	return numberToCheck;
}