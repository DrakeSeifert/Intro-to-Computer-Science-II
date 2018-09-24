#ifndef RANDOM_ROOMBA_H
#define RANDOM_ROOMBA_H
#include <iostream>
#include "./roomba.h"
//using namespace std;

class random_roomba : public roomba {
	private:
		int phase;
	public:
		random_roomba();
		void move(floor f);
};

#endif

//random_roomba.cpp

random_roomba::random_roomba() {
	phase = 1;
}

void line_roomba::move(floor f) {
	phase = rand() % 4 + 1;
	if (phase == 1) {
		f.move_roomba_up();
	}
	else if (phase == 2) {
		f.move_roomba_down();
	}
	else if (phase == 3) {
		f.move_roomba_right();
	}
	else if (phase == 4) {
		f.move_roomba_left();
	}
}
