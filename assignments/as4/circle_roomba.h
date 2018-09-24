#ifndef CIRCLE_ROOMBA_H
#define CIRCLE_ROOMBA_H
#include <iostream>
#include "./roomba.h"

class circle_roomba : public roomba {
	private:
		int phase, dx, dy;
	public:
		circle_roomba();
		void move(floor &f);
};

#endif
