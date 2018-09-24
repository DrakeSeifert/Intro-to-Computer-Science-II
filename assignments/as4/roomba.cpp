#include "./roomba.h"
#include <iostream>
using namespace std;

roomba::roomba() {
        battery = 0;
        total_moves = 0;
}

void roomba::set_battery(int a) {
        battery = a;
}

void roomba::set_moves(int a) {
        total_moves = a;
}

void roomba::dec_battery() {
        battery--;
}

void roomba::add_move() {
        total_moves++;
}

int roomba::get_battery() {
        return battery;
}

int roomba::get_moves() {
        return total_moves;
}

void roomba::move(floor &f) {}

void roomba::clean_floor(floor f) {
	f.set_tot_rows();
	f.set_tot_cols();
	battery = 100;
	f.place_roomba();
	f.print_floor();
	std::cout << std::endl;
	while (battery != 0 && f.check_floor()) {
		move(f); //in roomba functions
		dec_battery();
		add_move();
		f.change_floor();
		f.print_floor();
		std::cout << std::endl << std::endl;
	}
	std::cout << "Number of moves: " << total_moves << std::endl;
}
