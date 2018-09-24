/**************************************************************************************
 * Program: as2.cpp
 * Author: Drake Seifert
 * Date: 4/23/15
 * Description: Rent and store movies in a Netflix database
 * Input: Movie info and movie searches
 * Output: Store movie info and retrieve movie info
 * ************************************************************************************/

#include "./movie.h"
#include "./netflix.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

/**************************************************************************************
 * Funtion: num_of_movies
 * Description: finds how many movies there are
 * Parameters: none
 * Pre-Conditions: user is entering a movie
 * Post-Conditions: returns amount of movies
 * ************************************************************************************/

int num_of_movies() {
	
	ifstream input;
	input.open("netflix.dat");
	
	if (input.fail()) {
		cout << "The file failed to open :(" << endl;
		exit(EXIT_FAILURE);
	}

	string x;
	int count = 0;
	while (!input.eof()) {
		getline(input, x);
		count++;
	}
	input.close();
	return count;
}

/**************************************************************************************
 * Funtion: print_data
 * Description: prints movie info to netflix.dat
 * Parameters: movie info
 * Pre-Conditions: user entered movie info
 * Post-Conditions: prints movie info to netflix.dat
 * ************************************************************************************/

void print_data(movie info) {

	fstream output;
	output.open("netflix.dat", ios::out | ios::app);
	
	output << num_of_movies() << "|";
	output << info.get_name() << "|";
	output << info.get_stars() << "|";
	output << info.get_num_cast() << "|";
	for (int i = 0; i < info.get_num_cast(); i++) {
		output << info.get_cast(i) << "|";
	}
	output << info.get_rating() << "|";
	output << info.get_copies() << "|";
	output << endl;
	
	output.close();

	cout << endl << "Added to the database!" << endl << endl;
}

/**************************************************************************************
 * Funtion: search_title
 * Description: looks for title user enters
 * Parameters: none
 * Pre-Conditions: user selected search option
 * Post-Conditions: returns title
 * ************************************************************************************/

string search_title() {
	string y;
	cout << "What is the title?: ";
	cin >> y;

	ifstream input;
	input.open("netflix.dat");
	
	if (input.fail()) {
		cout << "The file failed to open :(" << endl;
		exit(EXIT_FAILURE);
	}
	
	char z[81];
	while (!input.eof()) {
		input.getline(z, 81, '|');
		if (z == y) {
			getline(input, y);
			return y;
		}
	}
	cout << "Please enter a valid title" << endl;
	search_title();
}

/**************************************************************************************
 * Funtion: search_stars
 * Description: looks for stars user enters
 * Parameters: none
 * Pre-Conditions: user selected search option
 * Post-Conditions: returns stars
 * ************************************************************************************/

int search_stars() {
	int y;
	cout << "How many stars?: ";
	cin >> y;

	ifstream input;
	input.open("netflix.dat");
	
	if (input.fail()) {
		cout << "The file failed to open :(" << endl;
		exit(EXIT_FAILURE);
	}
	
	char z[81];
	int a;
	while (!input.eof()) {
		input.getline(z, 81, '|');
		a = atoi(z);
		if (a == y) {
			return y;
		}
	}
	cout << "Please enter a valid amount of stars" << endl;
	search_stars();
}

/**************************************************************************************
 * Funtion: search_cast_member
 * Description: looks for cast member user enters
 * Parameters: none
 * Pre-Conditions: user selected search option
 * Post-Conditions: returns cast member
 * ************************************************************************************/

string search_cast_member() {
	string y;
	cout << "Which cast member?: ";
	cin >> y;

	ifstream input;
	input.open("netflix.dat");
	
	if (input.fail()) {
		cout << "The file failed to open :(" << endl;
		exit(EXIT_FAILURE);
	}
	
	char z[81];
	while (!input.eof()) {
		input.getline(z, 81, '|');
		if (z == y) {
			getline(input, y);
			return y;
		}
	}
	cout << "Please enter a valid cast member" << endl;
	search_cast_member();
}
	
/**************************************************************************************
 * Funtion: search_rating
 * Description: looks for rating user enters
 * Parameters: none
 * Pre-Conditions: user selected search option
 * Post-Conditions: returns rating
 * ************************************************************************************/

string search_rating() {
	string y;
	cout << "What is the rating?: ";
	cin >> y;

	ifstream input;
	input.open("netflix.dat");
	
	if (input.fail()) {
		cout << "The file failed to open :(" << endl;
		exit(EXIT_FAILURE);
	}
	
	char z[81];
	while (!input.eof()) {
		input.getline(z, 81, '|');
		if (z == y) {
			getline(input, y);
			return y;
		}
	}
	cout << "Please enter a valid rating" << endl;
	search_rating();
}

/**************************************************************************************
 * Funtion: search_movie
 * Description: prompts user what they want to search for
 * Parameters: none
 * Pre-Conditions: user selected search option
 * Post-Conditions: finds movie user searches
 * ************************************************************************************/

void search_movie(netflix m) {
	int x;
	cout << "Do you want to find movies based on:" << endl;
	cout << "(1 - title, 2 - stars, 3 - cast member, 4 - rating): ";
	cin >> x;

	while(x < 1 || x > 4 || cin.fail()) {
		cout << "Error! Please enter a valid input: ";
		cin.clear();
		cin.ignore();
		cin >> x;
	}
	
	if      (x == 1) {
		string a;
		a = search_title();
		cout << "your movie was found! movie info: " << a << endl << "#|Title|Stars|Cast|Members|Rating|Copies|" << endl << endl;
	}
	else if (x == 2) {
		int a;
		a = search_stars();
		cout << "your movie was found! movie info: " << a << endl << "#|Title|Stars|Cast|Members|Rating|Copies|" << endl << endl;
	}
	else if (x == 3) {
		string a;
		a = search_cast_member();
		cout << "your movie was found! movie info: " << a << endl << "#|Title|Stars|Cast|Members|Rating|Copies|" << endl << endl;
	}
	else if (x == 4) {
		string a;
		a = search_rating();
		cout << "your movie was found! movie info: " << a << endl << "#|Title|Stars|Cast|Members|Rating|Copies|" << endl << endl;
	}
}

/**************************************************************************************
 * Funtion: ask_user
 * Description: asks user if they want to enter a movie, search, or exit
 * Parameters: movie info
 * Pre-Conditions: none
 * Post-Conditions: allows user to manipulate netflix.dat
 * ************************************************************************************/

void ask_user(movie info, netflix m) {
	int x = 1;
	while(x) {
		cout << "Do you want to enter a movie to the database or find a movie to rent?" << endl << "(1 - enter, 2 - find, 0 - exit): ";
		cin >> x;

		while(x < 0 || x > 2 || cin.fail()) {
			cout << "Error! Please enter a valid input: ";
			cin.clear();
			cin.ignore();
			cin >> x;
		}

		if (x == 1) {
			int y;
			cout << "How many movies do you want to enter to the database?: ";
			cin >> y;
			while(y < 1 || cin.fail()) {
				cout << "Error! Please enter a valid input: ";
				cin.clear();
				cin.ignore();
				cin >> y;
			}
			for (int i = 0; i < y; i++) {
				info.get_data();
				print_data(info);				
			}
		}
		else if (x == 2) {
			search_movie(m);
		}
		else if(x == 0) {
			exit(EXIT_FAILURE);
		}
	}

}

int main() {
	class movie info;
	class netflix m;
	
	ask_user(info, m);

	return 0;
}
