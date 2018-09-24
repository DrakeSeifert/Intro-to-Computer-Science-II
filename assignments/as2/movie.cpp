/**************************************************************************************
 * Program: movie.cpp
 * Author: Drake Seifert
 * Date: 4/23/15
 * Description: Rent and store movies in a Netflix database
 * Input: Movie info and movie searches
 * Output: Store movie info and retrieve movie info
 * ************************************************************************************/

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

void movie::operator = (const movie &a) {
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

int movie::get_copies() {
	return copies;
}

void movie::get_data() {
	cin.ignore();
	cout << "Enter the name of your movie: ";
	getline(cin, name);
	cout << "Enter number of stars: ";
	cin >> stars;
	while(stars < 1 || cin.fail()) {
		cout << "Error! Please enter a valid input: ";
		cin.clear();
		cin.ignore();
		cin >> stars;
	}
	cout << "Enter number of cast members: ";
	cin >> num_cast;
	while(num_cast < 1 || cin.fail()) {
			cout << "Error! Please enter a valid input: ";
			cin.clear();
			cin.ignore();
			cin >> num_cast;
		}
	cast = new string [num_cast];
	cin.ignore();
	for (int i = 0; i < num_cast; i++) {
		cout << "Enter cast member " << i + 1 << ": ";
		getline(cin, cast[i]);
	}
	cout << "Enter the movie rating: ";
	cin >> rating;
	cout << "How many copies of this movie?: ";
	cin >> copies;
		while(copies < 1 || cin.fail()) {
			cout << "Error! Please enter a valid input: ";
			cin.clear();
			cin.ignore();
			cin >> copies;
		}
}
