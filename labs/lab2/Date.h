#ifndef DATE_H
#define DATE_H

#include <string>
#include <cstring>

using std::string;

class Date {
	private:
		int month;
		int day;
		int year;
		string month_name[12];
		int month_day[12];

	public:
		Date(); //default constructor

		Date(int the_month, int the_day, int the_year); //constructor

		int get_month(); //accessors
		int get_day();
		int get_year();

		void print_date1(int, int, int); //mutators
		void print_date2(int, int, int);
		void print_date3(int, int, int);
};

#endif
