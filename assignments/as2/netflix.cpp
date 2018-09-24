/**************************************************************************************
 * Program: netflix.cpp
 * Author: Drake Seifert
 * Date: 4/23/15
 * Description: Rent and store movies in a Netflix database
 * Input: Movie info and movie searches
 * Output: Store movie info and retrieve movie info
 * ************************************************************************************/

#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <string>
using namespace std;

netflix::netflix() {
	m = NULL;
	num_movies = 0;
}

netflix::netflix(int a) {
	num_movies = a;
	m = new movie [a];
}

netflix::~netflix() {
	delete [] m;
	m = NULL;
	num_movies = 0;
}

netflix::netflix(const netflix &a) {
	num_movies = a.num_movies;
	m = new movie [num_movies];
	for (int i = 0; i < num_movies; i++) {
		m[i] = a.m[i];
	}
}

void netflix::operator = (const netflix &a) {
	if (m != NULL)
		delete [] m;
	num_movies = a.num_movies;
	m = new movie [num_movies];
	for (int i = 0; i < num_movies; i++) {
		m[i] = a.m[i];
	}
}

int netflix::get_num_movies() {
	return num_movies;
}

void netflix::change_num_movies(int a) {
	num_movies--;
}
