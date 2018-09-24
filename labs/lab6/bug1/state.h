/*
 * state.h
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */

#ifndef STATE_H
#define STATE_H

class state {
private:
	char *name;
	int pop;
public:
	void set_name(const char *);
	void display_pop();
	void set_pop(int);
	state();
	virtual ~state();
};

#endif /* STATE_H_ */
