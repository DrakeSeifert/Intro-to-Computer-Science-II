#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "./floor.h"
#include "./roomba.h"
#include "./line_roomba.h"
#include "./circle_roomba.h"
//#include "./random_roomba.h"
using namespace std;

template <typename T>
class room {
	private:
		floor f;
		T *obj;
	public:
		room() {
			obj = NULL;
		}

		~room() {
			delete [] obj;
			obj = NULL;
		}

		room (const room &a) {
			obj = a.obj;
		}

		void operator = (const room &a) {
			if (obj != NULL)
				delete [] obj;
			obj = a.obj;
		}

		void set_roomba(int a) {
			if (a == 1)
				obj = new line_roomba;
			else if (a == 2)
				obj = new circle_roomba;
			//else if (a == 3)
			//	obj = new random_roomba;
		}
		
		void clean_room() {
			if (obj != NULL)
				obj->clean_floor(f);
		}
};

#endif
