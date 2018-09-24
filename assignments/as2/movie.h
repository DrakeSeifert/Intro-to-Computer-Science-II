/**************************************************************************************
 * Program: movie.h
 * Author: Drake Seifert
 * Date: 4/23/15
 * Description: Rent and store movies in a Netflix database
 * Input: Movie info and movie searches
 * Output: Store movie info and retrieve movie info
 * ************************************************************************************/

#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <cstring>
using std::string;

class movie {
	public:
		movie(); 			  //default constructor
		~movie();			  //destructor
		movie(const movie &);  		  //copy constructor
		void operator = (const movie &);

		string get_name();		  //accessors
		int get_stars();
		int get_num_cast();
		string get_cast(int);
		string get_rating();
		int get_copies();
		int get_num_movie();

		void change_copies(int);	  //mutators
		void get_data();
		
	private:
		string name;
		int stars;
		int num_cast;
		string *cast;
		string rating;
		int copies;
};

#endif
