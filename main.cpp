#include <iostream>

using namespace std;

bool isLeapYear(int year);
/**
isLeapYear – determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/

int daysInMonth(int month, int year);
/**
daysInMonth – determines the number of days in a specified month
@param month the month; expected to be in the range [1..12]
@param year the year; expected to be >= 1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/

int year, month;

string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
	do {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;

		try {
			cout << months[month-1] << " " << year << " has " << daysInMonth(month, year) << " days." << endl;
		}
		catch (range_error& e) {
			cout << e.what() << endl;
		}
	} while (!cin.fail());
	

	return 0;
}

bool isLeapYear(int year) {
	
	if (year < 1582) {
		throw range_error("The number needs to be an integer => 1582");
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

int daysInMonth(int month, int year) {
	isLeapYear(year);
	switch (month) {

	case 1:
		return 31;
	case 2:
		if (isLeapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	default:
		throw range_error("Months are represented by 1-12");
	}
}