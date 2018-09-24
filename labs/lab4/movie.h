#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <cstring>

class movie {
	public:
		movie();
		movie(int);
		~movie();
		movie(const movie &);
		void operator=(const movie &);

		std::string get_name();
		int get_stars();
		int get_num_cast();
		std::string get_cast(int);
		std::string get_rating();
		int get_copies();

		void change_copies(int);

		void store_data();
	private:
		std::string name;
		int stars;
		int num_cast;
		std::string *cast;
		std::string rating;
		int copies;
};

#endif
