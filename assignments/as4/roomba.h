#ifndef ROOMBA_H
#define ROOMBA_H
#include <iostream>
#include "./floor.h"


using namespace std;

class roomba {
	protected:
		int battery; //how many moves it can make
		int total_moves; //total moves needed to clean
	public:
		roomba();
		void set_battery(int);
		void set_moves(int);

		void dec_battery();
		void add_move();

		int get_battery();
		int get_moves();

		void virtual move(floor &f);
		void clean_floor(floor f);
};

#endif
