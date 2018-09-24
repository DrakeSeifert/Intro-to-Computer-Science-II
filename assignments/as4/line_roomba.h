#ifndef LINE_ROOMBA_H
#define LINE_ROOMBA_H
#include <iostream>
#include "./roomba.h"

class line_roomba : public roomba {
	private:
		int phase;
	public:
		line_roomba();
		void move(floor &f);
};

#endif
