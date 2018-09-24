#include "./floor.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

void floor::set_file_name(string x) {
        //file_name = x;
        file_name = "floorplan.txt";
}

string floor::get_file_name() {
        return file_name;
}

void floor::set_tot_rows() {
        char ch;
        int count = 0;

        ifstream my_file;
        //my_file.open(file_name.data());
        my_file.open("floorplan.txt");

        if (!my_file) {
                cout << "The file failed to open :(" << endl;
                exit(EXIT_FAILURE);
        }

        my_file.get(ch);
        while(!my_file.eof()) {
                if (ch == '\n')
                        count++;
                my_file.get(ch);
        }
        tot_rows = count;

        my_file.close();
}

void floor::set_tot_cols() {
        vector <char> temp;
        char ch;

        ifstream my_file;
        //my_file.open(file_name.data());
        my_file.open("floorplan.txt");

        if (!my_file) {
                cout << "The file failed to open :(" << endl;
                exit(EXIT_FAILURE);
        }

        my_file.get(ch);
        while (!my_file.eof()) {
                if (ch == '\n') {
                        v.push_back(temp);
                        if (v.size() == tot_rows) {
                                tot_cols = temp.size();
                                my_file.close();
                                return;
                        }
                        temp.clear();
                }
                if (ch != ' ' && ch != '\n') {
                        temp.push_back(ch);
                }
                my_file.get(ch);
        }

        my_file.close();
}

int floor::get_tot_rows() {
        return tot_rows;
}

int floor::get_tot_cols() {
        return tot_cols;
}

void floor::set_row(int a) {
        obj_row = a;
}

void floor::set_col(int a) {
        obj_col = a;
}

int floor::get_row() {
        return obj_row;
}

int floor::get_col() {
        return obj_col;
}

void floor::move_roomba_up() {
	obj_row--;
	move_roomba = 1;
}

void floor::move_roomba_down() {
	obj_row++;
	move_roomba = 2;
}

void floor::move_roomba_right() {
	obj_col++;
	move_roomba = 3;
}

void floor::move_roomba_left() {
	obj_col--;
	move_roomba = 4;
}

void floor::place_roomba() {
		obj_row = 2;
		obj_col = 2;
		v[obj_row][obj_col] = 'r';
	/*if (obj_row > 0 && obj_row <= tot_rows && obj_col > 0 && obj_col <= tot_cols)
		v[obj_row][obj_col] = 'r';
	else {
		cout << "Invalid roomba placement" << endl;
		exit(EXIT_FAILURE);
	}*/
}

void floor::change_floor() {
	for (int i = 0; i < tot_rows; i++) {
		for (int j = 0; j < tot_cols; j++) {
			v[obj_row][obj_col] = 'r';
			if (move_roomba == 1) { //move up
				v[obj_row + 1][obj_col] = 'c';
			}
			else if (move_roomba == 2) { //move down
				v[obj_row - 1][obj_col] = 'c';
			}
			else if (move_roomba == 3) { //move right
				v[obj_row][obj_col - 1] = 'c';
			}
			else if (move_roomba == 4) { //move left
				v[obj_row][obj_col + 1] = 'c';
			}
		}
	}
}

void floor::print_floor() {
	for (int i = 0; i < tot_rows; i++) {
		for (int j = 0; j < tot_cols; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

bool floor::check_floor() {
	int count = 0;
	for (int i = 0; i < tot_rows; i++) {
		for (int j = 0; j < tot_cols; j++) {
			if (v[i][j] == 'c' || v[i][j] == 'r')
				count++;
		}
	}
	if (count == (tot_rows * tot_cols))
		return false; //to exit the while loop in clean_floor
	else
		return true;
}
