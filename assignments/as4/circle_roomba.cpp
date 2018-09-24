#include <iostream>
#include "./circle_roomba.h"

circle_roomba::circle_roomba() {
	phase = 1;
	dx = dy = 0;
}

void circle_roomba::move(floor &f) {
	if (phase == 1) {
		f.move_roomba_up();
		if (f.get_row() == 0)
			phase = 2;
	}
	else if (phase == 2) {
		f.move_roomba_left();
		if (f.get_col() == 0)
			phase = 3;
	}
	else if (phase == 3) {
		f.move_roomba_down();
		dy++;
		//std::cout << "tot_rows - 1: " << f.get_tot_rows() - 1 << std::endl;
		//std::cout << "get_row: " << f.get_row() << std::endl;
		if (f.get_row() == f.get_tot_rows() - 1)
			phase = 4;
	}
	else if (phase == 4) {
		f.move_roomba_right();
		dx++;
		if (f.get_col() == f.get_tot_cols() - 1)
			phase = 5;
	}
	else if (phase == 5) {
		f.move_roomba_up();
		if (f.get_row() == 0)
			phase = 6;
	}
	else if (phase == 6) {
		f.move_roomba_left();
		if (f.get_col() == dx - (dx - 1))
			dx--;
			phase = 7;
	}
	else if (phase == 7) {
		f.move_roomba_down();
		if (f.get_row() == dy - 1)
			dy--;
			phase = 8;
	}
	else if (phase == 8) {
		f.move_roomba_right();
		if (f.get_col() == dx)
			phase = 9;
	}
	else if (phase == 9) {
		f.move_roomba_up();
		if (f.get_row() == dy)
			phase = 6;
	}
}
