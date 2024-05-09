#include <iostream>

using namespace std;

bool isLeapYear(int year);
/**
isLeapYear � determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/

int userInput;

int main() {
	do {
		cout << "Enter a year or Q to quit: ";
		cin >> userInput;

		try {
			if (isLeapYear(userInput)) {
				cout << userInput << " is a leap year." << endl;
			}
			else {
				cout << userInput << " is not a leap year." << endl;
			}
		}
		catch (...) {
			cout << "The number needs to be an integer => 1582" << endl;
		}
	} while (!cin.fail());
	

	return 0;
}

bool isLeapYear(int year) {
	
	if (year < 1582) {
		throw (1582);
	}
	else if (year % 100 == 0) {
		if (year % 400 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (year % 4 == 0) {
		return true;
	}
	return false;
}