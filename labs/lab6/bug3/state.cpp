/*
 * state.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <iostream>
#include <cstring>
#include "state.h"

using namespace std;

void state::set_name(const char *n) {
	delete [] name;
	name=new char[strlen(n)+1];
	strcpy(name, n);
}

void state::display_name() {
	cout << "State is: " << name << endl;
}

void state::set_pop(int n){
    this->pop=n;
}

void state::display_pop() {
	cout << "state, " << name << ", pop: " << pop << endl;
}

state::state() {
	pop=0;
	name=NULL;
}

state::~state() {

}

void state::operator = (const state &a) {
	if (name != NULL) {
		delete [] name;
		name = NULL;
	}
	pop = a.pop;
	name = new char[strlen(a.name) + 1];
	for (int i = 0; i < 5; i++)
		name[i] = a.name[i];	
}
