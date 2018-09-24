#include "./line_roomba.h"
#include <iostream>

line_roomba::line_roomba() {
	phase = 1;
}

void line_roomba::move(floor &f) {
	if (phase == 1) {
		f.move_roomba_up(); //find top left corner
		if (f.get_row() == 0)
			phase = 2;
	}
	else if (phase == 2) {
		f.move_roomba_left();
		if (f.get_col() == 0)
			phase = 3;
	}
	else if (phase == 3) { //begin loop
		f.move_roomba_down();
		if (f.get_row() == f.get_tot_rows() - 1)
			phase = 4;
	}
	else if (phase == 4) {
		f.move_roomba_right();
		phase = 5;
	}
	else if (phase == 5) {
		f.move_roomba_up();
		if (f.get_row() == 0)
			phase = 6;
	}
	else if (phase == 6) { //loop back to phase 3
		f.move_roomba_right();
		phase = 3;
	}
}
