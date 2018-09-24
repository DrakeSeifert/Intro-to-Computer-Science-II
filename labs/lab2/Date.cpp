#include "./Date.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

Date::Date() { // Default Constructor
	month = 1;
	day = 1;
	year = 2001;
}

Date::Date(int the_month, int the_day, int the_year) { //constructor
	month = the_month;
	day = the_day;
	year = the_year;
}

int Date::get_month() { //Accessors
	return month;
}

int Date::get_day() {
	return day;
}

int Date::get_year() {
	return year;
}

void Date::print_date1(int month, int day, int year) { //Mutators 4/8/15

	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	

	cout << month << "/" << day << "/" << year << endl;
}

void Date::print_date2(int month, int day, int year) { // April 8, 2015

	string month_name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	

	cout << month_name[month - 1] << " " << day << ", " << year << endl;
}

void Date::print_date3(int month, int day, int year) { // 8 April 2015 

	string month_name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	

	cout << day << " " << month_name[month - 1] << " " << year << endl;
}
