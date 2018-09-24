#include "./Date.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main() {

	int m, d, y;
	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	

	cout << "Enter the month (as a number 1-12): ";
	cin >> m;

	cout << "Enter the day: ";
	cin >> d;

	cout << "Enter the year: ";
	cin >> y;
	cout << endl;

	if (m < 1 || m > 12 || d < 1 || d > month_day[m - 1] || y < 1 ||y > 9999) { 
		
		Date p1; //Default Constructor

		d = p1.get_day(); //Accessors
		m = p1.get_month();
		y = p1.get_year();

		p1.print_date1(m, d, y); //Mutators
		p1.print_date2(m, d, y);
		p1.print_date3(m, d, y);
	}
	else {
		Date p1(m, d, y); //Constructor

		p1.print_date1(m, d, y); //Mutators
		p1.print_date2(m, d, y);
		p1.print_date3(m, d, y);
	}

	cout << endl;

	return 0;
}
