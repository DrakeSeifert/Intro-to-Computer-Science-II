/**************************************************************************************
 * Program: netflix.h
 * Author: Drake Seifert
 * Date: 4/23/15
 * Description: Rent and store movies in a Netflix database
 * Input: Movie info and movie searches
 * Output: Store movie info and retrieve movie info
 * ************************************************************************************/

#ifndef NETFLIX_H
#define NETFLIX_H

#include "./movie.h"
#include <string>
#include <cstring>
using std::string;

class netflix {
	public:
		netflix(); 		 	    //default constructor
		netflix(int);		  	    //constructor
		~netflix();		  	    //destructor
		netflix(const netflix &);  	    //copy constructor
		void operator = (const netflix &);

		string get_movie(int);    	    //accessors
		int get_num_movies();

		void change_num_movies(int);	    //mutator

	private:
		movie *m;
		int num_movies;
};

#endif
