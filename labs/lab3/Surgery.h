#ifndef SURGERY_H
#define SURGERY_H

class Surgery {
	public:
		Surgery(); //default constructor
		~Surgery(); //deconstructor
		Surgery(const Surgery &other); //copy constructor
	private:
		int *surgery_type;
		int *surgery_cost;
		/*string leg();
		string foot();
		string arm();
		string hand();
		string face();*/
};

#endif
