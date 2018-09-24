#include "./movie.h"
#include <iostream>
#include <string>
using namespace std;

movie::movie() {
	stars = num_cast = copies = 0;
	name = " ";
	cast = NULL;
	rating = " ";
}

movie::movie(int a) {
	num_cast = a;
	cast = new string [a];
}

movie::~movie() {
	delete [] cast;
	stars = num_cast = copies = 0;
	name = " ";
	cast = NULL;
	rating = " ";	
}

movie::movie(const movie &a) {
	name = a.name;
	stars = a.stars;
	num_cast = a.num_cast;
	cast = new string [num_cast];
	for(int i = 0; i < num_cast; i++){
		cast[i] = a.cast[i];
	}
	rating = a.rating;
	copies = a.copies;
}

void movie::operator=(const movie &a) {
	if (cast != NULL)
		delete [] cast;
	name = a.name;
	stars = a.stars;
	num_cast = a.num_cast;
	cast = new string [num_cast];
	for(int i = 0; i < num_cast; i++){
		cast[i] = a.cast[i];
	}
	rating = a.rating;
	copies = a.copies;
}

string movie::get_name() {
	return name;
}

int movie::get_stars() {
	return stars;
}

int movie::get_num_cast() {
	return num_cast;
}

string movie::get_cast(int i) {
	return cast[i];
}

string movie::get_rating() {
	return rating;
}
