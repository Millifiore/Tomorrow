#include <string>
#include <iostream>
using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

void nextDate(Date);

int main() {
	Date tomorrow;
	int num;
	cout << "Enter the amount of dates for entry: ";
	cin >> num;
	for (int i = 0; i < num; i++){
		cout << "Enter information for date #" << i+1 << endl;
		cout << "Enter month: ";
		cin >> tomorrow.month;
		
		cout << "Enter day: ";
		cin >> tomorrow.day;
		
		cout << "Enter year: ";
		cin >> tomorrow.year;
		
		nextDate(tomorrow);
		cout << endl;
		}
	return 0;
}

void nextDate(Date tomorrow) {
	if((to_string(tomorrow.day).size()> 2) || (to_string(tomorrow.month).size()> 2) || (to_string(tomorrow.year).size() > 4)) {
		cout << "Please try to stay in bounds you rebel." << endl;
	}
	else if ((tomorrow.month == 2) && (tomorrow.day == 28)) {	//if statements for february
		if ((tomorrow.year % 4 == 0) || ((tomorrow.year % 400 == 0) && (tomorrow.year % 100 == 0))) {
			tomorrow.day = 29;
			tomorrow.month = 2;
		}
		else {
			tomorrow.month += 1;
			tomorrow.day = 1;
		}
		cout << "The next days date is: " << tomorrow.month << "-" << tomorrow.day << "-" << tomorrow.year << endl;
	}
	else if ((tomorrow.month == 12) && (tomorrow.day == 31)) {	//if statements for last day of the year
		tomorrow.month = 1;
		tomorrow.day = 1;
		tomorrow.year += 1;
		cout << "The next days date is: " << tomorrow.month << "-" << tomorrow.day << "-" << tomorrow.year << endl;
	}
	else if ((tomorrow.month == 4 || tomorrow.month == 6 || tomorrow.month == 9 || tomorrow.month == 11) &&( tomorrow.day == 30)) { //if statements for months that have 30 days
		tomorrow.month += 1;
		tomorrow.day = 1;
		cout << "The next days date is: " << tomorrow.month << "-" << tomorrow.day << "-" << tomorrow.year << endl;
	}
	else if ((tomorrow.month == 1 || tomorrow.month == 3 || tomorrow.month == 5 || tomorrow.month == 7 || tomorrow.month == 8 || tomorrow.month == 10) && (tomorrow.day == 31)) { //if statements for months that have 31 days
		tomorrow.month += 1;
		tomorrow.day = 1;
		cout << "The next days date is: " << tomorrow.month << "-" << tomorrow.day << "-" << tomorrow.year << endl;
	}
	else { //if statements for every other day
		tomorrow.day += 1;
		cout << "The next days date is: " << tomorrow.month << "-" << tomorrow.day << "-" << tomorrow.year << endl;
	}
}