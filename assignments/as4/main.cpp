/**************************************************************************
 * Program: main.cpp
 * Author: Drake Seifert
 * Date: 5/26/15
 * Description: Roomba simulation
 * Input: .txt file, row number, col number, battery life, view
 * Output: Roomba simulation
 * ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
//#include "./random_roomba.h"
#include "./circle_roomba.h"
#include "./line_roomba.h"
#include "./room.hpp"
#include "./floor.h"
#include "./roomba.h"

using namespace std;

/************************************************************
 * Function: set_info
 * Descr: check command line and assigns values
 * Para: floor, roomba, argc, argv
 * Pre cond: program running
 * post cond: sets values
 * **********************************************************/

void set_info(floor f, roomba &roomba1, int argc, char *argv[]) {
	if (strcmp(argv[1], "-f") || strcmp(argv[3], "-b") || strcmp(argv[5], "-r") || strcmp(argv[7], "-c") || strcmp(argv[9], "-v") || argc != 11) {
		cout << "Error! Invalid argument entered" << endl;
		exit(EXIT_FAILURE);
	}

	string x = argv[2];	
	f.set_file_name(x);

	int row = atoi(argv[6]) - 1;
	int col = atoi(argv[8]) - 1;
	f.set_row(row);
	f.set_col(col);

	int battery = atoi(argv[4]);
	int moves = atoi(argv[10]);
	roomba1.set_battery(battery);
	roomba1.set_moves(moves);
}

/************************************************************
 * Function: choose_roomba
 * Descr: choose roomba simulation
 * Para: room <roomba> &r
 * Pre cond: program running
 * post cond: sets roomba
 * **********************************************************/

void choose_roomba(room <roomba> &r) {
	int choice;
	cout << "Which Roomba? (1 - line, 2 - circle, 3 - random) ";
	cin >> choice;

	r.set_roomba(choice);
}

/************************************************************
 * Function: simulate_roomba
 * Descr: begins simulation
 * Para: roomba roomba1
 * Pre cond: program running
 * post cond: shows simulation
 * **********************************************************/

void simulate_roomba(roomba roomba1) {
	room <roomba> r;
	choose_roomba(r);

	r.clean_room();

	cout << "All done!" << endl;
}

int main(int argc, char *argv[]) {
	roomba roomba1;
	floor f;
	srand(time(NULL)); //for random roomba

	set_info(f, roomba1, argc, argv);
	simulate_roomba(roomba1);

	return 0;
}
