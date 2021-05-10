#include <sstream>
#include <iostream>
<<<<<<< HEAD
using namespace std;
=======
#include "CheckInt.h"

using namespace std;

int checkInt() {
	int numberToCheck;
>>>>>>> 8aef9fe4c19c4356cd07bc0ccc26efafcd5242f8

	cin >> numberToCheck;
	while (cin.fail()) {
		cout << "This is not an int..." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> numberToCheck;
	}
	return numberToCheck;
}