#ifndef PHARMECY_H
#define PHARMECY_H

class Pharmecy {
	public:
		Pharmecy(); //default constructor
		~Pharmecy(); //deconstructor
		Pharmecy(const Pharmecy &other); //copy constructor
	private:
		int *medicine_type;
		int *medicine_cost;
		/*string tyl();
		string advil();
		string ibu();
		string laughter();
		string oxy();*/
};

#endif
