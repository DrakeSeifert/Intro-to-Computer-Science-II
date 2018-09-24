#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class floor {
	private:
		vector < vector <char> > v;
		int obj_row; //holds an object's current row position
		int obj_col; //holds an object's current col position
		int tot_rows;
		int tot_cols;
		string file_name;
		int move_roomba;
	public:
		void set_file_name(string x);
		string get_file_name();

		void set_tot_rows(); //find dimensions of room
		void set_tot_cols();
		int get_tot_rows();
		int get_tot_cols();

		void set_row(int); //set initial roomba position
		void set_col(int);

		int get_row(); //return roomba position
		int get_col();

		void move_roomba_up();    //changes int move_roomba so
		void move_roomba_down();  //change_floor knows what to change
		void move_roomba_right();
		void move_roomba_left();

		void place_roomba(); //puts roomba in first spot
		void change_floor(); //changes chars in vector to follow roomba path
		void print_floor(); //prints floor
		bool check_floor(); //checks if floor is clean

};

#endif
